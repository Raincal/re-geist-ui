[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~checked: bool=?,
    ~initialChecked: bool=?,
    ~onChange: ReactEvent.Synthetic.t => unit=?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~disabled: bool=?
  ) =>
  React.element =
  "Toggle";
