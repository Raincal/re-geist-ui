[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~title: string,
    ~subtitle: ZeitUiTypes.String_or_element.t=?,
    ~initialVisible: bool=?,
    ~shadow: bool=?
  ) =>
  React.element =
  "Collapse";

module Group = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Collapse"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~accordion: bool=?
    ) =>
    React.element =
    "Group";
};