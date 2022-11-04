#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0)); // 使用vector定义一个二维数组
        int startx = 0, starty = 0; // 定义每循环一个圈的起始位置
        int loop = n / 2; // 每个圈循环几次，例如n为奇数3，那么loop = 1 只是循环一圈，矩阵中间的值需要单独处理
        int mid = n / 2; // 矩阵中间的位置，例如：n为3， 中间的位置就是(1，1)，n为5，中间位置为(2, 2)
        int count = 1; // 用来给矩阵中每一个空格赋值
        int offset = 1; // 需要控制每一条边遍历的长度，每次循环右边界收缩一位
        int i,j;
        while (loop --) {
            i = startx;
            j = starty;

            // 下面开始的四个for就是模拟转了一圈
            // 模拟填充上行从左到右(左闭右开)
            for (j = starty; j < n - offset; j++) {
                res[startx][j] = count++;
            }
            // 模拟填充右列从上到下(左闭右开)
            for (i = startx; i < n - offset; i++) {
                res[i][j] = count++;
            }
            // 模拟填充下行从右到左(左闭右开)
            for (; j > starty; j--) {
                res[i][j] = count++;
            }
            // 模拟填充左列从下到上(左闭右开)
            for (; i > startx; i--) {
                res[i][j] = count++;
            }

            // 第二圈开始的时候，起始位置要各自加1， 例如：第一圈起始位置是(0, 0)，第二圈起始位置是(1, 1)
            startx++;
            starty++;

            // offset 控制每一圈里每一条边遍历的长度
            offset += 1;
        }

        // 如果n为奇数的话，需要单独给矩阵最中间的位置赋值
        if (n % 2) {
            res[mid][mid] = count;
        }

         for (int i = 0; i < n * n; i++)
        {
            cout << &res[i] << endl;
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution soluton;
    int n = 3;
    vector<vector<int>> res = soluton.generateMatrix(n);
    cout << "---------------------------------" << endl;
    for (int i = 0; i < n * n; i++)
    {
        cout << &res[i] << endl; //Vector存放在栈区，函数返回的Vector是右值，接收右值会调用移动语义，移动语义会修改对象所有权。因此栈内的数据没有随着函数结束被销毁，而是所有权发生了变更。
        // https://blog.51cto.com/u_15357586/3784791
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout.width(4);
            cout << res[i][j] << " ";
        }
        cout << endl;
        
    }

     res = soluton.generateMatrix(n); //两次打印的结果地址不相同
    cout << "---------------------------------" << endl;
    for (int i = 0; i < n * n; i++)
    {
        cout << &res[i] << endl; 

    return 0;
}
