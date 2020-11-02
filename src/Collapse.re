module Component: {
  type t;
  let string: string => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~key: string=?,
    ~name: string=?,
    ~className: string=?,
    ~title: string,
    ~subtitle: Component.t=?,
    ~initialVisible: bool=?,
    ~shadow: bool=?
  ) =>
  React.element =
  "Collapse";

module Group = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Collapse"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~accordion: bool=?
    ) =>
    React.element =
    "Group";
};
