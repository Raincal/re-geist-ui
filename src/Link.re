[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~rel: string=?,
    ~target: string=?,
    ~href: string=?,
    ~color: bool=?,
    ~pure: bool=?,
    ~underline: bool=?,
    ~block: bool=?
  ) =>
  React.element =
  "Link";