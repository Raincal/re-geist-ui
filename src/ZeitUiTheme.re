type palette = {
  accents_1: string,
  accents_2: string,
  accents_3: string,
  accents_4: string,
  accents_5: string,
  accents_6: string,
  accents_7: string,
  accents_8: string,
  background: string,
  foreground: string,
  selection: string,
  secondary: string,
  code: string,
  border: string,
  success: string,
  successLight: string,
  successDark: string,
  error: string,
  errorLight: string,
  errorDark: string,
  warning: string,
  warningLight: string,
  warningDark: string,
  cyan: string,
  purple: string,
  alert: string,
  violet: string,
  link: string,
};
[@bs.obj]
external palette:
  (
    ~accents_1: string=?,
    ~accents_2: string=?,
    ~accents_3: string=?,
    ~accents_4: string=?,
    ~accents_5: string=?,
    ~accents_6: string=?,
    ~accents_7: string=?,
    ~accents_8: string=?,
    ~background: string=?,
    ~foreground: string=?,
    ~selection: string=?,
    ~secondary: string=?,
    ~code: string=?,
    ~border: string=?,
    ~success: string=?,
    ~successLight: string=?,
    ~successDark: string=?,
    ~error: string=?,
    ~errorLight: string=?,
    ~errorDark: string=?,
    ~warning: string=?,
    ~warningLight: string=?,
    ~warningDark: string=?,
    ~cyan: string=?,
    ~purple: string=?,
    ~alert: string=?,
    ~violet: string=?,
    ~link: string=?,
    unit
  ) =>
  palette;

type expressiveness;
[@bs.obj]
external expressiveness:
  (
    ~linkStyle: string=?,
    ~linkHoverStyle: string=?,
    ~dropdownBoxShadow: string=?,
    ~scrollerStart: string=?,
    ~scrollerEnd: string=?,
    ~shadowSmall: string=?,
    ~shadowMedium: string=?,
    ~shadowLarge: string=?,
    ~portalOpacity: float=?,
    unit
  ) =>
  expressiveness;

type layout;
[@bs.obj]
external layout:
  (
    ~gap: string=?,
    ~gapNegative: string=?,
    ~gapHalf: string=?,
    ~gapHalfNegative: string=?,
    ~gapQuarter: string=?,
    ~gapQuarterNegative: string=?,
    ~pageMargin: string=?,
    ~pageWidth: string=?,
    ~pageWidthWithMargin: string=?,
    ~breakpointMobile: string=?,
    ~breakpointTablet: string=?,
    ~radius: string=?,
    unit
  ) =>
  layout;

type font;
[@bs.obj] external font: (~sans: string=?, ~mono: string=?, unit) => font;

type theme = {
  palette,
  expressiveness,
  layout,
  font,
  [@bs.as "type"]
  _type: string,
};

type t = theme;
[@bs.obj]
external make:
  (
    ~palette: palette=?,
    ~expressiveness: expressiveness=?,
    ~layout: layout=?,
    ~font: font=?,
    ~_type: [ | `dark | `light]=?,
    unit
  ) =>
  t;
