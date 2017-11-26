/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct cmp {
	bool operator() (const ListNode* p, const ListNode* q) {
		return p->val > q->val;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
		ListNode* head = new ListNode(0);
		int k = lists.size();
		for (int i = 0; i < k; i++)
			if (lists[i])
				pq.push(lists[i]);
		ListNode* p = head;
		while (!pq.empty()) {
			ListNode* top = pq.top();
			pq.pop();
			p->next = top;
			p = p->next;
			if (pq.empty()) break;
			if (top->next) pq.push(top->next);
		}
		return head->next;
	}
};