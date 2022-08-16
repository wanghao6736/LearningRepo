"""
中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
自测 - 3 数组元素循环右移问题
wanghao 2022.08.16
"""
# parse input
s = input().split(' ')
n, m = eval(s[0]), eval(s[1])
data = input().split(' ')
# print
m %= n
if m == 0:
    print(' '.join(data))
else:
    print(' '.join(data[-m:]) + ' ' + ' '.join(data[:n - m]))