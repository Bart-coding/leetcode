/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head != nullptr)
        {
            ListNode* tmp = head;
        
            while (tmp->next != nullptr)
            {
                if (tmp->val != 100001)
                    tmp->val = 100001;
                else
                    return tmp;
                
                tmp = tmp->next;
            }
        }
        
        return nullptr;
    }
};
