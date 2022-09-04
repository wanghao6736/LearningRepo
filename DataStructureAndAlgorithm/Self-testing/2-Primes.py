"""
中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
自测 - 2 素数对猜想
wanghao 2022.08.16
"""
def _odd_iter():  # 生成奇数序列
    n = 1
    while True:
        n = n + 2
        yield n

def _not_divisible(n):  # 定义筛选函数
    return lambda x: x % n > 0

def primes():  # 素数生成器
    yield 2
    it = _odd_iter() # 初始序列
    while True:
        n = next(it) # 返回序列的第一个数
        yield n
        it = filter(_not_divisible(n), it) # 构造新序列

# N = eval(input("input a number: "))
N = 1e5
count = 0
p1 = primes() # 素数序列
n1 = next(p1) # 获取第一个素数

for n2 in p1:
    # print(f"n1 = {n1}, n2 = {n2}")
    if n2 > N:
        break
    if n2 - n1 == 2:
        count += 1
    n1 = n2

print(count)