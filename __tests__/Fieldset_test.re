open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Fieldset", () => {
  test("should render correctly", () => {
    let wrapper =
      render(
        <Fieldset>
          <Fieldset.Title> "title"->str </Fieldset.Title>
          <Fieldset.Subtitle> "subtitle"->str </Fieldset.Subtitle>
          <Fieldset.Footer>
            <Fieldset.Footer.Status> "status"->str </Fieldset.Footer.Status>
            <Fieldset.Footer.Actions>
              <button> "Actions"->str </button>
            </Fieldset.Footer.Actions>
          </Fieldset.Footer>
        </Fieldset>,
      );

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should render correctly", () => {
    let wrapper =
      render(
        <Fieldset>
          <Fieldset.Title> "title"->str </Fieldset.Title>
          <Fieldset.Subtitle> "subtitle"->str </Fieldset.Subtitle>
          <Fieldset.Footer>
            <Fieldset.Footer.Status> "status"->str </Fieldset.Footer.Status>
            <Fieldset.Footer.Actions>
              <button> "Actions"->str </button>
            </Fieldset.Footer.Actions>
          </Fieldset.Footer>
        </Fieldset>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });
});
