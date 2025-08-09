class Solution {
private:
    vector<int> memo;

    int steal(vector<int>& nums, int start, int end) {
        if (start == end) return nums[end];
        if (start > end) return 0;

        if (memo[start] != -1) return memo[start];

        int amtSkip = 0, amtTake = 0;
        amtTake = nums[start] + steal(nums, start + 2, end);
        amtSkip = steal(nums, start + 1, end);

        memo[start] = max(amtTake, amtSkip); 

        return memo[start];
    }


public:
    int rob(vector<int>& nums) {
        memo.resize(nums.size(), -1);
        return steal(nums, 0, nums.size() - 1);
    }
};