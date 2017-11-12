class Solution {
public:
	string addBinary(string a, string b) {
		string sum;
		int carry = 0;
		int i = a.length() - 1;
		int j = b.length() - 1;
		while (i >= 0 || j >= 0 || carry) {
			if (i >= 0 && j >= 0) {
				int add = a[i] - '0' + b[j] - '0' + carry;
				sum.push_back(add % 2 + '0');
				carry = add / 2;
				i--;
				j--;
			}
			else if (i >= 0) {
				int add = a[i] - '0' + carry;
				sum.push_back(add % 2 + '0');
				carry = add / 2;
				i--;
			}
			else if (j >= 0) {
				int add = b[j] - '0' + carry;
				sum.push_back(add % 2 + '0');
				carry = add / 2;
				j--;
			}
			else {
				sum.push_back(carry + '0');
				carry = 0;
			}
		}
		reverse(sum.begin(), sum.end());
		return sum;
	}
};