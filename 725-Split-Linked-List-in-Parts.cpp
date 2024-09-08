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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        auto tmp = head;
        while (tmp) {
            ++n;
            tmp = tmp->next;
        }
        int q = n / k, rem = n % k;
        vector<ListNode*> ans;
        for (int i = 0; i < k; ++i) {
            int c = q + (rem > 0) - 1;
            // cout << q << ' ' << rem << ' ' << c << '\n';
            --rem;
            auto curr = head;
            for (int i = 0; i < c; ++i) {
                if (head) head = head->next;
            }
            if (head) {
                auto tmp = head->next;
                head->next = nullptr;
                ans.push_back(curr);
                curr = tmp;
                head = tmp;
            } else ans.push_back(curr);
        }
        return ans;
    }
};