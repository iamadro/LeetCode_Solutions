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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        TreeNode *curr1, *curr2;
        stack<TreeNode*> stack1, stack2;
        stack1.push(root1);
        stack2.push(root2);

        while (!stack1.empty()) {
            curr1 = stack1.top();
            stack1.pop();

            if (!curr1->left && !curr1->right) {
                if (stack2.empty()) return false;

                while (!stack2.empty()) {
                    curr2 = stack2.top();
                    stack2.pop();

                    if (!curr2->left && !curr2->right) {
                        if (curr1->val != curr2->val) {
                            return false;
                        } else {
                            break;
                        }
                    }
                    if (curr2->right) stack2.push(curr2->right);
                    if (curr2->left) stack2.push(curr2->left);
                }
            }

            if (curr1->right) stack1.push(curr1->right);
            if (curr1->left) stack1.push(curr1->left);   
        }

        if (stack1.empty() && stack2.empty()) return true;
        else return false;
    }
};