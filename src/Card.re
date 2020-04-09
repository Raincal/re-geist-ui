[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~hoverable: bool=?,
    ~shadow: bool=?,
    ~_type: [@bs.string] [
              | `default
              | `secondary
              | `success
              | `warning
              | `error
              | `dark
              | `lite
              | `alert
              | `purple
              | `violet
              | `cyan
            ]
              =?
  ) =>
  React.element =
  "Card";