/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct cmp {
	bool operator() (const ListNode* a, const ListNode* b)
	{
		return a->val>b->val;
	}
};
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int n = lists.size();
		if (n == 0)
			return NULL;
		priority_queue<ListNode*, vector<ListNode*>, cmp> q;
		ListNode *p;
		for (int i = 0; i<n; i++)
		{
			p = lists[i];
			while (p)
			{
				q.push(p);
				p = p->next;
			}
		}
		if (q.empty())
			return NULL;
		ListNode *ans = q.top();
		p = ans;
		q.pop();
		while (!q.empty())
		{
			p->next = q.top();
			q.pop();
			p = p->next;
		}
		p->next = NULL;
		return ans;
	}
};