[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~className: string=?,
    ~hoverable: bool=?,
    ~shadow: bool=?,
    ~_type: [
              | `default
              | `secondary
              | `success
              | `warning
              | `error
              | `dark
              | `lite
              | `alert
              | `purple
              | `violet
              | `cyan
            ]
              =?,
    ~width: string=?
  ) =>
  React.element =
  "Card";

module Content = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Card"]
  external make:
    (~id: string=?, ~className: string=?, ~children: React.element=?) =>
    React.element =
    "Content";
};

module Footer = {
  [@react.component] [@bs.module "@geist-ui/react"] [@bs.scope "Card"]
  external make:
    (
      ~id: string=?,
      ~className: string=?,
      ~children: React.element=?,
      ~disableAutoMargin: bool=?
    ) =>
    React.element =
    "Footer";
};
