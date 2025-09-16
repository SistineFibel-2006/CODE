--- @diagnostic disable: unused-function
local function pri(fmt,...)
    return io.write(string.format(fmt, ...))
end

local function II() --读单个数字
    return io.read("*num")
end

local function LI() --读一整行
    return io.read("l")
end

local function MSI() --读取一行的所有字符串并放入赋值的表内
    local words = {}
    for word in io.read("*l"):gmatch("%S+") do
        table.insert(words, word)
    end
    return words
end

local function quickSort(arr, left, right)
    left = left or 1
    right = right or #arr
    if left >= right then return end

    -- 分区操作（核心逻辑）
    local pivot = arr[math.floor((left + right) / 2)]  -- 取中间值作基准
    local i, j = left, right
    while i <= j do
        while arr[i] < pivot do i = i + 1 end  -- 左指针右移
        while arr[j] > pivot do j = j - 1 end  -- 右指针左移
        if i <= j then
            arr[i], arr[j] = arr[j], arr[i]   -- 交换不满足条件的元素
            i, j = i + 1, j - 1
        end
    end

    -- 递归排序子分区
    quickSort(arr, left, j)
    quickSort(arr, i, right)
end


