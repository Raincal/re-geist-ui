open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Divider", () => {
  test("should render correctly", () => {
    let wrapper = render(<Divider />);

    wrapper |> container |> expect |> toMatchSnapshot |> ignore;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should work with x and y", () => {
    let wrapper = render(<> <Divider x=3.0 /> <Divider y=3.0 /> </>);

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should work with type", () => {
    let wrapper =
      render(
        <>
          <Divider _type=`secondary />
          <Divider _type=`warning />
          <Divider _type=`dark />
        </>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should work with align and volume", () => {
    let wrapper =
      render(
        <>
          <Divider align=`start> "start"->str </Divider>
          <Divider align=`left> "left"->str </Divider>
          <Divider align=`_end> "end"->str </Divider>
          <Divider align=`start volume=2.0> "start"->str </Divider>
        </>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });
});
