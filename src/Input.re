[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~_type: [@bs.string] [ | `text | `password]=?,
    ~width: string=?,
    ~value: string=?,
    ~initialValue: string=?,
    ~placeholder: string=?,
    ~size: [@bs.string] [ | `mini | `small | `medium | `large]=?,
    ~status: [@bs.string] [
               | `default
               | `secondary
               | `success
               | `warning
               | `error
             ]
               =?,
    ~readOnly: bool=?,
    ~disabled: bool=?,
    ~clearable: bool=?,
    ~label: string=?,
    ~labelRight: string=?,
    ~icon: React.element=?,
    ~iconRight: React.element=?,
    ~onChange: ReactEvent.Synthetic.t => unit=?,
    ~onClearClick: ReactEvent.Mouse.t => unit=?
  ) =>
  React.element =
  "Input";