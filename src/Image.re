[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~alt: string=?,
    ~src: string=?,
    ~disableSkeleton: bool=?,
    ~disableAutoResize: bool=?,
    ~maxDelay: int=?,
    ~width: int=?,
    ~height: int=?,
    ~scale: string=?
  ) =>
  React.element =
  "Image";

module Browser = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Image"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~className: string=?,
      ~id: string=?,
      ~title: string=?,
      ~url: string=?,
      ~showFullLink: bool=?,
      ~invert: bool=?
    ) =>
    React.element =
    "Browser";
};