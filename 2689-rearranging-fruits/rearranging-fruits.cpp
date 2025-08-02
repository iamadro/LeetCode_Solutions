class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        // Count frequency of each fruit across both baskets
        unordered_map<int, int> totalCount;
        for (int fruit : basket1) {
            totalCount[fruit]++;
        }
        for (int fruit : basket2) {
            totalCount[fruit]++;
        }
        
        // Check if it's possible to make baskets equal
        // Each fruit type must appear even number of times total
        for (auto& [fruit, count] : totalCount) {
            if (count % 2 != 0) {
                return -1; // Impossible
            }
        }
        
        // Count how many of each fruit each basket should have in final state
        unordered_map<int, int> count1, count2;
        for (int fruit : basket1) {
            count1[fruit]++;
        }
        for (int fruit : basket2) {
            count2[fruit]++;
        }
        
        // Find fruits that need to be moved
        vector<int> needToGiveFromBasket1; // fruits basket1 has excess of
        vector<int> needToTakeForBasket1;  // fruits basket1 needs more of
        
        for (auto& [fruit, totalCnt] : totalCount) {
            int targetCount = totalCnt / 2;
            int currentInBasket1 = count1[fruit];
            
            if (currentInBasket1 > targetCount) {
                // Basket1 has excess, need to give some to basket2
                int excess = currentInBasket1 - targetCount;
                for (int i = 0; i < excess; i++) {
                    needToGiveFromBasket1.push_back(fruit);
                }
            } else if (currentInBasket1 < targetCount) {
                // Basket1 needs more, need to take from basket2
                int deficit = targetCount - currentInBasket1;
                for (int i = 0; i < deficit; i++) {
                    needToTakeForBasket1.push_back(fruit);
                }
            }
        }
        
        // Sort to optimize pairing:
        // - Sort fruits to give away in ascending order (give away cheapest first)
        // - Sort fruits to receive in descending order (pair cheap-to-give with expensive-to-receive)
        sort(needToGiveFromBasket1.begin(), needToGiveFromBasket1.end());
        sort(needToTakeForBasket1.begin(), needToTakeForBasket1.end(), greater<int>());
        
        long long minCost = 0;
        int n = needToGiveFromBasket1.size();
        
        // Find the minimum fruit cost for potential indirect swaps
        int minFruit = *min_element(basket1.begin(), basket1.end());
        minFruit = min(minFruit, *min_element(basket2.begin(), basket2.end()));
        
        // For each pair, choose between direct swap and indirect swap via minFruit
        for (int i = 0; i < n; i++) {
            int giveFromBasket1 = needToGiveFromBasket1[i];
            int takeForBasket1 = needToTakeForBasket1[i];
            
            // Cost of direct swap
            long long directCost = min(giveFromBasket1, takeForBasket1);
            
            // Cost of indirect swap: use minFruit as bridge
            // Cost = 2 * minFruit (swap each fruit with minFruit)
            long long indirectCost = 2LL * minFruit;
            
            minCost += min(directCost, indirectCost);
        }
        
        return minCost;
    }
};