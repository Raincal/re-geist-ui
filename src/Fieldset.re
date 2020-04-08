[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~value: string=?,
    ~label: string=?,
    ~title: ZeitUiTypes.String_or_Element.t=?,
    ~subtitle: ZeitUiTypes.String_or_Element.t=?
  ) =>
  React.element =
  "Fieldset";

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
  external make: (~children: React.element=?) => React.element = "Title";
};

module Subtitle = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Fieldset"]
  external make: (~children: React.element=?) => React.element = "Subtitle";
};

module Footer = {
  module Actions = {
    [@react.component]
    [@bs.module "@zeit-ui/react"]
    [@bs.scope ("Fieldset", "Footer")]
    external make: (~children: React.element=?) => React.element = "Actions";
  };

  module Status = {
    [@react.component]
    [@bs.module "@zeit-ui/react"]
    [@bs.scope ("Fieldset", "Footer")]
    external make: (~children: React.element=?) => React.element = "Status";
  };

  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Fieldset"]
  external make: (~children: React.element=?) => React.element = "Footer";
};