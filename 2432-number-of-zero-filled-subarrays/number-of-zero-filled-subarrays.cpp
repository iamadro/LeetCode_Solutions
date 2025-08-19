class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int i = 0, n = nums.size();
        long long res = 0;

        while(i < n) {
            if (nums[i] == 0) {
                long long count = 0;
                while (i < n && nums[i] == 0) {
                    count++;
                    i++;
                }
                res += count * (count + 1) / 2;
            }
            i++;
        }

        return res;
    }
};