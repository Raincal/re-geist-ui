open Jest;
open JestDom;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("ButtonDropdown", () => {
  test("should render correctly", () => {
    let wrapper =
      render(
        <ButtonDropdown>
          <ButtonDropdown.Item main=true>
            "Default Action"->str
          </ButtonDropdown.Item>
          <ButtonDropdown.Item> "Secondary Action"->str </ButtonDropdown.Item>
          <ButtonDropdown.Item> "Tertiary Action"->str </ButtonDropdown.Item>
        </ButtonDropdown>,
      );
    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should support types and sizes", () => {
    let wrapper =
      render(
        <>
          <ButtonDropdown size=`mini auto=true>
            <ButtonDropdown.Item key="1" main=true>
              "Auto Mini"->str
            </ButtonDropdown.Item>
          </ButtonDropdown>
          <ButtonDropdown size=`large>
            <ButtonDropdown.Item key="2" main=true>
              "Auto Mini"->str
            </ButtonDropdown.Item>
          </ButtonDropdown>
          <ButtonDropdown _type=`secondary>
            <ButtonDropdown.Item key="3" main=true>
              "Secondary Action"->str
            </ButtonDropdown.Item>
          </ButtonDropdown>
        </>,
      );
    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should trigger callback function", () => {
    module Wrapper = {
      [@react.component]
      let make = () => {
        let (state, setState) = React.useState(() => "state1");
        <ButtonDropdown _type=`secondary>
          <ButtonDropdown.Item
            key="1" main=true onClick={_ => setState(_ => "state2")}>
            state->str
          </ButtonDropdown.Item>
        </ButtonDropdown>;
      };
    };

    let wrapper = render(<Wrapper />);

    wrapper |> container |> expect |> toHaveTextContent(`Str("state1"));

    wrapper |> container |> querySelector("button") |> FireEvent.click;

    wrapper |> container |> expect |> toHaveTextContent(`Str("state2"));
  });

  test("should work correctly when callback missing", () => {
    let wrapper =
      render(
        <ButtonDropdown _type=`secondary>
          <ButtonDropdown.Item key="1" main=true />
        </ButtonDropdown>,
      );

    wrapper |> container |> querySelector("button") |> FireEvent.click;

    (() => wrapper |> container) |> expect |> not |> toThrow;
  });

  test("should ignore all events when loading", () => {
    module Wrapper = {
      [@react.component]
      let make = () => {
        let (state, setState) = React.useState(() => "state1");
        <ButtonDropdown _type=`secondary loading=true>
          <ButtonDropdown.Item
            key="1" main=true onClick={_ => setState(_ => "state2")}>
            state->str
          </ButtonDropdown.Item>
        </ButtonDropdown>;
      };
    };

    let wrapper = render(<Wrapper />);

    wrapper |> container |> querySelector("button") |> FireEvent.click;

    wrapper
    |> container
    |> expect
    |> not
    |> toHaveTextContent(`Str("state2"));
  });

  test("should ignore all events when disabled", () => {
    module Wrapper = {
      [@react.component]
      let make = () => {
        let (state, setState) = React.useState(() => "state1");
        <ButtonDropdown _type=`secondary disabled=true>
          <ButtonDropdown.Item
            key="1" main=true onClick={_ => setState(_ => "state2")}>
            state->str
          </ButtonDropdown.Item>
        </ButtonDropdown>;
      };
    };

    let wrapper = render(<Wrapper />);

    wrapper |> container |> querySelector("summary") |> FireEvent.click;
    wrapper |> container |> querySelector("button") |> FireEvent.click;

    wrapper
    |> container
    |> expect
    |> not
    |> toHaveTextContent(`Str("state2"));
  });

  test("should render multiple types", () => {
    let wrapper =
      render(
        <ButtonDropdown size=`medium auto=true>
          <ButtonDropdown.Item main=true _type=`success>
            "Auto Mini"->str
          </ButtonDropdown.Item>
          <ButtonDropdown.Item _type=`warning>
            "Auto Mini"->str
          </ButtonDropdown.Item>
          <ButtonDropdown.Item _type=`error>
            "Auto Mini"->str
          </ButtonDropdown.Item>
        </ButtonDropdown>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should expand after click", () => {
    let wrapper =
      render(
        <ButtonDropdown>
          <ButtonDropdown.Item main=true>
            "Default Action"->str
          </ButtonDropdown.Item>
          <ButtonDropdown.Item> "Secondary Action"->str </ButtonDropdown.Item>
          <ButtonDropdown.Item> "Tertiary Action"->str </ButtonDropdown.Item>
        </ButtonDropdown>,
      );

    wrapper |> container |> querySelector("summary") |> FireEvent.click;

    wrapper
    |> container
    |> querySelector("details")
    |> expect
    |> toHaveAttribute("open");
  });
});