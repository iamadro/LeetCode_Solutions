class Solution {
private:
    class Node {
    public:
        int maxVal;
        Node *left, *right;

        Node(int data) {
            maxVal = data;
            left = nullptr;
            right = nullptr;
        }
    };

    Node *segTree(vector<int> &baskets, int left, int right) {
        if (left > right) return nullptr;

        if (left == right) {
            Node* newNode = new Node(baskets[left]);
            return newNode;
        }

        int mid = left + (right - left) / 2;
        int leftVal = 0, rightVal = 0;
        Node *leftNode = segTree(baskets, left, mid), *rightNode = segTree(baskets, mid + 1, right);
        if (leftNode != nullptr) leftVal = leftNode -> maxVal;
        if (rightNode != nullptr) rightVal = rightNode -> maxVal;

        Node* newNode = new Node(max(leftVal, rightVal));
        newNode -> left = leftNode;
        newNode -> right = rightNode;

        return newNode;
    }

    bool canFit(int w, Node *root) {
        if (root -> maxVal < w) {
            return false;
        }
        if (root -> left == nullptr && root -> right == nullptr) {
            root -> maxVal = -1;
            return true;
        }
        if (canFit(w, root -> left) || canFit(w, root -> right)) {
            int rightVal = -1, leftVal = -1;
            if (root -> right != nullptr) rightVal = root -> right -> maxVal;
            if (root -> left != nullptr) leftVal = root -> left -> maxVal;
            root -> maxVal = max(leftVal, rightVal);
            return true;
        }
        return false;
    }

public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        Node *root = segTree(baskets, 0, n - 1);

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!canFit(fruits[i], root)) count++;
        }

        return count;
    }
};