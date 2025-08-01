class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 1) {
            return {{1}};
        }

        vector<vector<int>> ans(numRows, vector<int>{});
        ans[0] = {1};
        
        for(int i = 1; i < numRows; i++) {
            vector<int> row = {1};
            if (i >= 2) {
                for (int j = 0; j < ans[i-1].size() - 1; j++) {
                    row.push_back(ans[i - 1][j] + ans[i - 1][j+1]);
                }
            }
            row.push_back(1);

            ans[i] = row;
        }

        return ans;
    }
};