[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~value: ZeitUiTypes.String_or_stringArray.t=?,
    ~initialValue: ZeitUiTypes.String_or_stringArray.t=?,
    ~placeholder: string=?,
    ~width: string=?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~icon: React.element=?,
    ~pure: bool=?,
    ~multiple: bool=?,
    ~disabled: bool=?,
    ~onChange: ZeitUiTypes.String_or_stringArray.t => unit=?,
    ~dropdownClassName: string=?,
    ~dropdownStyle: ReactDOMRe.Style.t=?,
    ~disableMatchWidth: bool=?
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
