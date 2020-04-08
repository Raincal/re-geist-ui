[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~src: string=?,
    ~stacked: bool=?,
    ~isSquare: bool=?,
    ~text: string=?,
    ~style: ReactDOMRe.Style.t=?,
    ~alt: string=?,
    ~className: string=?,
    ~size: [@bs.string] [ | `mini | `small | `medium | `large]=?
  ) =>
  React.element =
  "Avatar";