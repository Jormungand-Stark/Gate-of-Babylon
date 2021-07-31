/*
请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
*/

class Solution { // set实现滑动窗口
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        set<char> set;
        int i = 0, length = 1;
        set.insert(s[i]);
        for(int j=1; j<s.size(); j++){
            while(set.find(s[j]) != set.end()) set.erase(s[i++]);
            length = max(length, j-i+1);
            set.insert(s[j]);
        }
        return length;
    }
};

class Solution { // vector实现滑动窗口
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        vector<int> ivec(127, 0);
        int i = 0, length = 1;
        ivec[s[i]] = 1;
        for(int j=1; j<s.size(); j++){
            while(ivec[s[j]]) ivec[s[i++]]=0;
            length = max(length, j-i+1);
            ivec[s[j]] = 1;
        }
        return length;
    }
};

class Solution { // map实现滑动窗口
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        map<char, int> map;
        int i = -1, res = 0;
        for(int j=0; j<s.size(); j++){
            if(map.find(s[j]) != map.end()) i = max(i, map[s[j]]);
            map[s[j]] = j;
            res = max(res, j-i);
        }
        return res;
    }
};

class Solution { // dp-hash，变量tmp保存动规数据，map辅助边界判断，res保存最大长度
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        map<char, int> map;
        int tmp = 0, res = 0;
        for(int j=0; j<s.size(); j++){
            int i = map.find(s[j])==map.end()?-1:map[s[j]];
            tmp = tmp < j-i? tmp+1:j-i; // dp[j-1]变为dp[j]
            res = max(res, tmp); // res与新出现的dp[j]谁更大？
            map[s[j]] = j;
        }
        return res;
    }
};
