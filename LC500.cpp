class Solution {
public:
	vector<string> findWords(vector<string>& words) {
		vector<string> res;
		if (words.size() == 0) return res;
		unordered_map<char, int> keyboard;
		keyboard['Q'] = keyboard['q'] = 0;
		keyboard['W'] = keyboard['w'] = 0;
		keyboard['E'] = keyboard['e'] = 0;
		keyboard['R'] = keyboard['r'] = 0;
		keyboard['T'] = keyboard['t'] = 0;
		keyboard['Y'] = keyboard['y'] = 0;
		keyboard['U'] = keyboard['u'] = 0;
		keyboard['I'] = keyboard['i'] = 0;
		keyboard['O'] = keyboard['o'] = 0;
		keyboard['P'] = keyboard['p'] = 0;
		keyboard['A'] = keyboard['a'] = 1;
		keyboard['S'] = keyboard['s'] = 1;
		keyboard['D'] = keyboard['d'] = 1;
		keyboard['F'] = keyboard['f'] = 1;
		keyboard['G'] = keyboard['g'] = 1;
		keyboard['H'] = keyboard['h'] = 1;
		keyboard['J'] = keyboard['j'] = 1;
		keyboard['K'] = keyboard['k'] = 1;
		keyboard['L'] = keyboard['l'] = 1;
		keyboard['Z'] = keyboard['z'] = 2;
		keyboard['X'] = keyboard['x'] = 2;
		keyboard['C'] = keyboard['c'] = 2;
		keyboard['V'] = keyboard['v'] = 2;
		keyboard['B'] = keyboard['b'] = 2;
		keyboard['N'] = keyboard['n'] = 2;
		keyboard['M'] = keyboard['m'] = 2;
		for (int i = 0; i < words.size(); i++) {
			bool flag = true;
			for (int j = 1; j < words[i].length(); j++)
				if (keyboard[words[i][j]] != keyboard[words[i][0]]) {
					flag = false;
				}
			if (flag) res.push_back(words[i]);
		}
		return res;
	}
};