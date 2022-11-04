#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int arr[2][3] = {{1,2,3},{4,5,6}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << &arr[i][j] << endl;//数组中的元素是存储在连续地址上的
            // 0x7fffbf46a660
            // 0x7fffbf46a664
            // 0x7fffbf46a668
            // 0x7fffbf46a66c
            // 0x7fffbf46a670
            // 0x7fffbf46a674
        }        
    }
    

    return 0;
}
