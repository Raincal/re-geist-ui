[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~size: [ | `mini | `small | `medium | `large]=?
  ) =>
  React.element =
  "Spinner";
