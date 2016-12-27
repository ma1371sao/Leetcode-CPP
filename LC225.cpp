class Stack {
public:
	// Push element x onto stack.
	queue<int> q;
	void push(int x) {
		q.push(x);
	}

	// Removes the element on top of the stack.
	void pop() {
		if (q.empty())
			return;
		queue<int> q1;
		while (!q.empty()) {
			int tmp = q.front();
			q.pop();
			if (q.empty()) {
				q = q1;
				return;
			}
			else
				q1.push(tmp);
		}
	}

	// Get the top element.
	int top() {
		queue<int> q1;
		while (!q.empty()) {
			int tmp = q.front();
			q.pop();
			if (q.empty()) {
				q1.push(tmp);
				q = q1;
				return tmp;
			}
			else
				q1.push(tmp);
		}
		return 0;
	}

	// Return whether the stack is empty.
	bool empty() {
		return q.empty();
	}
};