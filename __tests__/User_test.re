open Jest;
open JestDom;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("User", () => {
  test("should render correctly", () => {
    let wrapper = render(<User name={User.Component.string("witt")} />);

    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should support image and text", () => {
    let wrapper =
      render(
        <div>
          <User name={User.Component.string("witt")} text="witt" />
          <User
            name={User.Component.string("witt")}
            src="https://unix.bio/assets/avatar.png"
          />
        </div>,
      );

    wrapper |> container |> expect |> toMatchSnapshot;
  });

  test("should render description correctly", () => {
    let wrapper =
      render(
        <User name={User.Component.string("witt")}>
          "description"->str
        </User>,
      );

    wrapper
    |> container
    |> JestDom.expect
    |> toHaveTextContent(`Str("description"));
  });

  test("should render link on user.link", () => {
    let wrapper =
      render(
        <User name={User.Component.string("witt")}>
          <User.Link href="https://twitter.com/echo_witt">
            "twitter"->str
          </User.Link>
        </User>,
      );

    wrapper |> container |> findBySelector("a") |> expect |> not |> toBe(0);
  });
});
