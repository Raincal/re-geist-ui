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
    ~_type: [
              | `default
              | `secondary
              | `success
              | `warning
              | `error
              | `dark
              | `lite
            ]
              =?,
    ~placement: [
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
    ~trigger: [ | `click | `hover]=?,
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
      ~placement: option(GeistUITypes.placement)=?,
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
    ~text=GeistUIHelper.unwrapValue(text),
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

[@bs.module "@geist-ui/react"] external make: React.component('a) = "Tooltip";
