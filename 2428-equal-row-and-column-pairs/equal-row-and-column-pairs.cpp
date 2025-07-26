class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> rows;
        
        for (int i = 0; i < grid.size(); i++) {
            auto ind = rows.find(grid[i]);
            if (ind == rows.end()) {
                rows.insert({grid[i], 1});
            } else {
                rows[grid[i]]++;
            }
        }

        int count = 0;

        for (int j = 0; j < grid.size(); j++) {
            vector<int> col{};
            for (int i = 0; i < grid.size(); i++) {
                col.push_back(grid[i][j]);
            }

            if (rows.find(col) != rows.end()) {
                count += rows[col];
            }
        }

        return count;
    }
};