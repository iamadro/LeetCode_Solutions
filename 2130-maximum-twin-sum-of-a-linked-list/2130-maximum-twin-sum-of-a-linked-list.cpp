/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        // find the middle node
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            if (!fast->next) break;
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        // reverse the 2nd half
        ListNode* tempPrev = nullptr;

        while (slow != nullptr) {
            ListNode* tempNext = slow -> next;
            slow -> next = tempPrev;
            tempPrev = slow;
            slow = tempNext;            
        }

        // initiate 2 pointers
        ListNode *left = head, *right = tempPrev;

        // find the max pair sum
        int maxSum = 0, tempSum;
        while (right != nullptr) {
            tempSum = left -> val + right -> val;
            maxSum = maxSum > tempSum ? maxSum : tempSum;

            left = left -> next;
            right = right -> next;
        }

        return maxSum;
    }
};