class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int sum = 0, x;
        for(int i = 0; i < nums.size(); i++){
            if(!sum) x = nums[i];
            sum += nums[i]==x?1:-1;
        }
        
        int count = 0;
        for(int& num:nums)
            if(num==x) count++;
        return count>nums.size()/2?x:-1;
    }
};
