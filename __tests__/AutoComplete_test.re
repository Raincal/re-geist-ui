open Jest;
open JestDom;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("AutoComplete", () => {
  test("should render correctly", () => {
    let wrapper = render(<AutoComplete />);

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should support sizes and status", () => {
    let wrapper =
      render(
        <>
          <AutoComplete status=`secondary />
          <AutoComplete status=`success />
          <AutoComplete size=`mini />
          <AutoComplete size=`large />
        </>,
      );

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should set input value from initial value", () => {
    let wrapper =
      renderWithTestId(
        ~testId="input",
        <AutoComplete initialValue="value" />,
      );

    wrapper
    |> container
    |> queryByTestID("input")
    |> expect
    |> toHaveValue(`Str("value"));

    let wrapper =
      renderWithTestId(~testId="input", <AutoComplete value="value2" />);

    wrapper
    |> container
    |> queryByTestID("input")
    |> expect
    |> toHaveValue(`Str("value2"));
  });

  test("should render clear icon", () => {
    let wrapper =
      renderWithTestId(
        ~testId="input",
        <AutoComplete initialValue="value" clearable=true />,
      );

    wrapper |> container |> querySelector("svg") |> FireEvent.click;

    wrapper
    |> container
    |> queryByTestID("input")
    |> expect
    |> toHaveValue(`Str(""));
  });
});