/**********************************************************
 * LeetCode Practise
 * 7/1/2019
 * Add Two Numbers 
 * https://leetcode.com/problems/add-two-numbers/
 **********************************************************/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        typedef ListNode* Nodeptr; 
        Nodeptr sum = new ListNode(0);
        Nodeptr l3=sum;
        Nodeptr temp;
        int val=0;

        while (l1!=NULL||l2!=NULL||val>0)
        {
            if(l1!=NULL)
            {
                val += l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL)
            {
                val += l2->val;
                l2 = l2->next;
            }
            sum->val = val%10;
            val /= 10;
            temp = new ListNode(0);
            if(l1!=NULL||l2!=NULL||val>0)
            {
                sum->next = temp;
                sum = temp;
            }
        }
        return l3;
    }
};