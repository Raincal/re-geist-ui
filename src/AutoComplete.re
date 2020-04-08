module AutoCompleteOption = {
  type t = {
    label: string,
    value: string,
  };
};

[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~autoComplete: bool=?,
    ~options: array(AutoCompleteOption.t)=?,
    ~status: [@bs.string] [
               | `default
               | `secondary
               | `success
               | `warning
               | `error
             ]
               =?,
    ~size: [@bs.string] [ | `mini | `small | `medium | `large]=?,
    ~initialValue: string=?,
    ~value: string=?,
    ~width: string=?,
    ~clearable: bool=?,
    ~searching: bool=?,
    ~onChange: string => unit=?,
    ~onSearch: string => unit=?,
    ~onSelect: string => unit=?
  ) =>
  React.element =
  "AutoComplete";

module Item = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "AutoComplete"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~className: string=?,
      ~value: string=?
    ) =>
    React.element =
    "Item";
};

module Searching = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "AutoComplete"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~className: string=?
    ) =>
    React.element =
    "Searching";
};

module Empty = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "AutoComplete"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~className: string=?
    ) =>
    React.element =
    "Empty";
};