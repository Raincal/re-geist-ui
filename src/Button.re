[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~name: string=?,
    ~autoFocus: bool=?,
    ~_type: [@bs.string] [
              | `default
              | `secondary
              | `success
              | `warning
              | `error
              | `abort
            ]
              =?,
    ~size: [@bs.string] [ | `mini | `small | `medium | `large]=?,
    ~ghost: bool=?,
    ~loading: bool=?,
    ~shadow: bool=?,
    ~auto: bool=?,
    ~effect: bool=?,
    ~disabled: bool=?,
    ~onClick: ReactEvent.Mouse.t => unit=?
  ) =>
  React.element =
  "Button";