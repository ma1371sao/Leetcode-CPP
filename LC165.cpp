class Solution {
public:
	int compareVersion(string version1, string version2) {
		string s1 = version1;
		string s2 = version2;
		while (s1.length() || s2.length()) {
			int p1 = s1.find('.');
			int p2 = s2.find('.');
			if (p1 == string::npos)    p1 = s1.length();
			if (p2 == string::npos)    p2 = s2.length();
			while (s1.length()>0 && s1[0] == '0') {
				s1 = s1.substr(1);
				p1--;
			}
			while (s2.length()>0 && s2[0] == '0') {
				s2 = s2.substr(1);
				p2--;
			}
			if (p1>p2)   return 1;
			if (p1<p2)   return -1;
			if (s1.substr(0, p1)>s2.substr(0, p2))   return 1;
			if (s2.substr(0, p2)>s1.substr(0, p1))   return -1;
			if (p1 == s1.length()) s1 = "";
			else s1 = s1.substr(p1 + 1);
			if (p2 == s2.length()) s2 = "";
			else s2 = s2.substr(p2 + 1);
		}
		return 0;
	}
};