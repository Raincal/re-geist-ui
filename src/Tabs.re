[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~alt: string=?,
    ~initialValue: string=?,
    ~value: string=?,
    ~hideDivider: bool=?,
    ~onChange: string => unit=?
  ) =>
  React.element =
  "Tabs";

module Item = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Tabs"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~label: string=?,
      ~value: string=?,
      ~disabled: bool=?
    ) =>
    React.element =
    "Item";
};
