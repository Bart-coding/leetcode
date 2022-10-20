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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        
        ListNode* head;
        ListNode* tmp;
        ListNode* tmp2;
        ListNode* tmp3;
        ListNode* tmp4;
        
        if (list1->val <= list2->val)
        {
            if (list1->next == nullptr)
            {
                list1->next = list2;
                return list1;
            }
            head = list1;
            tmp = list1;
            tmp2 = list2;
        }
            
        else
        {
            if (list2->next == nullptr)
            {
                list2->next = list1;
                return list2;
            }
            head = list2;
            tmp = list2;
            tmp2 = list1;
        }
        
        while (tmp->next != nullptr)
        {
            if (tmp2 == nullptr)
                return head;
            
            if (tmp->next->val >= tmp2->val)
            {
                tmp3 = tmp->next;
                tmp4 = tmp2->next;
                
                tmp->next = tmp2;
                tmp2->next = tmp3;
                
                tmp = tmp2;
                tmp2 = tmp4;
            }
            else
                tmp = tmp->next;
        }
        
        if (tmp2 != nullptr)
            tmp->next = tmp2;
            
        return head;
    }
};
