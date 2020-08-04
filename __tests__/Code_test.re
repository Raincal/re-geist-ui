open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Code", () => {
  test("should render correctly", () => {
    <Button /> |> render |> container |> expect |> toMatchSnapshot
  });

  test("should render correctly", () => {
    let wrapper = render(<Code> "code"->str </Code>);

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should support block mode", () => {
    let wrapper = render(<Code block=true> "code"->str </Code>);

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should repspond to changed by width", () => {
    let wrapper = render(<Code block=true width="50%"> "code"->str </Code>);

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should render pre element only in block mode", () => {
    let wrapper = render(<Code> "code"->str </Code>);

    wrapper
    |> container
    |> findBySelector("pre")
    |> expect
    |> toBe(0)
    |> ignore;

    wrapper |> rerender(<Code block=true> "code"->str </Code>);

    wrapper |> container |> findBySelector("pre") |> expect |> toBe(1);
  });
});
