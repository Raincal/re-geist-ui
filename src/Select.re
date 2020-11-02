module Value: {
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
    ~value: Value.t=?,
    ~initialValue: Value.t=?,
    ~placeholder: string=?,
    ~width: string=?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~icon: React.element=?,
    ~pure: bool=?,
    ~multiple: bool=?,
    ~disabled: bool=?,
    ~onChange: Value.t => unit=?,
    ~dropdownClassName: string=?,
    ~dropdownStyle: ReactDOMRe.Style.t=?,
    ~disableMatchWidth: bool=?
  ) =>
  React.element =
  "Select";

module Option = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Select"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~value: string=?,
      ~disabled: bool=?
    ) =>
    React.element =
    "Option";
};
