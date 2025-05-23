#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <iterator>
using namespace std;
// 四数之和  延续三数之和的想法
// 先写一个三数之和--利用三数之和求四数之和
class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        //vector<vector<int>> res;
        long sum;
        int t;
        int left;
        int right;
        if (nums.size() < 4)
        {
            return result;
        }
        sort(nums.begin(), nums.end()); // 第一步排序
        for (size_t i = 0; i < nums.size() - 3; i++)//固定第一个元素
        {
            // if (nums[i]>target)
            // {
            //     break;
            // }
            if (i>0&&nums[i] == nums[i - 1])//去重
            {
                continue;
            }
            for (size_t j = i+1; j < nums.size() - 2; j++)//固定第二个元素
            {
                if (j>i+1&&nums[j] == nums[j - 1])//去重
                {
                    continue;
                }
                left = j + 1;
                right = nums.size() - 1;
                while (left < right)
                {
                    sum = nums[i]+nums[j] + nums[left] + nums[right];
                    if (sum < target)
                    {
                        left++;
                    }
                    else if (sum > target)
                    {
                        right--;
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) // 去重
                        {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right - 1]) // 去重
                        {
                            right--;
                        }
                        left++;
                        right--;
                    }
                
                }              
            } 
        }     
        return result;
    }
};

void test01()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    Solution s;
    vector<vector<int>> res = s.fourSum(nums, 0);
    for_each(res.begin(), res.end(), [](vector<int> val) { cout << val[0] << " " << val[1] << " " << val[2] <<" "<<val[3]<< endl; });
}
int main()
{
    test01();
    system("pause");
    return EXIT_SUCCESS;
}