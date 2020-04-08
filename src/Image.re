[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~alt: string=?,
    ~src: string=?,
    ~animation: bool=?,
    ~maxDelay: int=?,
    ~width: int=?,
    ~height: int=?,
    ~scale: string=?
  ) =>
  React.element =
  "Image";