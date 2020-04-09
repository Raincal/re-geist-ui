[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~caption: ZeitUiTypes.String_or_element.t=?,
    ~shadow: bool=?,
    ~width: string=?
  ) =>
  React.element =
  "Display";