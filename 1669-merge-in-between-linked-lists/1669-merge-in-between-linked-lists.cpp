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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* an = list1;
        int c = 1;
        while (c != a) {
            an = an->next;
            ++c;
        }
        ListNode* bn = an->next;
        while (c != b + 1) {
            bn = bn->next;
            ++c;
        }
        an->next = list2;
        ListNode* tmp = list2;
        while (tmp->next) tmp = tmp->next;
        tmp->next = bn;
        return list1;
    }
};