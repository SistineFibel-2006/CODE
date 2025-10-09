
local function foo(x)
  if x == 1 then
    return 1;
  end
  return 2 * foo(x - 1)
end
--[[
local n = io.read("*n")
for _ = 1, n,1 do
  local t = io.read("*n");
  local flag = true;
  for i = math.sqrt(t-1), 2, -1 do
    if t % i == 0 then
      flag = false;
      break
    end
  end
  if t == 1 then
    flag = false;
  end
  if flag then
    print("YES")
  else 
    print("NO");
  end
end
--]]
print(foo(20))
