[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~title: ZeitUiTypes.String_or_Element.t=?,
    ~content: ZeitUiTypes.String_or_Element.t=?
  ) =>
  React.element =
  "Description";