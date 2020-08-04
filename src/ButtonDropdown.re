[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~autoFocus: bool=?,
    ~_type: [ | `default | `secondary | `success | `warning | `error]=?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~loading: bool=?,
    ~auto: bool=?,
    ~disabled: bool=?
  ) =>
  React.element =
  "ButtonDropdown";

module Item = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "ButtonDropdown"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~_type: [ | `default | `secondary | `success | `warning | `error]=?,
      ~main: bool=?,
      ~onClick: ReactEvent.Mouse.t => unit=?
    ) =>
    React.element =
    "Item";
};
