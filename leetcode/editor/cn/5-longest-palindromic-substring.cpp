//给你一个字符串 s，找到 s 中最长的 回文 子串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "babad"
//输出："bab"
//解释："aba" 同样是符合题意的答案。
// 
//
// 示例 2： 
//
// 
//输入：s = "cbbd"
//输出："bb"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 仅由数字和英文字母组成 
// 
//
// Related Topics 双指针 字符串 动态规划 👍 7259 👎 0


#include<bits/stdc++.h>

using namespace std;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 1) {
            return "";
        }
        string s1;
        for (int i = 0; i < n; i++) {
            s1 += "#";
            s1 += s[i];
        }
        s1 += "#";
        n = s1.size();
        int maxright=0,pos=0,maxrl=0,maxpos=0;
        int* RL = new int[n];
        memset(RL, 0, n * sizeof(int));
        for (int i = 0; i < n; i++) {
            if (i < maxright) {
                RL[i] = min(RL[2 * pos - i], maxright - i);
            } else {
                RL[i] = 1;
            }
            while (i - RL[i] >= 0 && i + RL[i] < n && s1[i-RL[i]] == s1[i + RL[i]]) {
                RL[i] += 1;
            }

            if (RL[i] + i - 1 > maxright) {
                maxright = RL[i] + i - 1;
                pos = i;
            }

            if (maxrl <= RL[i]) {
                maxrl = RL[i];
                maxpos = i;
            }
        }
        return s.substr((maxpos - maxrl + 1) / 2, maxrl - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)


int main() {
    Solution s;
    cout<<s.longestPalindrome("a");
    return 0;
}