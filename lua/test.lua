
do
    local a = io.read("n")
    local arr = {}

    local ans = 0
    for i = 1, a do
        arr[i] = io.read("n")
        if i & 1 == 1 then
            ans = ans + arr[i]
        end
    end

    io.write(ans)
end

