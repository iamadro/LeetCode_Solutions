class Solution {
private:
    int gap = 0;
    vector<vector<int>> memo;
    unordered_map<int, int> mp;

    bool jumps(unordered_set<int>& nums, int curr, const int &end, int k) {
        if (curr == end) {
            return true;
        }

        gap++;

        int ind = mp[curr];

        if (memo[ind][k] != -1) {
            return memo[ind][k] == 1 ? true : false;
        }

        bool opt1 = false, opt2 = false, opt3 = false;

        if (k > 0 && nums.find(curr + k) != nums.end()) opt1 = jumps(nums, curr + k, end, k);
        if (k - 1 > 0 && nums.find(curr + k - 1) != nums.end()) opt2 = jumps(nums, curr + k - 1, end, k - 1);
        if (nums.find(curr + k + 1) != nums.end()) opt3 = jumps(nums, curr + k + 1, end, k + 1);

        gap--;
        bool opt = opt1 || opt2 || opt3;
        
        memo[ind][k] = opt ? 1 : 2;

        return opt;
    }
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;

        int n = stones.size();
        memo.resize(n + 1, vector<int>(n + 1, -1));

        unordered_set<int> nums;
        for (int i = 0; i < stones.size(); i++) {
            nums.insert(stones[i]);
            mp.insert({stones[i], i});
        }

        return jumps(nums, 1, stones[stones.size() - 1], 1);
    }
};