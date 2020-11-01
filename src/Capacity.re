[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~value: int=?,
    ~limit: int=?,
    ~color: string=?
  ) =>
  React.element =
  "Capacity";
