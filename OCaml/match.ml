let rec matlength' xs cnt = 
  match xs with
  | [] -> 0
  | _ :: [] -> cnt + 1 
  | _ :: x -> matlength' x (cnt + 1)

let matlength xs = 
  matlength' xs 0

let empty lst =
  match lst with
  | [] -> true
  | _ -> false

let rec sum' s = function
  | [] -> s
  | x :: t -> sum' (s + x) t

let sum lst =
  sum' 0 lst

