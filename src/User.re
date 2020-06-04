[@bs.obj]
external makePropsZui:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~className: string=?,
    ~key: string=?,
    ~name: 'name,
    ~src: string=?,
    ~text: string=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~style: option(ReactDOMRe.Style.t)=?,
      ~children: option(React.element)=?,
      ~id: option(string)=?,
      ~className: option(string)=?,
      ~key: option(string)=?,
      ~name: [ | `String(string) | `Element(React.element)],
      ~src: option(string)=?,
      ~text: option(string)=?,
      unit,
    ) =>
  makePropsZui(
    ~style?,
    ~children?,
    ~id?,
    ~className?,
    ~key?,
    ~name=ZeitUiHelper.unwrapValue(name),
    ~src?,
    ~text?,
    unit,
  );

[@bs.module "@zeit-ui/react"] external make: React.component('a) = "User";

module Link = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "User"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~href: string=?
    ) =>
    React.element =
    "Link";
};