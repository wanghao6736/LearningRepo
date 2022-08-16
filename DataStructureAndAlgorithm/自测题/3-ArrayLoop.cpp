/* 中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
 * 自测 - 3 数组元素循环右移问题
 * wanghao 2022.08.16
 */
#include <iostream>
using namespace std;

int main()
{
    int n=0, m=0;   // 数组元素个数、右移位数
    cin >> n >> m;
    m %= n;     // 处理 m >= n 的情况

    int str[n]; // 数组声明需要在上一个 cin 之后，否则输入数组不正确
    for (int i = 0; i < n; i++) // 输入数组
        cin >> str[i];

    for (int i = m; i > 0; i--) // 先输出右移部分
    {
        cout << str[n - i];
        if (i != 1) // 最后一位不输出空格
            cout << " ";
    }

    for (int i = 0; i < n - m; i++) // 再输出剩余部分
    {
        if (!(m == 0 && i == 0)) // 仅无需右移时的第一位前不输出空格
            cout << " ";
        cout << str[i];
    }
    return 0;
}