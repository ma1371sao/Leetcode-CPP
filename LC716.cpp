class MaxStack {
public:
	/** initialize your data structure here. */
	map<int, vector<list<int>::iterator>> val_pos;
	list<int> nums;
	MaxStack() {

	}

	void push(int x) {
		nums.push_front(x);
		val_pos[x].push_back(nums.begin());
	}

	int pop() {
		int val = nums.front();
		nums.pop_front();
		val_pos[val].pop_back();
		if (val_pos[val].empty()) val_pos.erase(val);
		return val;
	}

	int top() {
		return nums.front();
	}

	int peekMax() {
		auto it = val_pos.end();
		it--;
		return it->first;
	}

	int popMax() {
		auto it = val_pos.end();
		it--;
		int val = it->first;
		nums.erase(it->second.back());
		it->second.pop_back();
		if (it->second.empty()) val_pos.erase(val);
		return val;
	}
};

/**
* Your MaxStack object will be instantiated and called as such:
* MaxStack obj = new MaxStack();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.top();
* int param_4 = obj.peekMax();
* int param_5 = obj.popMax();
*/