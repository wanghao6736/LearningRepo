/* 中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
 * 自测 - 5 Shuffling Machine
 * wanghao 2022.08.16
 */
#include <iostream>
#include <string>
using namespace std;
/*
 * @details         按给定的顺序重复打乱一副扑克牌
 * @param order     包含打乱顺序的数组
 * @param ret_order 保存最终牌顺的数组
 * @param len       数组的长度，即 54
 * @param n         重复打乱的次数
 * @retval          无
 */
void shuffle(int* order, int* ret_order, int len, int n)
{
    int new_order[len] = {0};   // 用于保存新牌序

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < len; j++) // 打乱牌序
            if (i == 0) // 首次打乱时，原牌序为 0, 1 ··· 52, 53
                new_order[order[j] - 1] = j;
            else // 非首次打乱时，上一次打乱后的牌序保存在 ret_order 中
                new_order[order[j] - 1] = ret_order[j];

        for (int k = 0; k < len; k++) // 将打乱后的牌序保存
            ret_order[k] = new_order[k];
    }
}

int main()
{
    int n = 0;
    cin >> n; // 输入打乱次数

    char clrs[] = {'S', 'H', 'C', 'D', 'J'};
    int order[] = {
        36,52,37,38,3,39,40,53,54,41,11,12,13,42,43,44,2,4,23,24,25,26,27,6,7,8,48,49,
        50,51,9,10,14,15,16,5,17,18,19,1,20,21,22,28,29,30,31,32,33,34,35,45,46,47
        };
    int len = sizeof(order) / sizeof(int);
    int ret_order[len] = {0};

    for (int i = 0; i < len; i++) // 输入打乱顺序
        cin >> order[i];

    shuffle(order, ret_order, len, n);

    for (int i = 0; i < len; i++) // 输出打乱后的牌
    {
        int carry = ret_order[i] / 13; // 花色
        int val = ret_order[i] % 13;   // 大小
        
        cout << clrs[carry] << val + 1;
        if (i != len - 1)
            cout << ' ';
    }
    return 0;
}