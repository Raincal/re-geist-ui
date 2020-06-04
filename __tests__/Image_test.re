open Jest;
open Expect;
open ReactTestingLibrary;
open Utils;

let url = {j| 'data:image/png;base64, iVBORw0KGgoAAAANSUhEUgAAAAUA' +
  'AAAFCAYAAACNbyblAAAAHElEQVQI12P4//8/w38GIAXDIBKE0DHxgljNBAAO' +
  '9TXL0Y4OHwAAAABJRU5ErkJggg==' |j};

describe("Image", () => {
  test("should render correctly", () => {
    let wrapper = render(<Image src=url />);
    wrapper |> container |> expect |> toMatchSnapshot;
    (() => wrapper |> unmount()) |> expect |> not |> toThrow;

    wrapper |> rerender(<Image src=url width=20 height=20 />);
    wrapper |> container |> querySelector("img") |> FireEvent.load;
    wrapper |> container |> expect |> toMatchSnapshot;
    (() => wrapper |> unmount()) |> expect |> not |> toThrow;

    wrapper
    |> rerender(<Image src=url width=20 height=20 disableSkeleton=true />);
    wrapper |> container |> querySelector("img") |> FireEvent.load;
    wrapper |> container |> expect |> toMatchSnapshot;
    (() => wrapper |> unmount()) |> expect |> not |> toThrow;
  });

  test("should work correctly with skeleton", () => {
    let wrapper = render(<Image src=url width=20 height=20 />);
    wrapper |> container |> findBySelector(".skeleton") |> expect |> toBe(1);

    wrapper |> rerender(<Image src=url width=20 height=20 />);
    wrapper |> container |> querySelector("img") |> FireEvent.load;
    wrapper |> container |> findBySelector(".skeleton") |> expect |> toBe(1);

    wrapper |> rerender(<Image src=url width=20 />);
    wrapper |> container |> findBySelector(".skeleton") |> expect |> toBe(0);

    wrapper
    |> rerender(<Image src=url width=20 height=20 disableSkeleton=true />);
    wrapper |> container |> findBySelector(".skeleton") |> expect |> toBe(0);
  });
});