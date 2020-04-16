open Jest;
open Expect;
open ReactTestingLibrary;
open Webapi.Dom;
open Utils;

describe("Checkbox", () => {
  test("should render correctly", () => {
    let wrapper = render(<Checkbox checked=true> "Sydney"->str </Checkbox>);

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;

    let rendered = render(<Checkbox> "Sydney"->str </Checkbox>);

    rendered |> container |> expect |> toMatchSnapshot;
  });

  test("should work correctly with initial value", () => {
    let wrapper = render(<Checkbox checked=true> "Sydney"->str </Checkbox>);

    wrapper
    |> container
    |> querySelector("input")
    |> checked
    |> expect
    |> ExpectJs.toBeTruthy;

    wrapper |> rerender(<Checkbox checked=false> "Sydney"->str </Checkbox>);

    wrapper
    |> container
    |> querySelector("input")
    |> checked
    |> expect
    |> not
    |> ExpectJs.toBeTruthy;

    wrapper
    |> rerender(<Checkbox initialChecked=true> "Sydney"->str </Checkbox>);

    wrapper
    |> container
    |> querySelector("input")
    |> checked
    |> expect
    |> ExpectJs.toBeTruthy;

    wrapper
    |> rerender(<Checkbox initialChecked=false> "Sydney"->str </Checkbox>);

    wrapper
    |> container
    |> querySelector("input")
    |> checked
    |> expect
    |> not
    |> ExpectJs.toBeTruthy;
  });

  test("should change value after click", () => {
    module Wrapper = {
      [@react.component]
      let make = () => {
        let (state, setState) = React.useState(_ => "state1");
        <Checkbox initialChecked=true onChange={_ => setState(_ => "state2")}>
          state->str
        </Checkbox>;
      };
    };

    let wrapper =
      <Wrapper />
      |> render
      |> getByText(~matcher=`Str("state1"))
      |> parentElement;

    wrapper |> FireEvent.click;

    wrapper
    |> querySelector(".text")
    |> text
    |> expect
    |> toContainString("state2");
  });

  test("should ignore events when disabled", () => {
    module Wrapper = {
      [@react.component]
      let make = () => {
        let (state, setState) = React.useState(_ => "state1");
        <Checkbox disabled=true onChange={_ => setState(_ => "state2")}>
          state->str
        </Checkbox>;
      };
    };

    let wrapper =
      <Wrapper />
      |> render
      |> getByText(~matcher=`Str("state1"))
      |> parentElement;

    wrapper |> FireEvent.click;

    wrapper
    |> querySelector(".text")
    |> text
    |> expect
    |> not
    |> toContainString("state2");
  });
});

describe("Checkbox Group", () => {
  test("should render correctly", () => {
    let wrapper =
      render(
        <Checkbox.Group value=[||]>
          <Checkbox value="sydney"> "Sydney"->str </Checkbox>
        </Checkbox.Group>,
      );

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;

    let rendered =
      render(
        <Checkbox.Group value=[||]>
          <Checkbox value="sydney"> "Sydney"->str </Checkbox>
        </Checkbox.Group>,
      );
    rendered |> container |> expect |> toMatchSnapshot;
  });

  test("should work correctly with initial value", () => {
    let wrapper =
      render(
        <Checkbox.Group value=[|"sydney"|]>
          <Checkbox value="sydney"> "Sydney"->str </Checkbox>
          <Checkbox value="beijing"> "BeiJing"->str </Checkbox>
        </Checkbox.Group>,
      );

    wrapper
    |> container
    |> querySelectorAll("input")
    |> NodeList.item(0)
    |> Belt.Option.getExn
    |> checkedNode
    |> expect
    |> ExpectJs.toBeTruthy;

    wrapper
    |> container
    |> querySelectorAll("input")
    |> NodeList.item(1)
    |> Belt.Option.getExn
    |> checkedNode
    |> expect
    |> not
    |> ExpectJs.toBeTruthy;
  });

  test("should change value after click", () => {
    let value = ref([|"sydney"|]);
    let wrapper =
      render(
        <Checkbox.Group value=[|"sydney"|] onChange={v => value := v}>
          <Checkbox value="sydney"> "Sydney"->str </Checkbox>
          <Checkbox value="beijing"> "BeiJing"->str </Checkbox>
        </Checkbox.Group>,
      );

    let sydney =
      wrapper |> getByText(~matcher=`Str("Sydney")) |> parentElement;

    sydney |> FireEvent.click;

    value^ |> Array.length |> expect |> toBe(0);

    let beijing =
      wrapper |> getByText(~matcher=`Str("BeiJing")) |> parentElement;

    beijing |> FireEvent.click;

    value^ |> expect |> toEqual([|"beijing"|]);
  });

  test("should ignore events when disabled", () => {
    let value = ref([|"sydney"|]);
    let wrapper =
      render(
        <Checkbox.Group
          disabled=true value=[|"sydney"|] onChange={v => value := v}>
          <Checkbox value="sydney"> "Sydney"->str </Checkbox>
          <Checkbox value="beijing"> "BeiJing"->str </Checkbox>
        </Checkbox.Group>,
      );

    let sydney =
      wrapper |> getByText(~matcher=`Str("Sydney")) |> parentElement;

    sydney |> FireEvent.click;

    value^ |> Array.length |> expect |> not |> toBe(0);

    let beijing =
      wrapper |> getByText(~matcher=`Str("BeiJing")) |> parentElement;

    beijing |> FireEvent.click;

    value^ |> expect |> not |> toEqual([|"beijing"|]);
  });

  test("should throw error when value missing", () => {
    let errorMessage = ref("");

    let consoleSpy: MockJs.fn(string => unit, string, unit) = [%raw
      "jest.spyOn(console, 'warn')"
    ];
    MockJs.mockImplementation(msg => errorMessage := msg, consoleSpy);

    render(
      <Checkbox.Group>
        <Checkbox value="sydney"> "Sydney"->str </Checkbox>
        <Checkbox value="beijing"> "BeiJing"->str </Checkbox>
      </Checkbox.Group>,
    );

    consoleSpy |> mockRestore;

    errorMessage^ |> expect |> toContainString("required");
  });

  test("should throw error when set check prop in group", () => {
    let errorMessage = ref("");

    let consoleSpy: MockJs.fn(string => unit, string, unit) = [%raw
      "jest.spyOn(console, 'warn')"
    ];
    MockJs.mockImplementation(msg => errorMessage := msg, consoleSpy);

    render(
      <Checkbox.Group value=[||]>
        <Checkbox value="sydney" checked=true> "Sydney"->str </Checkbox>
        <Checkbox value="beijing"> "BeiJing"->str </Checkbox>
      </Checkbox.Group>,
    );

    consoleSpy |> mockRestore;

    errorMessage^ |> expect |> toContainString("Remove props");
  });
});