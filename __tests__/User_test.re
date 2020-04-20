open Jest;
open JestDom;
open Expect;
open ReactTestingLibrary;
open Webapi.Dom;
open Utils;

describe("User", () => {
  test("should render correctly", () => {
    let wrapper = render(<User name={`String("witt")} />);
    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should support image and text", () => {
    let wrapper =
      render(
        <div>
          <User name={`String("witt")} text="witt" />
          <User
            name={`String("witt")}
            src="https://unix.bio/assets/avatar.png"
          />
        </div>,
      );
    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should render description correctly", () => {
    let wrapper =
      render(<User name={`String("witt")}> "description"->str </User>);

    wrapper |> container |> expect |> toHaveTextContent(`Str("description"));
  });

  test("should render link on user.link", () => {
    let wrapper =
      render(
        <User name={`String("witt")}>
          <User.Link href="https://twitter.com/echo_witt">
            "twitter"->str
          </User.Link>
        </User>,
      );

    wrapper
    |> container
    |> querySelectorAll("a")
    |> NodeList.toArray
    |> Array.length
    |> expect
    |> not
    |> toBe(0);
  });
});