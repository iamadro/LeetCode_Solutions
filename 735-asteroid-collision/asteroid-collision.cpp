class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> collides{};

        for (int i = asteroids.size() - 1; i > -1; i--) {
            int asteroid = asteroids[i];
            while (!collides.empty() && collides.top() < 0 && asteroid > 0) {
                if (-1 * collides.top() < asteroid) collides.pop();
                else if (-1 * collides.top() > asteroid) asteroid = 0;
                else {
                    collides.pop();
                    asteroid = 0;
                }
            }
            if (asteroid != 0) collides.push(asteroid);
        }

        vector<int> res{};
        while (!collides.empty()) {
            res.push_back(collides.top());
            collides.pop();
        }

        return res;
    }
};