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
    ListNode* middleNode(ListNode* head) {
        if (head->next == nullptr)
            return head;
        
        ListNode* middle;
        ListNode* tmp;
        
        bool evenElements = true;
        middle = head->next;
        
        tmp = head->next->next;
        
        while(tmp != nullptr)
        {
            evenElements = !evenElements;
            if (evenElements)
                middle = middle->next;
            
            tmp = tmp->next;
        }
        
        return middle;
    }
};
