open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Col", () => {
  test("should render correctly", () => {
    let wrapper = render(<Col> "col"->str </Col>);

    wrapper |> container |> expect |> toMatchSnapshot |> ignore;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should work with span and offset", () => {
    let wrapper =
      render(
        <div>
          <Col span=2> "col"->str </Col>
          <Col span=2 offset=2> "col"->str </Col>
        </div>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should render correctly when nested", () => {
    let wrapper = render(<Col> <Col> <Col /> "col"->str </Col> </Col>);

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should render different components", () => {
    let wrapper = render(<Col component="p" />);
    wrapper
    |> container
    |> findBySelector("p")
    |> expect
    |> toBe(1)
    |> ignore;

    wrapper |> rerender(<Col component="details" />);
    wrapper
    |> container
    |> findBySelector("details")
    |> expect
    |> toBe(1)
    |> ignore;

    wrapper |> rerender(<Col component="h1" />);
    wrapper |> container |> findBySelector("h1") |> expect |> toBe(1);
  });
});
