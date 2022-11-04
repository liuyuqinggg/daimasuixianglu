#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += (2 * k)) {
            // 1. 每隔 2k 个字符的前 k 个字符进行反转
            // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
            if (i + k <= s.size()) {
                reverse(s.begin() + i, s.begin() + i + k );
            } else {
                // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;

    cout << solution.reverseStr("abcdefg",2) << endl;
    cout << solution.reverseStr("abcdefghijklmn",3) << endl;
    cout << solution.reverseStr("abcd",2) << endl;
    return 0;
}
