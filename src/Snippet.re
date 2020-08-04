[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~name: string=?,
    ~className: string=?,
    ~text: ZeitUiTypes.String_or_stringArray.t=?,
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
    ~filled: bool=?,
    ~width: string=?,
    ~copy: [ | `default | `slient | `prevent]=?
  ) =>
  React.element =
  "Snippet";
