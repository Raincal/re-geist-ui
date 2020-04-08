open ZeitUiTypes;

[@bs.module "@zeit-ui/react"]
external useTheme: unit => ZeitUiTheme.t = "useTheme";

[@bs.module "@zeit-ui/react"]
external useToasts: unit => (array(Toast.toast), Toast.toast => unit) =
  "useToasts";

[@bs.module "@zeit-ui/react"] external useInput: string => input = "useInput";

[@bs.module "@zeit-ui/react"] external useModal: bool => modal = "useModal";

[@bs.module "@zeit-ui/react"] external useTabs: string => tabs = "useTabs";