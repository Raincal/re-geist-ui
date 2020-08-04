module FileTreeValue = {
  type t;
  [@bs.obj]
  external make:
    (
      ~_type: [ | `directory | `file],
      ~name: string,
      ~extra: string=?,
      ~files: array(t)=?,
      unit
    ) =>
    t;
};

[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~id: string=?,
    ~className: string=?,
    ~title: string=?,
    ~value: array(FileTreeValue.t)=?,
    ~initialExpand: bool=?,
    ~onClick: string => unit=?
  ) =>
  React.element =
  "Tree";

module File = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Tree"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~id: string=?,
      ~className: string=?,
      ~title: string=?,
      ~name: string=?,
      ~extra: string=?
    ) =>
    React.element =
    "File";
};

module Folder = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Tree"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~className: string=?,
      ~title: string=?,
      ~name: string=?,
      ~extra: string=?
    ) =>
    React.element =
    "Folder";
};
