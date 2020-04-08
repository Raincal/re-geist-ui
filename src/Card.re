[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~hoverable: bool=?,
    ~shadow: bool=?
  ) =>
  React.element =
  "Card";