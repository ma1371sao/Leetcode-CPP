class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		if (s.length()<10)   return res;
		unordered_map<string, bool> repeat;
		for (int i = 0; i <= s.length() - 10; i++) {
			string sub = s.substr(i, 10);
			if (repeat.find(sub) != repeat.end() && !repeat[sub]) {
				res.push_back(sub);
				repeat[sub] = true;
			}
			else if (repeat.find(sub) == repeat.end())
				repeat[sub] = false;
		}
		return res;
	}
};