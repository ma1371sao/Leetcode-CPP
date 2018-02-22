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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)    return l2;
        if(l2==NULL)    return l1;
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* start=new ListNode(0);
        ListNode* k=start;
        while(p || q){
            if(p && q){
                if(p->val<=q->val){
                    k->next=p;
                    p=p->next;
                    k=k->next;
                }
                else{
                    k->next=q;
                    q=q->next;
                    k=k->next;
                }
            }
            else if(p){
                k->next=p;
                break;
            }
            else{
                k->next=q;
                break;
            }
        }
        return start->next;
    }
};
