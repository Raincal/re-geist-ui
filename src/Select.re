[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~initialValue: string=?,
    ~placeholder: string=?,
    ~size: [@bs.string] [ | `mini | `small | `medium | `large]=?,
    ~icon: React.element=?,
    ~pure: bool=?,
    ~disabled: bool=?,
    ~onChange: string => unit=?
  ) =>
  React.element =
  "Select";

module Option = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Select"]
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