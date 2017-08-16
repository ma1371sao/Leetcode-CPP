class Node {
public:
	int x;
	int y;
	int value;
	Node(int x, int y, int v) {
		this->x = x;
		this->y = y;
		this->value = v;
	}
};
struct cmp {
	bool operator() (const Node& a, const Node& b) {
		return a.value > b.value;
	}
};
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		priority_queue<Node, vector<Node>, cmp> pq;
		Node root(0, 0, matrix[0][0]);
		pq.push(root);
		vector<vector<int>> flag(matrix.size(), vector<int>(matrix.size(), 0));
		flag[0][0] = 1;
		for (int i = 0; i<k - 1; i++) {
			Node top = pq.top();
			pq.pop();
			if (top.x + 1 < matrix.size() && !flag[top.x + 1][top.y]) {
				Node below(top.x + 1, top.y, matrix[top.x + 1][top.y]);
				pq.push(below);
				flag[top.x + 1][top.y] = 1;
			}
			if (top.y + 1 < matrix.size() && !flag[top.x][top.y + 1]) {
				Node right(top.x, top.y + 1, matrix[top.x][top.y + 1]);
				pq.push(right);
				flag[top.x][top.y + 1] = 1;
			}
		}
		return pq.top().value;
	}
};