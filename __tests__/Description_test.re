open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Description", () => {
  test("should render correctly", () => {
    let wrapper = render(<Description title={`String("title")} />);

    wrapper |> container |> expect |> toMatchSnapshot;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should render react-node on title", () => {
    let wrapper =
      render(<Description title={`Element(<p> "p"->str </p>)} />);
    wrapper |> container |> findBySelector("p") |> expect |> toBe(1);

    wrapper
    |> rerender(<Description title={`Element(<h1> "h1"->str </h1>)} />);
    wrapper |> container |> findBySelector("h1") |> expect |> toBe(1);
  });

  test("should render react-node on content", () => {
    let wrapper =
      render(<Description content={`Element(<p> "p"->str </p>)} />);

    wrapper |> container |> findBySelector("p") |> expect |> toBe(1);

    wrapper
    |> rerender(<Description content={`Element(<h1> "h1"->str </h1>)} />);

    wrapper |> container |> findBySelector("h1") |> expect |> toBe(1);
  });
});