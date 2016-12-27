/**
* Definition for undirected graph.
* struct UndirectedGraphNode {
*     int label;
*     vector<UndirectedGraphNode *> neighbors;
*     UndirectedGraphNode(int x) : label(x) {};
* };
*/
class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if (node == NULL)
			return NULL;
		UndirectedGraphNode *res = new UndirectedGraphNode(node->label);
		queue<UndirectedGraphNode*> q;
		q.push(node);
		unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;
		hash[node] = res;
		unordered_map<UndirectedGraphNode*, int> vis;
		vis[node] = 1;
		while (!q.empty()) {
			UndirectedGraphNode *p = q.front();
			q.pop();
			for (int i = 0; i<p->neighbors.size(); i++) {
				if (hash.find(p->neighbors[i]) == hash.end()) {
					UndirectedGraphNode *t = new UndirectedGraphNode(p->neighbors[i]->label);
					hash[p->neighbors[i]] = t;
				}
				int flag = 0;

				hash[p]->neighbors.push_back(hash[p->neighbors[i]]);
				if (p != p->neighbors[i] && !vis[p->neighbors[i]]) {
					q.push(p->neighbors[i]);
					vis[p->neighbors[i]] = 1;
				}
			}
		}
		return res;
	}
};