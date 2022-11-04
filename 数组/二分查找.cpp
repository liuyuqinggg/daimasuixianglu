#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        // int right = nums.size(); //如果这样设置右边界， 则下面的区间设置将不同， https://programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html#%E6%80%9D%E8%B7%AF

        while(left <= right){
            int middle = left + (right - left) / 2;
            if(nums[middle] < target){
                left = middle + 1;
            }else if(nums[middle] > target){
                right = middle - 1;
            }else{
                return middle;
            }
        }
        return -1;
    }
};

int main(int argc, char const *argv[])
{
    vector<int> test1 = {-1,0,3,5,9,12};
    vector<int> test2 = {-1,0,3,5,9,12};
    Solution solution;
    cout << solution.search(test1 , 9) << endl;
    cout << solution.search(test2 , 2) << endl;
    return 0;
}
