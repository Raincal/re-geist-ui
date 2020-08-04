open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

describe("Card", () => {
  test("should render correctly", () => {
    let wrapper = render(<Card> "card"->str </Card>);
    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should support shadow and hoverable", () => {
    <div>
      <Card hoverable=true> "card"->str </Card>
      <Card shadow=true> "card"->str </Card>
      <Card shadow=true hoverable=true> "card"->str </Card>
    </div>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should render different types", () => {
    <>
      <Card _type=`secondary> "card"->str </Card>
      <Card _type=`success> "card"->str </Card>
      <Card _type=`violet> "card"->str </Card>
      <Card _type=`lite> "card"->str </Card>
      <Card _type=`cyan> "card"->str </Card>
      <Card _type=`secondary> "card"->str </Card>
      <Card _type=`warning> "card"->str </Card>
    </>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });

  test("should render correctly when nested", () => {
    <Card> <Card shadow=true> <Card> "card"->str </Card> </Card> </Card>
    |> render
    |> container
    |> expect
    |> toMatchSnapshot
  });
});
