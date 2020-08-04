type toastAction;
[@bs.obj]
external makeToastAction:
  (
    ~name: string,
    ~handler: (ReactEvent.Mouse.t, unit => unit) => unit,
    ~passive: bool=?,
    unit
  ) =>
  toastAction;

type toast;
[@bs.obj]
external makeToast:
  (
    ~text: string=?,
    ~_type: [ | `default | `secondary | `success | `warning | `error]=?,
    ~delay: int=?,
    ~actions: array(toastAction)=?,
    unit
  ) =>
  toast;
