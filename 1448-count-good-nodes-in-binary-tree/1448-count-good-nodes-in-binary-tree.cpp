/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int goodNodes(TreeNode* root) {
        stack<pair<TreeNode*, int>> nodes;
        nodes.push({root, root -> val});
        int count = 0;

        while (!nodes.empty()) {
            pair<TreeNode*, int> current;
            current = nodes.top();
            nodes.pop();
            TreeNode* curr = current.first;
            int maxVal = current.second;
            
            if (!curr) continue;

            if (curr -> val >= maxVal) {
                count++;
                maxVal = curr -> val;
            }
            nodes.push({curr -> left, maxVal});
            nodes.push({curr -> right, maxVal});
        }

        return count;
    }
};