class Solution {
public:
	int largestPalindrome(int n) {
		if (n == 1) return 9;
		long long upperbound = (pow(10, n) - 1) * (pow(10, n) - 1);
		long long lowerbound = pow(10, 2 * n - 2);
		long long palindrome;
		bool flag = false;
		for (long long frontHalf = upperbound / pow(10, n); frontHalf >= pow(10, n - 1) && !flag; frontHalf--) {
			palindrome = createPalindrome(frontHalf);
			for (long long i = pow(10, n) - 1; i * i >= palindrome; i--) {
				if (palindrome % i == 0 && palindrome / i >= pow(10, n - 1) && palindrome / i < pow(10, n)) {
					flag = true;
					break;
				}
			}
		}
		return palindrome % 1337;
	}
	long long createPalindrome(long long frontHalf) {
		string backHalf = to_string(frontHalf);
		reverse(backHalf.begin(), backHalf.end());
		string palindromeStr = to_string(frontHalf) + backHalf;
		stringstream ss(palindromeStr);
		long long palindrome;
		ss >> palindrome;
		return palindrome;
	}
};