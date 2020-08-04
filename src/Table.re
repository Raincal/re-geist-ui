[@react.component] [@bs.module "@zeit-ui/react"]
external make:
  (
    ~style: ReactDOMRe.Style.t=?,
    ~children: React.element=?,
    ~className: string=?,
    ~id: string=?,
    ~data: array('item),
    ~emptyText: string=?,
    ~hover: bool=?,
    ~onRow: ('item, int) => unit=?,
    ~onCell: ('item, int, int) => unit=?,
    ~onChange: array('item) => unit=?
  ) =>
  React.element =
  "Table";

module Column = {
  [@react.component] [@bs.module "@zeit-ui/react"] [@bs.scope "Table"]
  external make:
    (
      ~style: ReactDOMRe.Style.t=?,
      ~children: React.element=?,
      ~id: string=?,
      ~className: string=?,
      ~prop: string=?,
      ~label: string=?,
      ~width: int=?
    ) =>
    React.element =
    "Column";
};

type cellActions = {remove: unit => unit};

type cellData('item) = {
  row: int,
  column: int,
  rowValue: 'item,
};
