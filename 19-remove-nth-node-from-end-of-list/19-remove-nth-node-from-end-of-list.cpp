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
  ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode *slow(head), *fast(head);
    
    // find element to remove
    while (n--) fast = fast->next;
    
    // empty case
    if (!fast) return head->next;
    
    // find element to skip over
    while (fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    
    // skip over
    slow->next = slow->next->next;
    return head;
  }
};