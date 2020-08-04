[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~name: string=?,
    ~className: string=?,
    ~autoFocus: bool=?,
    ~span: int=?,
    ~offset: int=?,
    ~component: string=?
  ) =>
  React.element =
  "Col";
