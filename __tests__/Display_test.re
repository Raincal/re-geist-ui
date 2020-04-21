open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Display", () => {
  test("should render correctly", () => {
    let wrapper =
      render(
        <Display caption={`String("caption")}> "display"->str </Display>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should support react-node", () => {
    let wrapper =
      render(
        <Display caption={`Element(<h1> "h1"->str </h1>)}>
          "display"->str
        </Display>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;

    wrapper |> container |> findBySelector("h1") |> expect |> toBe(1);
  });

  test("should work with shadow and width", () => {
    let wrapper =
      render(
        <>
          <Display caption={`Element(<h1> "h1"->str </h1>)} shadow=true>
            "display"->str
          </Display>
          <Display caption={`Element(<h1> "h1"->str </h1>)} width="50px">
            "display"->str
          </Display>
        </>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });
});