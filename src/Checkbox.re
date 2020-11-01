[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~form: string=?,
    ~className: string=?,
    ~checked: bool=?,
    ~initialChecked: bool=?,
    ~value: string=?,
    ~disabled: bool=?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~onChange: ReactEvent.Synthetic.t => unit=?
  ) =>
  React.element =
  "Checkbox";

module Group = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Checkbox"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~className: string=?,
      ~value: array(string)=?,
      ~disabled: bool=?,
      ~onChange: array(string) => unit=?
    ) =>
    React.element =
    "Group";
};
