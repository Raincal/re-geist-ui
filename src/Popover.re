[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    // TODO React.element | unit => React.element
    ~content: unit => React.element,
    ~visible: bool=?,
    ~initialVisible: bool=?,
    ~hideArrow: bool=?,
    ~placement: [@bs.string] [
                  | `top
                  | `topStart
                  | `topEnd
                  | `left
                  | `leftStart
                  | `leftEnd
                  | `bottom
                  | `bottomStart
                  | `bottomEnd
                  | `right
                  | `rightStart
                  | `rightEnd
                ]
                  =?,
    ~trigger: [@bs.string] [ | `click | `hover]=?,
    ~enterDelay: int=?,
    ~leaveDelay: int=?,
    ~offset: int=?,
    ~portalClassName: string=?,
    ~onVisibleChange: bool => unit=?
  ) =>
  React.element =
  "Popover";

module Item = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Popover"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~name: string=?,
      ~className: string=?,
      ~line: bool=?,
      ~title: bool=?
    ) =>
    React.element =
    "Item";
};