open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Description", () => {
  test("should render correctly", () => {
    let wrapper =
      render(<Description title={Description.Component.string("title")} />);

    wrapper |> container |> expect |> toMatchSnapshot |> ignore;

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should render react-node on title", () => {
    let wrapper =
      render(
        <Description
          title={Description.Component.element(<p> "p"->str </p>)}
        />,
      );
    wrapper
    |> container
    |> findBySelector("p")
    |> expect
    |> toBe(1)
    |> ignore;

    wrapper
    |> rerender(
         <Description
           title={Description.Component.element(<h1> "h1"->str </h1>)}
         />,
       );
    wrapper |> container |> findBySelector("h1") |> expect |> toBe(1);
  });

  test("should render react-node on content", () => {
    let wrapper =
      render(
        <Description
          content={Description.Component.element(<p> "p"->str </p>)}
        />,
      );

    wrapper
    |> container
    |> findBySelector("p")
    |> expect
    |> toBe(1)
    |> ignore;

    wrapper
    |> rerender(
         <Description
           content={Description.Component.element(<h1> "h1"->str </h1>)}
         />,
       );

    wrapper |> container |> findBySelector("h1") |> expect |> toBe(1);
  });
});
