class Solution {//无需动规数组
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], max = nums[0];
        for(int i=1; i<nums.size(); i++){
            sum = sum+nums[i]<nums[i]?nums[i]:sum+nums[i]; //更新sum
            max = sum>max?sum:max;//更新最大值
        }
        return max;
    }
};

class Solution {//动规数组
public:
    int maxSubArray(vector<int>& nums) {
        int max = nums[0];
        for(int i=1; i<nums.size(); i++){
            nums[i] += nums[i-1]<0?0:nums[i-1];
            max = max>nums[i]?max:nums[i];
        }
        return max;
    }
};
