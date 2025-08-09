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
        // memo.resize(nums.size(), -1);
        // return steal(nums, 0, nums.size() - 1);

        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> dp(n);
        dp[n-1] = nums[n-1];                    // 2
        dp[n-2] = max(nums[n-1], nums[n-2]);    // 2

        for (int i = n - 3; i > -1; i--) {
            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
        }

        return dp[0];
    }
};