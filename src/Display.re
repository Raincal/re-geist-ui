[@bs.obj]
external makePropsZui:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~className: string=?,
    ~key: string=?,
    ~caption: 'caption=?,
    ~shadow: bool=?,
    ~width: string=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~style: option(ReactDOMRe.Style.t)=?,
      ~children: option(React.element)=?,
      ~id: option(string)=?,
      ~className: option(string)=?,
      ~key: option(string)=?,
      ~caption: option([ | `String(string) | `Element(React.element)])=?,
      ~shadow: option(bool)=?,
      ~width: option(string)=?,
      unit,
    ) =>
  makePropsZui(
    ~style?,
    ~children?,
    ~id?,
    ~key?,
    ~className?,
    ~caption=?caption->(Belt.Option.map(v => ZeitUiHelper.unwrapValue(v))),
    ~shadow?,
    ~width?,
    unit,
  );

[@bs.module "@zeit-ui/react"] external make: React.component('a) = "Display";