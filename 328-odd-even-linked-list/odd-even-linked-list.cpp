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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return head;

        ListNode *odd, *even, *even_head;
        odd = head;
        even_head = even = head -> next;
        int i = 0;

        while (odd -> next && even -> next) {
            // ListNode *odd_next = odd -> next, *even_next = even -> next;
            if (odd -> next) {
                odd -> next = odd -> next -> next;
                // odd = odd -> next;
            }
            if (even -> next) {
                even -> next = even -> next -> next;
                // even = even -> next;
            }

            if (odd) odd = odd -> next;
            if (even) even = even -> next;

            i++;
        }

        if (odd) odd -> next = even_head;

        return head;
    }
};