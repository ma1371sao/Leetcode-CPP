class Queue {
public:
	// Push element x to the back of queue.
	stack<int> s;
	void push(int x) {
		s.push(x);
	}

	// Removes the element from in front of queue.
	void pop(void) {
		stack<int> s1;
		if (s.size() == 1)
			s.pop();
		else {
			while (s.size()>1) {
				s1.push(s.top());
				s.pop();
			}
			s.pop();
			while (!s1.empty()) {
				s.push(s1.top());
				s1.pop();
			}
		}
	}

	// Get the front element.
	int peek(void) {
		stack<int> s1;
		if (s.size() == 1) return s.top();
		else {
			int front;
			while (s.size()>1) {
				s1.push(s.top());
				s.pop();
			}
			front = s.top();
			while (!s1.empty()) {
				s.push(s1.top());
				s1.pop();
			}
			return front;
		}
	}

	// Return whether the queue is empty.
	bool empty(void) {
		return s.empty();
	}
};