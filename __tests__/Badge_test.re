open Jest;
open JestDom;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Badge", () => {
  test("should supoort text", () => {
    let badge = <Badge> "count"->str </Badge> |> render;

    badge |> container |> expect |> toMatchSnapshot;

    (() => badge |> unmount()) |> expect |> not |> toThrow;
  });

  test("should render different sizes", () => {
    <>
      <Badge size=`mini> "mini"->str </Badge>
      <Badge size=`small> "small"->str </Badge>
      <Badge size=`medium> "medium"->str </Badge>
      <Badge size=`large> "large"->str </Badge>
    </>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should re-render when size changed", () => {
    let badge = <Badge> "size"->str </Badge> |> render;

    badge |> rerender(<Badge size=`small> "size"->str </Badge>);
    badge |> container |> expect |> toMatchSnapshot;

    badge |> rerender(<Badge size=`mini> "size"->str </Badge>);
    badge |> container |> expect |> toMatchSnapshot;
  });

  test("should render different types", () => {
    <>
      <Badge _type=`success> "badge"->str </Badge>
      <Badge _type=`secondary> "badge"->str </Badge>
      <Badge _type=`warning> "badge"->str </Badge>
      <Badge _type=`error> "badge"->str </Badge>
    </>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should overwrite style by inline-style", () => {
    let badge =
      <Badge
        style={ReactDOMRe.Style.make(~background="white", ())} _type=`success>
        "badge"->str
      </Badge>
      |> render;

    badge
    |> container
    |> querySelector("span")
    |> expect
    |> toHaveStyle("background: white");
  });
});