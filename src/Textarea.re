[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~value: string=?,
    ~initialValue: string=?,
    ~placeholder: string=?,
    ~status: [ | `default | `secondary | `success | `warning | `error]=?,
    ~readOnly: bool=?,
    ~disabled: bool=?,
    ~width: string=?,
    ~minHeight: string=?,
    ~onChange: ReactEvent.Synthetic.t => unit=?
  ) =>
  React.element =
  "Textarea";
