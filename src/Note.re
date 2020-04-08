[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~_type: [@bs.string] [
              | `default
              | `secondary
              | `success
              | `warning
              | `error
            ]
              =?,
    ~label: ZeitUiTypes.String_or_bool.t=?,
    ~small: bool=?,
    ~filled: bool=?
  ) =>
  React.element =
  "Note";