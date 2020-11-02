module Text: {
  type t;
  let arrayOf: array(string) => t;
  let string: string => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let arrayOf = (v: array(string)) => Any(v);
  let string = (v: string) => Any(v);
};

[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~text: Text.t=?,
    ~_type: [
              | `default
              | `secondary
              | `success
              | `warning
              | `error
              | `dark
              | `lite
            ]
              =?,
    ~filled: bool=?,
    ~width: string=?,
    ~copy: [ | `default | `slient | `prevent]=?
  ) =>
  React.element =
  "Snippet";
