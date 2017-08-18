class Solution {
public:
	vector<int> lexicalOrder(int n) {
		vector<int> numsLexicalOrder;
		getNextNum(numsLexicalOrder, 1, n);
		return numsLexicalOrder;
	}
	void getNextNum(vector<int>& numsLexicalOrder, int num, int n) {
		numsLexicalOrder.push_back(num);
		if (num * 10 <= n) {
			getNextNum(numsLexicalOrder, num * 10, n);
		}
		if (num % 10 < 9 && num + 1 <= n) {
			getNextNum(numsLexicalOrder, num + 1, n);
		}
	}
};