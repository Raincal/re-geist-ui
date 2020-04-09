[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~text: ZeitUiTypes.String_or_element.t,
    ~visible: bool=?,
    ~initialVisible: bool=?,
    ~hideArrow: bool=?,
    ~_type: [@bs.string] [
              | `default
              | `secondary
              | `success
              | `warning
              | `error
              | `dark
              | `lite
            ]
              =?,
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
  "Tooltip";