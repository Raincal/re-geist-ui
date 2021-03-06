[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~_type: [ | `text | `password]=?,
    ~width: string=?,
    ~value: string=?,
    ~initialValue: string=?,
    ~placeholder: string=?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~status: [ | `default | `secondary | `success | `warning | `error]=?,
    ~readOnly: bool=?,
    ~disabled: bool=?,
    ~clearable: bool=?,
    ~label: string=?,
    ~labelRight: string=?,
    ~icon: React.element=?,
    ~iconRight: React.element=?,
    ~iconClickable: bool=?,
    ~onIconClick: ReactEvent.Synthetic.t => unit=?,
    ~onChange: ReactEvent.Synthetic.t => unit=?,
    ~onClearClick: ReactEvent.Mouse.t => unit=?,
    ~ref: ReactDOMRe.domRef=?
  ) =>
  React.element =
  "Input";

module Password = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Input"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~className: string=?,
      ~id: string=?,
      ~_type: [ | `text | `password]=?,
      ~width: string=?,
      ~value: string=?,
      ~initialValue: string=?,
      ~placeholder: string=?,
      ~size: [ | `mini | `small | `medium | `large]=?,
      ~status: [ | `default | `secondary | `success | `warning | `error]=?,
      ~readOnly: bool=?,
      ~disabled: bool=?,
      ~clearable: bool=?,
      ~label: string=?,
      ~labelRight: string=?,
      ~icon: React.element=?,
      ~iconRight: React.element=?,
      ~iconClickable: bool=?,
      ~onIconClick: ReactEvent.Synthetic.t => unit=?,
      ~onChange: ReactEvent.Synthetic.t => unit=?,
      ~onClearClick: ReactEvent.Mouse.t => unit=?,
      ~ref: ReactDOMRe.domRef=?,
      ~hideToggle: bool=?
    ) =>
    React.element =
    "Password";
};
