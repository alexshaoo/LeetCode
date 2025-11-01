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
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    bitset<100001> s;
    for (const int& num : nums) s[num] = 1;
    ListNode* dummy = new ListNode(-1, head);
    for (auto curr = dummy; curr->next != nullptr; ) {
      if (s[curr->next->val]) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};