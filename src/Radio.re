[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~checked: bool=?,
    ~value: string=?,
    ~disabled: bool=?,
    ~onChange: ReactEvent.Synthetic.t => unit=?
  ) =>
  React.element =
  "Radio";

module Group = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Radio"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~initialValue: string=?,
      ~value: string=?,
      ~useRow: bool=?,
      ~disabled: bool=?,
      ~onChange: string => unit=?
    ) =>
    React.element =
    "Group";
};

module Description = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Radio"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?
    ) =>
    React.element =
    "Description";
};

module Desc = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Radio"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?
    ) =>
    React.element =
    "Desc";
};