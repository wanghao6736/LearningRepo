/* 中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
 * 自测 - 2 素数对猜想
 * wanghao 2022.08.16
 */
#include <iostream>
#include <cmath>
using namespace std;
/*
 * @details 判断一个数是否为素数
 * @param n 需要判断的正整数
 * @retval  是素数则返回 true
 */
bool is_prime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int num, count = 0; // 最大界限数、素数对个数
    // cin >> num;
    num = 1e5;
    int pre = 3;  // 保存前一个素数

    for (int i = 5; i <= num; i += 2)
    {
        if(is_prime(i))
        {
            if(i - pre == 2) // 满足条件的相邻素数对
                count++;
            pre = i;
        }
    }
    cout << count << endl;
    return 0;
}