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
	ListNode* insertionSortList(ListNode* head) {
		if (!head)   return head;
		ListNode* p = head;
		vector<int> list;
		while (p) {
			list.push_back(p->val);
			p = p->next;
		}
		for (int i = 1; i<list.size(); i++) {
			int j = i;
			while (j>0 && list[j]<list[j - 1]) {
				int tmp = list[j];
				list[j] = list[j - 1];
				list[j - 1] = tmp;
				j--;
			}
		}
		p = head;
		int i = 0;
		while (p) {
			p->val = list[i++];
			p = p->next;
		}
		return head;
	}
};