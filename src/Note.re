module Label: {
  type t;
  let bool: bool => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let bool = (v: bool) => Any(v);
  let string = (v: string) => Any(v);
};

[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~_type: [ | `default | `secondary | `success | `warning | `error]=?,
    ~label: Label.t=?,
    ~small: bool=?,
    ~filled: bool=?
  ) =>
  React.element =
  "Note";
