[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~x: float=?,
    ~y: float=?,
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
    ~align: [@bs.string] [
              | `center
              | `start
              | `left
              | [@bs.as "end"] `_end
              | `right
            ]
              =?,
    ~volume: float=?
  ) =>
  React.element =
  "Divider";
