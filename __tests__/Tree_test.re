open Jest;
open JestDom;
open Expect;
open ReactTestingLibrary;
open Utils;

let mockFiles: array(Tree.FileTreeValue.t) =
  Tree.(
    [|
      FileTreeValue.make(~_type=`file, ~name="cs.js", ~extra="extra", ()),
      FileTreeValue.make(
        ~_type=`directory,
        ~name="bin",
        ~extra="extra",
        ~files=[|FileTreeValue.make(~_type=`file, ~name="cs.js", ())|],
        (),
      ),
      FileTreeValue.make(
        ~_type=`directory,
        ~name="docs",
        ~files=[|
          FileTreeValue.make(~_type=`file, ~name="controllers.md", ()),
          FileTreeValue.make(~_type=`file, ~name="es6.md", ()),
          FileTreeValue.make(~_type=`file, ~name="production.md", ()),
          FileTreeValue.make(~_type=`file, ~name="views.md", ()),
        |],
        (),
      ),
      FileTreeValue.make(~_type=`file, ~name="views.md", ()),
    |]
  );

describe("Tree", () => {
  test("should mount correctly", () => {
    let wrapper =
      render(
        <Tree>
          <Tree.File name="package.json" />
          <Tree.Folder name="components">
            <Tree.File name="layout.js" />
            <Tree.File name="header.js" />
          </Tree.Folder>
          <Tree.File name="readme.md" />
        </Tree>,
      );

    <Tree.File name="package.json" />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot;

    <Tree.Folder name="components" />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot;

    wrapper |> container |> expect |> toMatchSnapshot;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should show extra messages", () => {
    let wrapper = render(<Tree value=mockFiles />);

    wrapper
    |> container
    |> querySelector(".name")
    |> expect
    |> toHaveTextContent(`Str("extra"));

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should trigger event when file clicked", () => {
    let spy = JestJs.inferred_fn();
    let fn = spy |> MockJs.fn;
    let clickHandler = _ => fn(. "clicked!") |> ignore;

    let wrapper = render(<Tree value=mockFiles onClick=clickHandler />);

    wrapper |> container |> querySelector(".file") |> FireEvent.click;

    expect(spy |> MockJs.calls) |> toEqual([|"clicked!"|]);
  });

  test("should be work when value is empty", () => {
    let wrapper = render(<Tree value=[||] />);

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });
});