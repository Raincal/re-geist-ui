[@bs.obj]
external makePropsZui:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~key: string=?,
    ~text: 'text=?,
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
    ~onVisibleChange: bool => unit=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~style: option(ReactDOMRe.Style.t)=?,
      ~children: option(React.element)=?,
      ~id: option(string)=?,
      ~className: option(string)=?,
      ~key: option(string)=?,
      ~text: [ | `String(string) | `Element(React.element)],
      ~visible: option(bool)=?,
      ~initialVisible: option(bool)=?,
      ~hideArrow: option(bool)=?,
      ~_type:
         option(
           [
             | `default
             | `secondary
             | `success
             | `warning
             | `error
             | `dark
             | `lite
           ],
         )=?,
      ~placement: option(ZeitUiTypes.placement)=?,
      ~trigger: option([ | `click | `hover])=?,
      ~enterDelay: option(int)=?,
      ~leaveDelay: option(int)=?,
      ~offset: option(int)=?,
      ~portalClassName: option(string)=?,
      ~onVisibleChange: option(bool => unit)=?,
      unit,
    ) =>
  makePropsZui(
    ~style?,
    ~children?,
    ~id?,
    ~className?,
    ~key?,
    ~text=ZeitUiHelper.unwrapValue(text),
    ~visible?,
    ~initialVisible?,
    ~hideArrow?,
    ~_type?,
    ~placement?,
    ~trigger?,
    ~enterDelay?,
    ~leaveDelay?,
    ~offset?,
    ~portalClassName?,
    ~onVisibleChange?,
    unit,
  );

[@bs.module "@zeit-ui/react"] external make: React.component('a) = "Tooltip";