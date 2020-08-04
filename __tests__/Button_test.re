open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Button", () => {
  test("should render correctly", () => {
    <Button> "Button"->str </Button>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should support all types", () => {
    <div>
      <Button _type=`secondary />
      <Button _type=`success />
      <Button _type=`warning />
      <Button _type=`error />
      <Button _type=`abort />
    </div>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should support all sizes", () => {
    <div>
      <Button size=`mini />
      <Button size=`small />
      <Button size=`medium />
      <Button size=`large />
    </div>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should render different text", () => {
    let wrapper = <Button> "button"->str </Button> |> render;

    wrapper
    |> container
    |> text
    |> expect
    |> toContainString("button")
    |> ignore;

    wrapper |> rerender(<Button> <span> "按钮"->str </span> </Button>);

    wrapper |> container |> text |> expect |> toContainString("按钮");
  });

  test("should render empty button correctly", () => {
    <Button /> |> expect |> toMatchSnapshot
  });

  test("should trigger callback function", () => {
    module WrapperButton = {
      [@react.component]
      let make = () => {
        let (state, setState) = React.useState(() => "state1");
        <Button onClick={_ => setState(_ => "state2")}> state->str </Button>;
      };
    };

    let wrapper =
      <WrapperButton />
      |> render
      |> getByText(~matcher=`Str("state1"))
      |> parentElement;

    wrapper |> text |> expect |> toContainString("state1") |> ignore;

    wrapper |> FireEvent.click;

    wrapper |> text |> expect |> toContainString("state2");
  });

  test("should ignore events when disabled", () => {
    module WrapperButton = {
      [@react.component]
      let make = () => {
        let (state, setState) = React.useState(() => "state1");
        <Button disabled=true onClick={_ => setState(_ => "state2")}>
          state->str
        </Button>;
      };
    };

    let wrapper =
      <WrapperButton />
      |> render
      |> getByText(~matcher=`Str("state1"))
      |> parentElement;

    wrapper |> text |> expect |> toContainString("state1") |> ignore;

    wrapper |> FireEvent.click;

    wrapper |> text |> expect |> toContainString("state1") |> ignore;
    wrapper |> text |> expect |> not |> toContainString("state2");
  });

  test("should ignore events when loading", () => {
    module WrapperButton = {
      [@react.component]
      let make = () => {
        let (state, setState) = React.useState(() => "state1");
        <Button loading=true onClick={_ => setState(_ => "state2")}>
          state->str
        </Button>;
      };
    };

    let wrapper = <WrapperButton /> |> render |> container;

    wrapper |> FireEvent.click;

    wrapper |> text |> expect |> not |> toContainString("state2");
  });

  test("should render special styles", () => {
    <div>
      <Button ghost=true> "button"->str </Button>
      <Button ghost=true _type=`success> "button"->str </Button>
      <Button ghost=true _type=`warning> "button"->str </Button>
      <Button ghost=true loading=true> "button"->str </Button>
      <Button shadow=true> "button"->str </Button>
      <Button auto=true> "button"->str </Button>
      <Button effect=false> "button"->str </Button>
    </div>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should remove expired events", () => {
    let wrapper = <Button> "button"->str </Button> |> render;

    wrapper |> getByText(~matcher=`Str("button")) |> FireEvent.click;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should support loading change with deply", () => {
    let wrapper = <Button> "button"->str </Button> |> render;

    wrapper |> container |> FireEvent.click;

    sleep(500) |> ignore;

    wrapper |> rerender(<Button loading=true> "button"->str </Button>);

    sleep(500) |> ignore;

    wrapper
    |> container
    |> querySelector(".loading-container")
    |> parentElement
    |> childElementCount
    |> expect
    |> not
    |> toBe(0);
  });
});
