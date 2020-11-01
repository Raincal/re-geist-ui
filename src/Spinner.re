[@react.component] [@bs.module "@geist-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~size: [ | `mini | `small | `medium | `large]=?
  ) =>
  React.element =
  "Spinner";
