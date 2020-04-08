[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~autoFocus: bool=?,
    ~_open: bool=?,
    ~onOpen: unit => unit=?,
    ~onClose: unit => unit=?,
    ~disableBackdropClick: bool=?
  ) =>
  React.element =
  "Modal";

module Title = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Modal"]
  external make:
    (~children: React.element=?, ~id: string=?, ~className: string=?) =>
    React.element =
    "Title";
};

module Subtitle = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Modal"]
  external make:
    (~children: React.element=?, ~id: string=?, ~className: string=?) =>
    React.element =
    "Subtitle";
};

module Content = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Modal"]
  external make:
    (~children: React.element=?, ~id: string=?, ~className: string=?) =>
    React.element =
    "Content";
};

module Actions = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Modal"]
  external make:
    (~children: React.element=?, ~id: string=?, ~className: string=?) =>
    React.element =
    "Actions";
};

module Action = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Modal"]
  external make:
    (
      ~children: React.element=?,
      ~id: string=?,
      ~className: string=?,
      ~passive: bool=?,
      ~disabled: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?
    ) =>
    React.element =
    "Action";
};