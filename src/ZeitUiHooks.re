open ZeitUiTypes;

[@bs.module "@zeit-ui/react"]
external useTheme: unit => ZeitUiTheme.t = "useTheme";

[@bs.module "@zeit-ui/react"]
external useToasts: unit => (array(Toast.toast), Toast.toast => unit) =
  "useToasts";

[@bs.module "@zeit-ui/react"] external useInput: string => input = "useInput";

[@bs.module "@zeit-ui/react"] external useModal: bool => modal = "useModal";

[@bs.module "@zeit-ui/react"] external useTabs: string => tabs = "useTabs";

// useBodyScroll
type bodyScrollOptions = {scrollLayer: bool};

[@bs.module "@zeit-ui/react"]
external useBodyScroll:
  (
    ~elementRef: Js.Nullable.t(ref('value))=?,
    ~options: bodyScrollOptions=?,
    unit
  ) =>
  unit =
  "useBodyScroll";

// useClickAway
[@bs.module "@zeit-ui/react"]
external useClickAway:
  (Js.Nullable.t(ref('value)), [@bs.uncurry] (ReactEvent.Mouse.t => unit)) =>
  unit =
  "useClickAway";

// useClipboard
type useClipboardOptions = {onError: unit => unit};

type copyResult = {copy: string => unit};

[@bs.module "@zeit-ui/react"]
external useClipboard: (~options: useClipboardOptions=?, unit) => copyResult =
  "useClipboard";

// useCurrentState
[@bs.module "@zeit-ui/react"]
external useCurrentState:
  ([@bs.uncurry] (unit => 'state)) =>
  ('state, ('state => 'state) => unit, React.ref('value)) =
  "useCurrentState";

// useMediaQuery
type responsiveOptions;
[@bs.obj]
external makeResponsiveOptions:
  (~match: [ | `up | `down]=?, ~ssrMatchMedia: string => bool=?, unit) =>
  responsiveOptions;

[@bs.module "@zeit-ui/react"]
external useMediaQuery:
  (
    [ | `xs | `sm | `md | `lg | `xl | `mobile],
    ~options: responsiveOptions=?,
    unit
  ) =>
  bool =
  "useMediaQuery";
