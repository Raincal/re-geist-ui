[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~title: ZeitUiTypes.String_or_element.t=?,
    ~content: ZeitUiTypes.String_or_element.t=?
  ) =>
  React.element =
  "Description";