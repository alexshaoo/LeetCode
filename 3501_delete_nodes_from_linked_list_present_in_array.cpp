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
    unordered_set<int> s;
    for (const int& num : nums) s.insert(num);
    ListNode* ans = nullptr;
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr != nullptr) {
      if (!s.contains(curr->val)) {
        if (ans == nullptr) {
          ans = curr;
        }
        if (prev != nullptr) {
          prev->next = curr;
        }
        prev = curr;
      }
      curr = curr->next;
    }
    if (prev->next != nullptr && s.contains(prev->next->val)) prev->next = nullptr;
    return ans;
  }
};