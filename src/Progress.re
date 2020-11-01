[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~_type: [ | `default | `secondary | `success | `warning | `error]=?,
    ~value: int=?,
    ~max: int=?,
    ~fixedTop: bool=?,
    ~fixedBottom: bool=?,
    ~colors: Js.Dict.t(string)=?
  ) =>
  React.element =
  "Progress";
