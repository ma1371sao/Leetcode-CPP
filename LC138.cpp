/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (head == NULL)  return NULL;
		RandomListNode *start = new RandomListNode(head->label);
		unordered_map<RandomListNode*, RandomListNode*> hash;
		hash[head] = start;
		RandomListNode*p = head;
		RandomListNode*q = start;
		while (p->next) {
			p = p->next;
			q->next = new RandomListNode(p->label);
			q = q->next;
			hash[p] = q;
		}
		p = head;
		q = start;
		while (p) {
			if (p->random != NULL)
				q->random = hash[p->random];
			p = p->next;
			q = q->next;
		}
		return start;
	}
};