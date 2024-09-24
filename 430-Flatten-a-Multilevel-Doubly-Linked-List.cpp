/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return head;
        Node* ans = head;
        while (head) {
            if (!head->child) {
                head = head->next;
            } else {
                Node* nxt = head->next;
                Node* child = head->child;
                Node* childTail = head->child;
                while (childTail->next) {
                    childTail = childTail->next;
                }
                head->child = nullptr;
                head->next = child;
                child->prev = head;
                childTail->next = nxt;
                if (nxt) nxt->prev = childTail;
            }
        }
        return ans;
    }
};