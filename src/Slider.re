[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~initialValue: float=?,
    ~value: float=?,
    ~step: float=?,
    ~max: float=?,
    ~min: float=?,
    ~disabled: bool=?,
    ~showMarkers: bool=?,
    ~onChange: float => unit=?
  ) =>
  React.element =
  "Slider";
