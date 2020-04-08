[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~keyType: string=?,
    ~command: bool=?,
    ~shift: bool=?,
    ~option: bool=?,
    ~ctrl: bool=?,
    ~small: bool=?
  ) =>
  React.element =
  "Keyboard";