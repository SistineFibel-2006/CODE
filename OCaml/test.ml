let () =
  print_endline "Hello, World";;
let ans =
  3 * 67;;
let () =
  print_endline @@ string_of_int ans;;
let () =
  print_endline @@ string_of_float @@ max 3.14 @@ float_of_int ans;;
let f =
  fun x -> x;;
let () =
  print_endline @@ string_of_int @@ (fun x -> x * x) ans;;
