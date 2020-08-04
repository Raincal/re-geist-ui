[@bs.obj]
external makePropsZui:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~key: string=?,
    ~value: string=?,
    ~label: string=?,
    ~title: 'title=?,
    ~subtitle: 'title=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~style: option(ReactDOMRe.Style.t)=?,
      ~children: option(React.element)=?,
      ~id: option(string)=?,
      ~name: option(string)=?,
      ~className: option(string)=?,
      ~key: option(string)=?,
      ~value: option(string)=?,
      ~label: option(string)=?,
      ~title: option([ | `String(string) | `Element(React.element)])=?,
      ~subtitle: option([ | `String(string) | `Element(React.element)])=?,
      unit,
    ) =>
  makePropsZui(
    ~style?,
    ~children?,
    ~id?,
    ~name?,
    ~className?,
    ~key?,
    ~value?,
    ~label?,
    ~title=?title->(Belt.Option.map(v => ZeitUiHelper.unwrapValue(v))),
    ~subtitle=?subtitle->(Belt.Option.map(v => ZeitUiHelper.unwrapValue(v))),
    unit,
  );

[@bs.module "@zeit-ui/react"] external make: React.component('a) = "Fieldset";

module Group = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~value: string=?,
      ~onChange: string => unit=?
    ) =>
    React.element =
    "Group";
};

module Title = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Title";
};

module Subtitle = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Subtitle";
};

module Content = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Content";
};

module Body = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Content";
};

module Footer = {
  module Actions = {
    [@react.component]
    [@bs.module "@zeit-ui/react"]
    [@bs.scope ("Fieldset", "Footer")]
    external make:
      (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) =>
      React.element =
      "Actions";
  };

  module Status = {
    [@react.component]
    [@bs.module "@zeit-ui/react"]
    [@bs.scope ("Fieldset", "Footer")]
    external make:
      (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) =>
      React.element =
      "Status";
  };

  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Footer";
};
