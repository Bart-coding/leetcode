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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return head;
    
        ListNode* tmp;
        ListNode* tmp2;
        tmp = head;
        
        do
        {
           tmp2 = tmp->next;
            
           tmp->next = tmp2->next;
           tmp2->next = head;
           head = tmp2;
            
        } while (tmp->next != nullptr);
        
        return head;
    }
};
