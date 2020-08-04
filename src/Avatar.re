module Size = {
  [@unboxed]
  type t =
    | Any('a): t;
  let mini = Any("mini");
  let small = Any("small");
  let medium = Any("medium");
  let large = Any("large");
  let int = (v: int) => Any(v);
  let float = (v: float) => Any(v);
};

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
    ~size: Size.t=?
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
