let l1 = [1; 2; 3; 4; 5]
let l2 = 1 :: 2 :: 3 :: 4 :: 5 :: []
let l3 = [1] @ [2; 3; 4] @ [5]

let rec product (xs : 'a list) : int = 
  match xs with
  | [] -> 1
  | h :: t -> h * product t

let rec concat (xs : string list) : string = 
  match xs with
  | [] -> ""
  | h :: t -> h ^ concat t

(* patten match *)

let rec pat1 = function
| [] -> false
| h :: _ -> h = "bigred"

let pat2 = function
| _ :: _ :: [] | _ :: _ :: _ :: _ :: [] -> true
| _ -> false

let pat3 = function
| x :: y :: [] -> x = y
| _ -> false

(* library *)

let fiveth (xs : int list) : int = 
  if List.length xs >= 5 then List.nth xs 4 else 0

let downlist (xs : int list) : int list = 
  List.sort Stdlib.compare xs |> List.rev 

(* library puzzle *)

let lastele xs = 
  List.nth (List.rev xs) 0 

let haszero (xs : int list) =
  List.exists (fun x -> x = 0) xs

(* take drop *)

let rec take n xs : int list =
  match n with 
  | 0 -> []
  | _ -> begin
      match xs with 
      | [] -> []
      | h :: t -> h :: take (n - 1) t
    end

let rec drop n xs : int list =
  match n with 
  | 0 -> xs
  | _ -> begin
      match xs with 
      | [] -> []
      | h :: t -> drop (n - 1) t
    end

(* unimodal *)

let rec is_dec (xs : int list) : bool =
  match xs with
  | [] | [_] -> true
  | h1 :: (h2 :: t1 as t) -> h1 >= h2 && is_dec t

let rec is_inc_dec = function
  | [] | [_] -> true
  | a :: (b :: t) as t1 -> 
    if a <= b then is_inc_dec t else is_dec t1  

let is_unimodal xs = is_inc_dec xs

(* powerset *)

let rec powerset (xs : int list) : int list list = 
  let ss = List.sort Stdlib.compare xs in
  match ss with
  | [] -> [[]]
  | h :: t -> let p = powerset t in 
    List.map (List.cons h) p @ p 

(* print int list rec *)
let rec print_int_list (xs : int list) : unit = 
  match xs with 
  | [] -> ()
  | h :: t -> print_endline @@ string_of_int h; print_int_list t

(* print int list iter *)

let print_int_list' xs =
  List.iter (fun x -> print_endline @@ string_of_int x) xs

(* student *)

type student = {first_name : string; last_name : string; gpa : float}

let a1 : student = {first_name = "Line"; last_name = "BuBu"; gpa = 3.1}

let student_name stu = 
  (stu.first_name, stu.last_name)

let student_create f l g : student = 
  {first_name = f; last_name = l; gpa = g}

(* pokerecord *)

type poketype = Normal | Fire | Water
type pokemen = {name : string; hp : int; ptype : poketype}

let charizard = {name = "charizard"; hp = 78; ptype = Fire}
let squirtle = {name = "squirtle"; hp = 44; ptype = Water}

(* safe hd and tl *)

let safe_hd = function
  | [] -> None
  | h :: _ -> Some h 

let rec safe_tl = function
  | [] -> None
  | _ :: t -> match t with 
    | [] -> failwith "can't be trigged" 
    | h :: [] -> Some h
    | _ -> safe_tl t

(* pokefun *)

let rec max_hp (xs : pokemen list) : pokemen option = 
  match xs with 
  | [] -> None
  | h :: t -> match max_hp t with
    | None -> Some h
    | Some h1 -> Some (if h1.hp >= h.hp then h1 else h)

(* date before *)

type date = int * int * int
let is_before (x : date) (y : date) : bool = 
  let (x1,x2,x3) = x in 
  let (y1,y2,y3) = y in 
  x1 < y1 || (x1 = y1 && x2 < y2) || (x1 = y1 && x2 = y2 && x3 < y3) 


(* earliest date *)

let rec earliest (xs : date list) : date option = 
  match xs with 
  | [] -> None
  | h :: t -> match earliest t with
    | None -> Some h
    | Some h1 -> Some (if is_before h1 h then h1 else h)

(* assoc list *)

let insert k v lst = (k, v) :: lst
let rec lookup k = function
| [] -> None
| (k', v) :: t -> if k = k' then Some v else lookup k t

let mp = insert 1 "one" (insert 2 "two" (insert 3 "three" []))
let ck2 = lookup 2 mp
let ck4 = lookup 4 mp

(* cards *)

type suit = Hearts | Spades | Clubs | Diamonds
type rank = Number of int | Ace | Jack | Queen | King 
type card = {suit : suit; rank : rank}

(* quadrant *)

type quad = I | II | III | IV 
type sign = Neg | Zero | Pos 

let sign (x : int) : sign = 
  if x = 0 then Zero else if x > 0 then Pos else Neg

let quadrant (point : int * int) : quad option = 
  let (x, y) = point in 
  match sign x, sign y with
  | Pos, Pos -> Some I 
  | Neg, Pos -> Some II 
  | Neg, Neg -> Some III 
  | Pos, Neg -> Some IV 
  | _ -> None 

let quadrant_when (point : int * int) : quad option = 
  let (x, y) = point in
  match x, y  with 
  | x, y when x > 0 && y > 0 -> Some I
  | x, y when x < 0 && y > 0 -> Some II 
  | x, y when x < 0 && y < 0 -> Some III 
  | x, y when x > 0 && y < 0 -> Some IV 
  | _ -> None 

(* depth *)

type 'a tree = Nil | Node of 'a * 'a tree * 'a tree

let rec depth (tree : 'a tree) : int = 
match tree with 
| Nil -> 0
| Node (_, l, r) -> max (1 + depth l) (1 + depth r)

(* shape *)
let rec shape (a : 'a tree) (b : 'a tree) : bool = 
match a, b with
| Nil, Nil -> true
| Node (_, l1, r1) , Node (_, l2, r2) -> shape l1 l2 && shape r1 r2
| _ -> false

(* list max exn *)
let rec list_max = function
| [] -> failwith "empty"
| h :: [] -> h
| h :: t -> max h @@ list_max t

(* list max exn string *)
let list_max_string (xs : int list) : string = 
match xs with 
| [] -> "empty"
| _ -> string_of_int @@ list_max xs

(* is_bst *)
let is_bst : ('a * 'b) tree -> bool = fun xs -> 
  failwith "TODO"