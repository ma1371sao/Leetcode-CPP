class Solution {
public:
	string originalDigits(string s) {
		unordered_map<char, int> characterNum;
		unordered_map<int, string> numTranslator;
		numTranslator[0] = "zero";
		numTranslator[1] = "one";
		numTranslator[2] = "two";
		numTranslator[3] = "three";
		numTranslator[4] = "four";
		numTranslator[5] = "five";
		numTranslator[6] = "six";
		numTranslator[7] = "seven";
		numTranslator[8] = "eight";
		numTranslator[9] = "nine";
		string resNums;
		for (int i = 0; i < s.length(); i++) {
			characterNum[s[i]]++;
		}
		while (characterNum['z'] > 0) {
			resNums.push_back('0');
			for (int j = 0; j < numTranslator[0].size(); j++) {
				characterNum[numTranslator[0][j]]--;
			}
		}
		while (characterNum['w'] > 0) {
			resNums.push_back('2');
			for (int j = 0; j < numTranslator[2].size(); j++) {
				characterNum[numTranslator[2][j]]--;
			}
		}
		while (characterNum['u'] > 0) {
			resNums.push_back('4');
			for (int j = 0; j < numTranslator[4].size(); j++) {
				characterNum[numTranslator[4][j]]--;
			}
		}
		while (characterNum['x'] > 0) {
			resNums.push_back('6');
			for (int j = 0; j < numTranslator[6].size(); j++) {
				characterNum[numTranslator[6][j]]--;
			}
		}
		while (characterNum['g'] > 0) {
			resNums.push_back('8');
			for (int j = 0; j < numTranslator[8].size(); j++) {
				characterNum[numTranslator[8][j]]--;
			}
		}
		while (characterNum['o'] > 0) {
			resNums.push_back('1');
			for (int j = 0; j < numTranslator[1].size(); j++) {
				characterNum[numTranslator[1][j]]--;
			}
		}
		while (characterNum['t'] > 0) {
			resNums.push_back('3');
			for (int j = 0; j < numTranslator[3].size(); j++) {
				characterNum[numTranslator[3][j]]--;
			}
		}
		while (characterNum['f'] > 0) {
			resNums.push_back('5');
			for (int j = 0; j < numTranslator[5].size(); j++) {
				characterNum[numTranslator[5][j]]--;
			}
		}
		while (characterNum['s'] > 0) {
			resNums.push_back('7');
			for (int j = 0; j < numTranslator[7].size(); j++) {
				characterNum[numTranslator[7][j]]--;
			}
		}
		while (characterNum['n'] > 0) {
			resNums.push_back('9');
			for (int j = 0; j < numTranslator[9].size(); j++) {
				characterNum[numTranslator[9][j]]--;
			}
		}
		sort(resNums.begin(), resNums.end());
		return resNums;
	}
};