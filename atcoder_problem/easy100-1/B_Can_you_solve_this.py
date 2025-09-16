
standard_input, packages, output_together = 1, 1, 0
dfs, hashing, read_from_file = 0, 0, 0
de = 1



if 1: 
    # ==================== ����������� ====================
    if standard_input:  # �Ƿ����ñ�׼�������
        import io, os, sys
        input = lambda: sys.stdin.readline().strip()  # �滻ԭ��input���ٶ�����3-5��

        import math
        inf = math.inf  # �������޴��������ڳ�ʼ����ֵ��

        def I():
            """��ȡһ���ַ������Զ�ȥ����β�ո�
            ����: str
            ʾ��: ���� "  hello " �� ���� "hello"
            """
            return input()
        
        def II():
            """��ȡ��������
            ����: int
            ʾ��: ���� "123" �� ���� 123
            """
            return int(input())
 
        def MII():
            """��ȡ�������������map����
            ����: map(int, ...)
            ʾ��: ���� "1 2 3" �� ���� map(1, 2, 3)
            """
            return map(int, input().split())
 
        def LI():
            """��ȡһ���ַ��������ո�ָ���б�
            ����: List[str]
            ʾ��: ���� "a b c" �� ���� ['a', 'b', 'c']
            """
            return input().split()
 
        def LII():
            """��ȡһ�������������б�
            ����: List[int]
            ʾ��: ���� "1 2 3" �� ���� [1, 2, 3]
            """
            return list(map(int, input().split()))
 
        def LFI():
            """��ȡһ�и������������б�
            ����: List[float]
            ʾ��: ���� "1.1 2.2" �� ���� [1.1, 2.2]
            """
            return list(map(float, input().split()))
 
        def GMI():
            """��ȡ���������ȫ����1��תΪ0-based������
            ����: map(int, ...)
            ʾ��: ���� "1 2 3" �� ���� map(0, 1, 2)
            """
            return map(lambda x: int(x) - 1, input().split())
 
        def LGMI():
            """��ȡһ��������ȫ����1�������б�
            ����: List[int]
            ʾ��: ���� "1 2 3" �� ���� [0, 1, 2]
            """
            return list(map(lambda x: int(x) - 1, input().split()))


    # ==================== ������Ԥ���� ====================
    if packages:  # �Ƿ�Ԥ�����㷨��
        from io import BytesIO, IOBase  # ������IO����
        import random  # ���������
        import os  # ϵͳ·������
        import bisect  # ���ֲ���ģ��
        import typing  # ����ע��
        from collections import Counter, defaultdict, deque  # ��Ƶ���ݽṹ
        from copy import deepcopy  # ���
        from functools import cmp_to_key, lru_cache, reduce  # �߽׺�������
        from heapq import merge, heapify, heappop, heappush, heappushpop  # �Ѳ���
        from itertools import accumulate, combinations, permutations  # ��������
        from operator import add, iand, ior, itemgetter, mul, xor  # ���������
        from string import ascii_lowercase, ascii_uppercase  # ��ĸ����
        BUFSIZE = 4096  # ���뻺������С


    # ==================== ������� ====================
    if output_together:  # �Ƿ������������
        class FastIO(IOBase):  # ����IOʵ����
            newlines = 0  # ���з�����

            def __init__(self, file):
                self._fd = file.fileno()  # �ļ�������
                self.buffer = BytesIO()  # �����ƻ�����
                self.writable = "x" in file.mode or "r" not in file.mode
                self.write = self.buffer.write if self.writable else None

            def read(self):
                """��ȡ���ݵ�������"""
                while True:
                    b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
                    if not b: break
                    ptr = self.buffer.tell()
                    self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
                self.newlines = 0
                return self.buffer.read()

            def readline(self):
                """���ж�ȡ"""
                while self.newlines == 0:
                    b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
                    self.newlines = b.count(b"\n") + (not b)
                    ptr = self.buffer.tell()
                    self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
                self.newlines -= 1
                return self.buffer.readline()

            def flush(self):
                """ˢ�»�����"""
                if self.writable:
                    os.write(self._fd, self.buffer.getvalue())
                    self.buffer.truncate(0), self.buffer.seek(0)

        class IOWrapper(IOBase):
            """IO��װ�ࣨ�����ı�ģʽ��"""
            def __init__(self, file):
                self.buffer = FastIO(file)
                self.flush = self.buffer.flush
                self.writable = self.buffer.writable
                self.write = lambda s: self.buffer.write(s.encode("ascii"))
                self.read = lambda: self.buffer.read().decode("ascii")
                self.readline = lambda: self.buffer.readline().decode("ascii")

        sys.stdout = IOWrapper(sys.stdout)  # �滻��׼���


    # ==================== �ݹ��Ż� ====================
    if dfs:  # �Ƿ����õݹ�ת����
        from types import GeneratorType

        def bootstrap(f, stk=[]):
            """�ݹ�ת����װ����
            ����:
                f: ��Ҫ�Ż��ĵݹ麯��
                stk: ����ջ���ڲ�ʹ�ã�
            �÷�:
                @bootstrap
                def dfs(u):
                    res = yield dfs(v)
                    yield res
            """
            def wrappedfunc(*args, **kwargs):
                if stk:  # ������е���ջ
                    return f(*args, **kwargs)
                else:   # �״ε���
                    to = f(*args, **kwargs)
                    while True:
                        if type(to) is GeneratorType:  # ���������ݹ����
                            stk.append(to)
                            to = next(to)
                        else:                         # ��ֵͨ������
                            stk.pop()
                            if not stk: break
                            to = stk[-1].send(to)
                    return to
            return wrappedfunc


    # ==================== ��ϣ�Ż� ====================
    if hashing:  # �Ƿ����ù�ϣ�����
        RANDOM = random.getrandbits(20)  # 20λ�������

        class Wrapper(int):
            """�Զ����ϣ�ࣨ��ֹ��ϣ��ײ��
            �÷�:
                d = defaultdict(int)
                d[Wrapper(x)] = 1
            """
            def __init__(self, x):
                int.__init__(x)

            def __hash__(self):
                return super(Wrapper, self).__hash__() ^ RANDOM  # ����������


    # ==================== �ļ����� ====================
    if read_from_file:  # �Ƿ���ļ���ȡ
        file = open("input.txt", "r").readline().strip()[1:-1]  # ��ȡ�����ļ�·��
        fin = open(file, 'r')  # �������ļ�
        input = lambda: fin.readline().strip()  # �ض������뺯��
        output_file = open("output.txt", "w")  # ������ļ�

        def fprint(*args, **kwargs):
            """�ļ���ӡ����
            �÷�:
                fprint("���:", ans)  # д��output.txt
            """
            print(*args, **kwargs, file=output_file)


    # ==================== ���Թ��� ====================
    if de:  # �Ƿ����õ���ģʽ
        def debug(*args, **kwargs):
            """��ɫ�����������ɫ���壩
            �÷�:
                debug("��ǰ�ڵ�:", u, "����:", dist[u])
            """
            print('\033[92m', end='')  # ������ɫ
            print(*args, **kwargs)
            print('\033[0m', end='')   # �ָ�Ĭ��


    # ==================== ʵ�ú��� ====================
    fmax = lambda x, y: x if x > y else y  # ���ֵ����
    fmin = lambda x, y: x if x < y else y  # ��Сֵ����


    # ==================== ��ʽǰ���� ====================
    class lst_lst:
        """ͼ���ڽӱ�洢���ռ��Ż���
        ����:
            n: �ڵ�������0-based��
        ����:
            append(i, j): ��ӱ�i��j
            iterate(i): �����ڵ�i���ھ�
        """
        def __init__(self, n) -> None:
            self.n = n  # �ڵ���
            self.pre = []  # ǰ��������
            self.cur = []  # Ŀ��ڵ��б�
            self.notest = [-1] * (n + 1)  # ͷָ������

        def append(self, i, j):
            """��ӱ�i��j
            ����:
                i: ��㣨0-based��
                j: �յ�
            """
            self.pre.append(self.notest[i])  # ��ǰ��ָ��ǰ����
            self.notest[i] = len(self.cur)   # ����ͷָ��
            self.cur.append(j)               # �洢Ŀ��ڵ�

        def iterate(self, i):
            """�����ڵ�i���ھӣ���������
            �÷�:
                for v in graph.iterate(u):
                    print(v)
            """
            tmp = self.notest[i]  # �ӵ�һ���߿�ʼ
            while tmp != -1:      # ��������
                yield self.cur[tmp]  # �����ھ�
                tmp = self.pre[tmp]  # �ƶ���ǰ����


