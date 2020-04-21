open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Tag", () => {
  test("should render correctly", () => {
    let wrapper = render(<Tag> "tag"->str </Tag>);

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should work with types", () => {
    let wrapper =
      render(
        <>
          <Tag _type=`success> "success"->str </Tag>
          <Tag _type=`secondary> "secondary"->str </Tag>
          <Tag _type=`error> "error"->str </Tag>
          <Tag _type=`dark> "dark"->str </Tag>
        </>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should work with invert", () => {
    let wrapper =
      render(<Tag _type=`success invert=true> "success"->str </Tag>);

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should work when child is null", () => {
    let wrapper = render(<Tag />);

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });
});