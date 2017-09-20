class Solution {
public:
	string complexNumberMultiply(string a, string b) {
		string cpya = a;
		string cpyb = b;
		for (int i = 0; i < a.length(); i++) {
			if (a[i] != '-') cpya.push_back(a[i]);
			else cpya += "+-";
		}
		for (int i = 0; i < b.length(); i++) {
			if (b[i] != '-') cpyb.push_back(b[i]);
			else cpyb += "+-";
		}
		vector<int> paraA(2, 0);
		vector<int> paraB(2, 0);
		int plus = cpya.find('+');
		if (plus == string::npos) plus = cpya.length();
		paraA[0] = stoi(cpya.substr(0, plus));
		int posi = cpya.find('i');
		if (posi != string::npos)
			paraA[1] = stoi(cpya.substr(plus + 1, posi - plus - 1));
		plus = cpyb.find('+');
		if (plus == string::npos) plus = cpyb.length();
		paraB[0] = stoi(cpyb.substr(0, plus));
		posi = cpyb.find('i');
		if (posi != string::npos)
			paraB[1] = stoi(cpyb.substr(plus + 1, posi - plus - 1));
		vector<int> res(2, 0);
		res[0] = paraA[0] * paraB[0] - paraA[1] * paraB[1];
		res[1] = paraA[0] * paraB[1] + paraA[1] * paraB[0];
		return to_string(res[0]) + "+" + to_string(res[1]) + "i";
	}
};