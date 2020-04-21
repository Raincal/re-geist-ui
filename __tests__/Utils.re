open Jest;
open ReactTestingLibrary;
open Webapi.Dom.Element;
open Js.Promise;

// Bindings
[@bs.get] external text: Dom.element => string = "textContent";

[@bs.send.pipe: Dom.element]
external querySelectorAll: string => Dom.nodeList = "querySelectorAll";

[@bs.send.pipe: Dom.element]
external getAttribute: string => string = "getAttribute";

[@bs.get] external parentElement: Dom.element => Dom.element = "parentElement";

[@bs.get] external childElementCount: Dom.element => int = "childElementCount";

[@bs.get] external checked: Dom.element => bool = "checked";

[@bs.get] external checkedNode: Dom.node => bool = "checked";

[@bs.get]
external mockRestore: MockJs.fn(string => unit, string, unit) => unit =
  "mockRestore";

[@bs.module "@testing-library/react"]
external waitForElement: (unit => Dom.element) => Js.Promise.t('a) =
  "waitForElement";

// Utility Functions
let str = React.string;

let sleep = ms =>
  make((~resolve, ~reject as _reject) => {
    let value = ();
    Js.Global.setTimeout(() => resolve(. value), ms)->ignore;
  });

let renderWithTestId = (~testId=?, element) => {
  switch (testId) {
  | Some(testId) =>
    render(
      ReasonReact.cloneElement(
        element,
        ~props={"data-testid": testId},
        [||],
      ),
    )
  | None => render(element)
  };
};

let queryByTestID = (id: string, element: Dom.element) =>
  switch (element |> querySelector({j|[data-testid="$(id)"]|j})) {
  | Some(el) => el
  | None => raise(Failure("Element not found"))
  };

let querySelector = (selector: string, element: Dom.element) =>
  switch (element |> querySelector(selector)) {
  | Some(el) => el
  | None => raise(Failure("Element not found"))
  };

let findBySelector = (selector: string, element: Dom.element) =>
  element
  |> querySelectorAll(selector)
  |> Webapi.Dom.NodeList.toArray
  |> Array.length;