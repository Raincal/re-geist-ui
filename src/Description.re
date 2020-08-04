[@bs.obj]
external makePropsZui:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~id: string=?,
    ~className: string=?,
    ~key: string=?,
    ~title: 'title=?,
    ~content: 'content=?,
    unit
  ) =>
  _;

let makeProps =
    (
      ~style: option(ReactDOMRe.Style.t)=?,
      ~id: option(string)=?,
      ~className: option(string)=?,
      ~key: option(string)=?,
      ~title: option([ | `String(string) | `Element(React.element)])=?,
      ~content: option([ | `String(string) | `Element(React.element)])=?,
      unit,
    ) =>
  makePropsZui(
    ~style?,
    ~id?,
    ~key?,
    ~className?,
    ~title=?title->(Belt.Option.map(v => ZeitUiHelper.unwrapValue(v))),
    ~content=?content->(Belt.Option.map(v => ZeitUiHelper.unwrapValue(v))),
    unit,
  );

[@bs.module "@zeit-ui/react"]
external make: React.component('a) = "Description";
