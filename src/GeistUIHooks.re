open GeistUITypes;

[@bs.module "@geist-ui/react"]
external useTheme: unit => GeistUITheme.t = "useTheme";

[@bs.module "@geist-ui/react"]
external useToasts: unit => (array(Toast.toast), Toast.toast => unit) =
  "useToasts";

[@bs.module "@geist-ui/react"] external useInput: string => input = "useInput";

[@bs.module "@geist-ui/react"] external useModal: bool => modal = "useModal";

[@bs.module "@geist-ui/react"] external useTabs: string => tabs = "useTabs";

// useBodyScroll
type bodyScrollOptions = {scrollLayer: bool};

[@bs.module "@geist-ui/react"]
external useBodyScroll:
  (
    ~elementRef: Js.Nullable.t(ref('value))=?,
    ~options: bodyScrollOptions=?,
    unit
  ) =>
  unit =
  "useBodyScroll";

// useClickAway
[@bs.module "@geist-ui/react"]
external useClickAway:
  (Js.Nullable.t(ref('value)), [@bs.uncurry] (ReactEvent.Mouse.t => unit)) =>
  unit =
  "useClickAway";

// useClipboard
type useClipboardOptions = {onError: unit => unit};

type copyResult = {copy: string => unit};

[@bs.module "@geist-ui/react"]
external useClipboard: (~options: useClipboardOptions=?, unit) => copyResult =
  "useClipboard";

// useCurrentState
[@bs.module "@geist-ui/react"]
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

[@bs.module "@geist-ui/react"]
external useMediaQuery:
  (
    [ | `xs | `sm | `md | `lg | `xl | `mobile],
    ~options: responsiveOptions=?,
    unit
  ) =>
  bool =
  "useMediaQuery";
