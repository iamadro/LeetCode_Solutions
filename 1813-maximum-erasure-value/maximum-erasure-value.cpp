class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), best = nums[0], cur = 0, currSum = 0;
        map<int, int> prev;

        // prev.insert({nums[0], 0});

        for (int i = 0; i < n; i++) {
            if (prev.find(nums[i]) == prev.end()) {
                prev.insert({nums[i], i});
                currSum += nums[i];
            } else {
                int prev_ind = prev[nums[i]];
                prev[nums[i]] = i;
                
                if (prev_ind >= cur) {
                    for (int j = cur; j <= prev_ind; j++) {
                        currSum -= nums[j];   
                    }
                    cur = prev_ind + 1;
                }
                currSum += nums[i];
            }
            best = max(best, currSum);
        }

        return best;
    }
};