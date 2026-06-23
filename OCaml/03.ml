type point = 
  float * float

type shapes = 
  | Circle of {center : point; r : float}
  | Rectangle of point * point
  | Point of point

let c1 = Circle {center = (0.,0.); r = 1.}
let r1 = Rectangle ((-1.,-1.), (1., 1.) )

let avg a b =
  (a +. b) /. 2.

let center s = 
  match s with
  | Circle {center; r} -> center 
  | Rectangle (x, t) -> 
      let (x_ll, y_ll) = x in
      let (x_ur, y_ur) = t in
      (avg x_ll x_ur, avg y_ll y_ur)
  | Point p -> p 

type week =
  | Mon | Tue | Thur | Wen

let print x =
  print_endline x

let a = Mon
let ck_week x = 
match x with
  | Mon -> print "Mon"
  | Tue -> print "Tue"
  | Wen -> print "Wen"
  | Thur -> print "Thur"
