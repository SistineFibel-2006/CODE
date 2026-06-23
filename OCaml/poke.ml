(* 宝可梦类型 *)
type ptype = Nor | Fir | Wat 
(* 攻击效果 *)
type peff = Norm | Notv | Supe

let mult_of_eff = function
  | Norm -> 1. 
  | Notv -> 0.5
  | Supe -> 2. 

let eff' = function
  | (Fir, Fir) | (Wat, Wat) | (Fir, Wat)
  -> Notv
  | (Wat, Fir) -> Supe
  | _ -> Norm

let eff x y = eff' (x, y)

type mon = {
  name : string;
  hp : int;
  ptype: ptype;
}

