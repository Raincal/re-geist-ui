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

module Group = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Avatar"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~name: string=?,
      ~className: string=?,
      ~id: string=?,
      ~count: int=?
    ) =>
    React.element =
    "Group";
};