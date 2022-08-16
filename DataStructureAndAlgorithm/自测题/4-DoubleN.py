"""
中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
自测 - 4 Have Fun with Numbers
wanghao 2022.08.16
"""
# s = input()
s = "1234567899"
n = eval(s)
ret = 2*n

l1 = [c for c in s]
l2 = [c for c in str(ret)]
l1.sort()
l2.sort()

print('Yes') if l1 == l2 else print('No')
print(ret)
