class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count = 0;
        int down = -1, up = -1;

        for (int i = 0; i < nums.size() -1; i++) {
            if (nums[i] > nums[i+1]) {
                down = i;
            } else if (nums[i] < nums[i+1]) {
                up = i;
            }

            if (up != -1 && down != -1) {
                count++;
                if (up < down) up = -1;
                else down = -1;
            }
        }

        return count;
    }
};