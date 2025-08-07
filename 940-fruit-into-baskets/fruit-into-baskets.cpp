class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0, j = -1, k = -1, a = -1, count = 0, maxCount = INT_MIN, n = fruits.size();

        while(i < n) {
            if (j == -1) {
                a = i;
                j = i;
                count++;
            } else if (k == -1) {
                if (fruits[i] != fruits[j]) k = i;
                else j = i;
                count++;
            } else {
                if (fruits[i] == fruits[j] || fruits[i] == fruits[k]) {
                    if (fruits[i] == fruits[j]) j = i;
                    else k = i;
                    count++;
                } else {
                    if (j < k) {
                        count -= j - a + 1;
                        a = j + 1;
                        j = i;
                        count++;
                    } else {
                        count -= k - a + 1;
                        a = k + 1;
                        k = i;
                        count++;
                    }
                }
            }
            
            maxCount = max(maxCount, count);
            i++;
            cout << i << j << k << a;
        }

        return maxCount;
    }
};