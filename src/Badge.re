[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~_type: [ | `default | `secondary | `success | `warning | `error]=?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~dot: bool=?
  ) =>
  React.element =
  "Badge";

module Anchor = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Badge"]
  external make:
    (
      ~alt: string=?,
      ~children: React.element=?,
      ~className: string=?,
      ~id: string=?,
      ~placement: [ | `topLeft | `topRight | `bottomLeft | `bottomRight]=?
    ) =>
    React.element =
    "Anchor";
};
