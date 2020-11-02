module Component: {
  type t;
  let string: string => t;
  let element: React.element => t;
} = {
  [@unboxed]
  type t =
    | Any('a): t;
  let string = (v: string) => Any(v);
  let element = (v: React.element) => Any(v);
};

[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~key: string=?,
    ~text: Component.t=?,
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
    ~onVisibleChange: bool => unit=?
  ) =>
  React.element =
  "Tooltip";
