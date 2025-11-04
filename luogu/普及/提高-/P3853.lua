---@diagnostic disable: lowercase-global
n=io.read("n")
m=io.read("*n")
a={}
for i=1 , n do
    a[i]=io.read("n")
end
l=a[1]
r=a[n]
for x=1,m do
    b=io.read("n")
    mid=(a[l]+a[r])/2
    if a[mid] >=b then
        r=mid
    else
        l=mid+1
    end
    if a[l]==b then
        print(l)
    elseif a[r]==b then
        print(r)
    elseif a[mid]==b then
        print(mid)
    end
end