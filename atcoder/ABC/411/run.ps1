$f = $args[0]  # 从命令行参数获取文件名
g++ -std=c++2a -O2 -Wall -Wshadow -D_GLIBCXX_DEBUG_PEDANTIC -o $f "$f.cpp"
Get-Content "$f.in" | & ".\$f.exe"
