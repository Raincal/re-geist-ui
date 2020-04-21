[@bs.obj]
external makePropsZui:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~key: string=?,
    ~name: string=?,
    ~className: string=?,
    ~title: string,
    ~subtitle: 'subtitle=?,
    ~initialVisible: bool=?,
    ~shadow: bool=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~style: option(ReactDOMRe.Style.t)=?,
      ~children: option(React.element)=?,
      ~id: option(string)=?,
      ~key: option(string)=?,
      ~name: option(string)=?,
      ~className: option(string)=?,
      ~title: string,
      ~subtitle: option([ | `String(string) | `Element(React.element)])=?,
      ~initialVisible: option(bool)=?,
      ~shadow: option(bool)=?,
      unit,
    ) =>
  makePropsZui(
    ~style?,
    ~children?,
    ~id?,
    ~key?,
    ~name?,
    ~className?,
    ~title,
    ~subtitle=?subtitle->(Belt.Option.map(v => ZeitUiHelper.unwrapValue(v))),
    ~initialVisible?,
    ~shadow?,
    unit,
  );

[@bs.module "@zeit-ui/react"] external make: React.component('a) = "Collapse";

module Group = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Collapse"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~accordion: bool=?
    ) =>
    React.element =
    "Group";
};