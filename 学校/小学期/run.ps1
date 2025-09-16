$f = $args[0]  # 从命令行参数获取文件名
g++ -std=c++17 -O2 -o $f "$f.cpp"
Get-Content "$f.in" | & ".\$f.exe"
