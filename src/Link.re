[@react.component] [@bs.module "@geist-ui/react"]
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
    ~icon: bool=?,
    ~underline: bool=?,
    ~block: bool=?,
    ~ref: React.ref(option(Dom.element))=?
  ) =>
  React.element =
  "Link";
