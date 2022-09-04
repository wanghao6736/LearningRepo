/* 中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
 * 自测 - 4 Have Fun with Numbers
 * wanghao 2022.08.16
 */
#include <iostream>
#include <string>
using namespace std;
/*
 * @details   判断两个数组所含元素是否相同，忽略元素顺序
 * @param d1  数组 1，原始数组
 * @param d2  数组 2，结果数组，首位为进位，不比较
 * @param len 原始数组长度
 * @retval    相同元素的个数等于原始数组长度则返回 true
 */
bool is_equal(int* d1, int* d2, int len)
{
    int count = 0; // 相同的元素个数
    for (int i = 1; i < len + 1; i++)
        for (int j = 0; j < len; j++)
            if (d2[i] == d1[j])
            {
                d1[j] = -1; // 将原始数组中相同的值赋值 -1，避免重复比较
                count++;
                break;
            }
    return count == len;
}
/*
 * @details     对两个十进制以内的数进行乘法运算
 * @param num1  被乘数, 0-10
 * @param carry 进位, 0-10
 * @param num2  乘数, 0-10
 * @retval ret  积的余数, 0-10
 */
int bitMultiply(int num1, int &carry, int num2 = 2)
{
    int ret = num1 * num2 + carry;
    carry = ret / 10;
    return ret % 10;
}
/*
 * @details   对数字型字符串进行乘法运算
 * @param str 数字型字符串，如 "123456"
 * @param num 乘数，0-10
 * @retval    无
 */
void halfMultiply(string str, int num = 2){
    int n = str.length();
    int carry = 0, ret = 0;
    int ori_data[n] = {-1};      // 输入字符串
    int ret_data[n + 1] = {-1};  // 结果字符串

    for (int i = n - 1; i >= 0; i--)
    {
        int last = str[i] - '0'; // 获取末尾数字，并将字符转为数字

        ret = bitMultiply(last, carry, num); // 位乘
        ori_data[i] = last;
        ret_data[i + 1] = ret;
    }

    if (carry) // 最终进位不为 0，则输入数据与结果位数不一致
    {
        cout << "No" << endl;
        ret_data[0] = carry;
    }
    else{      // 最终进位为 0，需判断两数组内所含元素是否相同
        if (is_equal(ori_data, ret_data, n))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    for (int i = 0; i < n + 1; i++) // 输出计算结果
    {
        if (ret_data[i] == -1) // 最终进位为 0 时，不输出进位
            continue;
        cout << ret_data[i];
    }
}

int main()
{
    string str;
    str = "1234567899";
    // cin >> str;
    halfMultiply(str);

    return 0;
}