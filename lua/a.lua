--- @diagnostic disable: unused-function

local function pri(fmt,...)
    return io.write(string.format(fmt, ...))
end

local function II() --����������
    return io.read("*num")
end

local function LI() --��һ����
    return io.read("l")
end

local function MSI() --��ȡһ�е������ַ��������븳ֵ�ı���
    local words = {}
    for word in io.read("*l"):gmatch("%S+") do
        table.insert(words, word)
    end
    return words
end



local t = {}
for i = 1, 13 do
  t[i] = 0
end
for _ = 1, 7 do
  local a = II()
  t[a] = t[a] + 1
end
for i = 1, 13 do
  for j = 1, 13 do
    if i ~= j and 3 <= t[i] and 2 <= t[j] then
      print("Yes")
      os.exit()
    end
  end
end
print("No")

