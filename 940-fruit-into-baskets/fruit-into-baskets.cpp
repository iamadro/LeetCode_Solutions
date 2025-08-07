class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> counts;
        int count = 0, maxCount = 0, left = 0;

        for (int i = 0; i < fruits.size(); i++) {
            if (counts.find(fruits[i]) == counts.end()) {
                counts.insert({fruits[i], 1});
            } else {
                counts[fruits[i]]++;
            }
            count++;

            if (counts.size() > 2) {
                while (counts.size() > 2) {
                    if (--counts[fruits[left]] == 0) {
                        counts.erase(fruits[left]);
                    }
                    left++;
                    count--;
                }
            }

            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};