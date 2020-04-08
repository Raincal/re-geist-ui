[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~_type: [@bs.string] [
              | `default
              | `secondary
              | `success
              | `warning
              | `error
            ]
              =?,
    ~size: [@bs.string] [ | `mini | `small | `medium | `large]=?
  ) =>
  React.element =
  "Badge";