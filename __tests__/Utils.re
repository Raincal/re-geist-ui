open Js.Promise;

// Bindings
[@bs.get] external text: Dom.element => string = "textContent";

[@bs.send.pipe: Dom.element]
external querySelector: string => Dom.element = "querySelector";

[@bs.send.pipe: Dom.element]
external querySelectorAll: string => Dom.nodeList = "querySelectorAll";

[@bs.get] external parentElement: Dom.element => Dom.element = "parentElement";

[@bs.get] external childElementCount: Dom.element => int = "childElementCount";

[@bs.get] external style: Dom.element => Js.t({..}) = "style";

// Utility Functions
let str = React.string;

let sleep = ms =>
  make((~resolve, ~reject as _reject) => {
    let value = ();
    Js.Global.setTimeout(() => resolve(. value), ms)->ignore;
  });