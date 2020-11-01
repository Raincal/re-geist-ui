[@react.component] [@bs.module "@geist-ui/react"]
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
              | [@bs.as "secondary-light"] `secondaryLight
              | [@bs.as "success-light"] `successLight
              | [@bs.as "warning-light"] `warningLight
              | [@bs.as "error-light"] `errorLight
            ]
              =?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~ghost: bool=?,
    ~loading: bool=?,
    ~shadow: bool=?,
    ~auto: bool=?,
    ~effect: bool=?,
    ~disabled: bool=?,
    ~onClick: ReactEvent.Mouse.t => unit=?,
    ~icon: React.element=?,
    ~iconRight: React.element=?,
    // TODO
    ~htmlType: string=?,
    ~ref: React.ref(option(Dom.element))=?
  ) =>
  React.element =
  "Button";
