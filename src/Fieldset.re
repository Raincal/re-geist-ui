module Component: {
  type t;
  let string: string => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~key: string=?,
    ~value: string=?,
    ~label: string=?,
    ~title: Component.t=?,
    ~subtitle: Component.t=?
  ) =>
  React.element =
  "Fieldset";

module Group = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Fieldset"]
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
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Title";
};

module Subtitle = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Subtitle";
};

module Content = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Content";
};

module Body = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Content";
};

module Footer = {
  module Actions = {
    [@react.component]
    [@bs.module "@geist-ui/react"]
    [@bs.scope ("Fieldset", "Footer")]
    external make:
      (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) =>
      React.element =
      "Actions";
  };

  module Status = {
    [@react.component]
    [@bs.module "@geist-ui/react"]
    [@bs.scope ("Fieldset", "Footer")]
    external make:
      (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) =>
      React.element =
      "Status";
  };

  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Fieldset"]
  external make:
    (~style: ReactDOMRe.Style.t=?, ~children: React.element=?) => React.element =
    "Footer";
};
