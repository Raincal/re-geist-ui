open Jest;
open Expect;
open ReactTestingLibrary;
open Webapi.Dom;
open Utils;

describe("Avatar", () => {
  test("should render correctly", () => {
    <Avatar /> |> render |> container |> expect |> toMatchSnapshot
  });

  test("should support square", () => {
    <Avatar isSquare=true />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should render text element", () => {
    <Avatar text="text" /> |> render |> container |> expect |> toMatchSnapshot
  });

  test("should omit long chars automatically", () => {
    <Avatar text="texttexttexttext" />
    |> render
    |> getByText(~matcher=`RegExp([%bs.re "/tex/"]))
    |> text
    |> String.length
    |> expect
    |> toBeLessThan(4)
  });

  test("stacked should be work", () => {
    <Avatar
      src="https://zeit.co/api/www/avatar/?u=evilrabbit&s=160"
      stacked=true
    />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should render component of a specified size", () => {
    <Avatar size={Avatar.Size.int(20)} />
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("group component should render all children", () => {
    <Avatar.Group> <Avatar /> <Avatar /> </Avatar.Group>
    |> render
    |> container
    |> querySelectorAll(".avatar")
    |> NodeList.toArray
    |> expect
    |> toHaveLength(2)
  });

  test("should stacked when avatars are in a group", () => {
    <Avatar.Group> <Avatar /> <Avatar /> </Avatar.Group>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should show count in group", () => {
    let count = 20;
    <Avatar.Group count />
    |> render
    |> getByText(~matcher=`RegExp([%bs.re "/\\d/"]))
    |> text
    |> expect
    |> toContainString(string_of_int(count));
  });
});
