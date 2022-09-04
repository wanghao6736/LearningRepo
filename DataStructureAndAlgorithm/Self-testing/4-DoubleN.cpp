/* 中国大学 MOOC - 陈越、何钦铭-数据结构-起步能力自测题
 * 自测 - 4 Have Fun with Numbers
 * wanghao 2022.08.16
 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, ret_str;
    // cin >> str;
    str = "1234567899";
    long unsigned int num = std::stoi(str);
    long unsigned int ret = 2 * num;
    ret_str = std::to_string(ret);

    int n1 = str.length();
    int n2 = ret_str.length();
    bool flag = true;

    if (n1 != n2) // 位数不等
        flag = false;
    else{ // 位数相等，判断元素是否相同
        for (int i = 0; i < n1; i++)
            for (int j = 0; j < n1; j++)
                if (str[i] == ret_str[j])
                {
                    str[i] = ' ';
                    ret_str[j] = ' ';
                }
        if (str != ret_str)
            flag = false;
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    cout << ret << endl;
    return 0;
}