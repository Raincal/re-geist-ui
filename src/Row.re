[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~key: string=?,
    ~name: string=?,
    ~className: string=?,
    ~autoFocus: bool=?,
    ~gap: float=?,
    ~justify: [@bs.string] [
                | `start
                | [@bs.as "end"] `end_
                | `center
                | [@bs.as "space-around"] `spaceAround
                | [@bs.as "space-between"] `spaceBetween
                | `abort
              ]
                =?,
    ~align: [@bs.string] [ | `top | `middle | `bottom]=?,
    ~component: string=?
  ) =>
  React.element =
  "Row";