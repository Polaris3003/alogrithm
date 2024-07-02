//给你一个整数数组 nums。 
//
// 返回两个（不一定不同的）质数在 nums 中 下标 的 最大距离。 
//
// 
//
// 示例 1： 
//
// 
// 输入： nums = [4,2,9,5,3] 
// 
//
// 输出： 3 
//
// 解释： nums[1]、nums[3] 和 nums[4] 是质数。因此答案是 |4 - 1| = 3。 
//
// 示例 2： 
//
// 
// 输入： nums = [4,8,2,8] 
// 
//
// 输出： 0 
//
// 解释： nums[2] 是质数。因为只有一个质数，所以答案是 |2 - 2| = 0。 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 3 * 10⁵ 
// 1 <= nums[i] <= 100 
// 输入保证 nums 中至少有一个质数。 
// 
//
// Related Topics 数组 数学 数论 👍 19 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool check(int num) {
        if(num == 1)
            return false;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while(!check(nums[l])) {
            l++;
        }
        while(!check(nums[r])) {
            r--;
        }
        return r - l;
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    return 0;
}