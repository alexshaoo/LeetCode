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
    void reorderList(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        ListNode* rev = nullptr;
        while (tmp) {
            ++n;
            ListNode* newRev = new ListNode(tmp->val, rev);
            rev = newRev;
            tmp = tmp->next;
        }
        for (int i = 0; i < (n - 1) / 2; ++i) {
            ListNode* headNext = head->next;
            ListNode* revNext = rev->next;
            head->next = rev;
            rev->next = headNext;
            head = headNext;
            rev = revNext;
        }
        if (n % 2 == 0) {
            head->next = rev;
            rev->next = nullptr;
        } else {
            head->next = nullptr;
        }
    }
};