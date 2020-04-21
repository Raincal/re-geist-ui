open Jest;
open JestDom;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Dot", () => {
  test("should render correctly", () => {
    let wrapper = render(<Dot />);

    wrapper |> container |> expect |> toMatchSnapshot;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should supports types", () => {
    let wrapper =
      render(
        <>
          <Dot _type=`success />
          <Dot _type=`secondary />
          <Dot _type=`warning />
          <Dot _type=`error />
        </>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should be render text", () => {
    let wrapper = render(<Dot> "test"->str </Dot>);

    wrapper |> container |> expect |> toHaveTextContent(`Str("test"));
  });
});