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
    ~id: string=?,
    ~className: string=?,
    ~key: string=?,
    ~title: Component.t=?,
    ~content: Component.t=?
  ) =>
  React.element =
  "Description";
