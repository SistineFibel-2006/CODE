
standard_input, packages, output_together = 1, 1, 0
dfs, hashing, read_from_file = 0, 0, 0
de = 1



if 1: 
    # ==================== 输入输出加速 ====================
    if standard_input:  # 是否启用标准输入加速
        import io, os, sys
        input = lambda: sys.stdin.readline().strip()  # 替换原生input，速度提升3-5倍

        import math
        inf = math.inf  # 定义无限大常量（用于初始化最值）

        def I():
            """读取一行字符串（自动去除首尾空格）
            返回: str
            示例: 输入 "  hello " → 返回 "hello"
            """
            return input()
        
        def II():
            """读取单个整数
            返回: int
            示例: 输入 "123" → 返回 123
            """
            return int(input())
 
        def MII():
            """读取多个整数，返回map对象
            返回: map(int, ...)
            示例: 输入 "1 2 3" → 返回 map(1, 2, 3)
            """
            return map(int, input().split())
 
        def LI():
            """读取一行字符串并按空格分割成列表
            返回: List[str]
            示例: 输入 "a b c" → 返回 ['a', 'b', 'c']
            """
            return input().split()
 
        def LII():
            """读取一行整数并返回列表
            返回: List[int]
            示例: 输入 "1 2 3" → 返回 [1, 2, 3]
            """
            return list(map(int, input().split()))
 
        def LFI():
            """读取一行浮点数并返回列表
            返回: List[float]
            示例: 输入 "1.1 2.2" → 返回 [1.1, 2.2]
            """
            return list(map(float, input().split()))
 
        def GMI():
            """读取多个整数并全部减1（转为0-based索引）
            返回: map(int, ...)
            示例: 输入 "1 2 3" → 返回 map(0, 1, 2)
            """
            return map(lambda x: int(x) - 1, input().split())
 
        def LGMI():
            """读取一行整数并全部减1（返回列表）
            返回: List[int]
            示例: 输入 "1 2 3" → 返回 [0, 1, 2]
            """
            return list(map(lambda x: int(x) - 1, input().split()))


    # ==================== 依赖库预加载 ====================
    if packages:  # 是否预加载算法库
        from io import BytesIO, IOBase  # 二进制IO操作
        import random  # 随机数生成
        import os  # 系统路径操作
        import bisect  # 二分查找模块
        import typing  # 类型注解
        from collections import Counter, defaultdict, deque  # 高频数据结构
        from copy import deepcopy  # 深拷贝
        from functools import cmp_to_key, lru_cache, reduce  # 高阶函数工具
        from heapq import merge, heapify, heappop, heappush, heappushpop  # 堆操作
        from itertools import accumulate, combinations, permutations  # 迭代工具
        from operator import add, iand, ior, itemgetter, mul, xor  # 运算符加速
        from string import ascii_lowercase, ascii_uppercase  # 字母常量
        BUFSIZE = 4096  # 输入缓冲区大小


    # ==================== 输出加速 ====================
    if output_together:  # 是否启用输出缓冲
        class FastIO(IOBase):  # 快速IO实现类
            newlines = 0  # 换行符计数

            def __init__(self, file):
                self._fd = file.fileno()  # 文件描述符
                self.buffer = BytesIO()  # 二进制缓冲区
                self.writable = "x" in file.mode or "r" not in file.mode
                self.write = self.buffer.write if self.writable else None

            def read(self):
                """读取数据到缓冲区"""
                while True:
                    b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
                    if not b: break
                    ptr = self.buffer.tell()
                    self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
                self.newlines = 0
                return self.buffer.read()

            def readline(self):
                """逐行读取"""
                while self.newlines == 0:
                    b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
                    self.newlines = b.count(b"\n") + (not b)
                    ptr = self.buffer.tell()
                    self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
                self.newlines -= 1
                return self.buffer.readline()

            def flush(self):
                """刷新缓冲区"""
                if self.writable:
                    os.write(self._fd, self.buffer.getvalue())
                    self.buffer.truncate(0), self.buffer.seek(0)

        class IOWrapper(IOBase):
            """IO包装类（兼容文本模式）"""
            def __init__(self, file):
                self.buffer = FastIO(file)
                self.flush = self.buffer.flush
                self.writable = self.buffer.writable
                self.write = lambda s: self.buffer.write(s.encode("ascii"))
                self.read = lambda: self.buffer.read().decode("ascii")
                self.readline = lambda: self.buffer.readline().decode("ascii")

        sys.stdout = IOWrapper(sys.stdout)  # 替换标准输出


    # ==================== 递归优化 ====================
    if dfs:  # 是否启用递归转迭代
        from types import GeneratorType

        def bootstrap(f, stk=[]):
            """递归转迭代装饰器
            参数:
                f: 需要优化的递归函数
                stk: 调用栈（内部使用）
            用法:
                @bootstrap
                def dfs(u):
                    res = yield dfs(v)
                    yield res
            """
            def wrappedfunc(*args, **kwargs):
                if stk:  # 如果已有调用栈
                    return f(*args, **kwargs)
                else:   # 首次调用
                    to = f(*args, **kwargs)
                    while True:
                        if type(to) is GeneratorType:  # 生成器→递归调用
                            stk.append(to)
                            to = next(to)
                        else:                         # 普通值→回溯
                            stk.pop()
                            if not stk: break
                            to = stk[-1].send(to)
                    return to
            return wrappedfunc


    # ==================== 哈希优化 ====================
    if hashing:  # 是否启用哈希随机化
        RANDOM = random.getrandbits(20)  # 20位随机种子

        class Wrapper(int):
            """自定义哈希类（防止哈希碰撞）
            用法:
                d = defaultdict(int)
                d[Wrapper(x)] = 1
            """
            def __init__(self, x):
                int.__init__(x)

            def __hash__(self):
                return super(Wrapper, self).__hash__() ^ RANDOM  # 混合随机种子


    # ==================== 文件输入 ====================
    if read_from_file:  # 是否从文件读取
        file = open("input.txt", "r").readline().strip()[1:-1]  # 读取输入文件路径
        fin = open(file, 'r')  # 打开输入文件
        input = lambda: fin.readline().strip()  # 重定向输入函数
        output_file = open("output.txt", "w")  # 打开输出文件

        def fprint(*args, **kwargs):
            """文件打印函数
            用法:
                fprint("结果:", ans)  # 写入output.txt
            """
            print(*args, **kwargs, file=output_file)


    # ==================== 调试工具 ====================
    if de:  # 是否启用调试模式
        def debug(*args, **kwargs):
            """彩色调试输出（绿色字体）
            用法:
                debug("当前节点:", u, "距离:", dist[u])
            """
            print('\033[92m', end='')  # 设置绿色
            print(*args, **kwargs)
            print('\033[0m', end='')   # 恢复默认


    # ==================== 实用函数 ====================
    fmax = lambda x, y: x if x > y else y  # 最大值函数
    fmin = lambda x, y: x if x < y else y  # 最小值函数


    # ==================== 链式前向星 ====================
    class lst_lst:
        """图的邻接表存储（空间优化）
        参数:
            n: 节点数量（0-based）
        方法:
            append(i, j): 添加边i→j
            iterate(i): 遍历节点i的邻居
        """
        def __init__(self, n) -> None:
            self.n = n  # 节点数
            self.pre = []  # 前驱边索引
            self.cur = []  # 目标节点列表
            self.notest = [-1] * (n + 1)  # 头指针数组

        def append(self, i, j):
            """添加边i→j
            参数:
                i: 起点（0-based）
                j: 终点
            """
            self.pre.append(self.notest[i])  # 当前边指向前驱边
            self.notest[i] = len(self.cur)   # 更新头指针
            self.cur.append(j)               # 存储目标节点

        def iterate(self, i):
            """遍历节点i的邻居（生成器）
            用法:
                for v in graph.iterate(u):
                    print(v)
            """
            tmp = self.notest[i]  # 从第一条边开始
            while tmp != -1:      # 遍历链表
                yield self.cur[tmp]  # 返回邻居
                tmp = self.pre[tmp]  # 移动到前驱边


