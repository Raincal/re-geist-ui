open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Capacity", () => {
  test("should render value correctly", () => {
    let wrapper = render(<Capacity value=50 />);
    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should render title correctly", () => {
    <Capacity value=50 />
    |> render
    |> container
    |> querySelector(".capacity")
    |> getAttribute("title")
    |> expect
    |> toEqual("50%")
  });

  test("should render different widths based on limit-value", () => {
    <div>
      <Capacity value=20 />
      <Capacity value=20 limit=50 />
      <Capacity value=20 limit=30 />
    </div>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should override background color", () => {
    <Capacity value=50 color="white" />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });
});
