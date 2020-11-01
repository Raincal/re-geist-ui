[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~_type: [ | `default | `secondary | `success | `warning | `error]=?,
    ~label: GeistUITypes.String_or_bool.t=?,
    ~small: bool=?,
    ~filled: bool=?
  ) =>
  React.element =
  "Note";
