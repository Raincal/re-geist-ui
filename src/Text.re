module Size: {
  type t;
  let int: int => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let int = (v: int) => Any(v);
  let string = (v: string) => Any(v);
};

[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~h1: bool=?,
    ~h2: bool=?,
    ~h3: bool=?,
    ~h4: bool=?,
    ~h5: bool=?,
    ~h6: bool=?,
    ~p: bool=?,
    ~small: bool=?,
    ~span: bool=?,
    ~del: bool=?,
    ~i: bool=?,
    ~em: bool=?,
    ~b: bool=?,
    ~blockquote: bool=?,
    ~size: Size.t=?,
    ~_type: [ | `default | `secondary | `success | `warning | `error]=?
  ) =>
  React.element =
  "Text";
