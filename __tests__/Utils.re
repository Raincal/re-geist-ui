open Jest;
open Js.Promise;

// Bindings
[@bs.get] external text: Dom.element => string = "textContent";

[@bs.send.pipe: Dom.element]
external querySelector: string => Dom.element = "querySelector";

[@bs.send.pipe: Dom.element]
external querySelectorAll: string => Dom.nodeList = "querySelectorAll";

[@bs.send.pipe: Dom.element]
external getAttribute: string => string = "getAttribute";

[@bs.get] external parentElement: Dom.element => Dom.element = "parentElement";

[@bs.get] external childElementCount: Dom.element => int = "childElementCount";

[@bs.get] external style: Dom.element => Js.t({..}) = "style";

[@bs.get] external checked: Dom.element => bool = "checked";

[@bs.get] external checkedNode: Dom.node => bool = "checked";

[@bs.get]
external mockRestore: MockJs.fn(string => unit, string, unit) => unit =
  "mockRestore";

// Utility Functions
let str = React.string;

let sleep = ms =>
  make((~resolve, ~reject as _reject) => {
    let value = ();
    Js.Global.setTimeout(() => resolve(. value), ms)->ignore;
  });