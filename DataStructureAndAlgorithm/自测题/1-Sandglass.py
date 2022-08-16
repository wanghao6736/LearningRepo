"""
中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
自测 - 1 打印沙漏
wanghao 2022.08.16
"""
# parse input
s = input().split(' ')
nin, sin = eval(s[0]), s[1]
# get depth
depth, nuse = 1, 1
while nuse < nin:
    depth += 1
    nuse = 2*depth*depth - 1

if nuse > nin:
    depth -= 1
    nuse = 2*depth*depth - 1
# print result
for i in range(depth):
    num = 2 * (depth - i) - 1
    print(' ' * i + sin * num)

for i in range(2, depth + 1):
    num = 2 * i - 1
    print(' ' * (depth - i) + sin * num)

print(nin - nuse, end='')