[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~className: string=?,
    ~id: string=?,
    ~size: [@bs.string] [ | `mini | `small | `medium | `large]=?
  ) =>
  React.element =
  "Spinner";