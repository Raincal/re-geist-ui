[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~title: string=?,
    ~_type: [ | `default | `secondary | `success | `warning | `error]=?,
    ~size: [ | `mini | `small | `medium | `large]=?,
    ~color: string=?,
    ~width: string=?,
    ~height: string=?
  ) =>
  React.element =
  "Loading";
