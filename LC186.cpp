#include<vector>
#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
class solution {
public:
	void Reverse(string& s, int i, int j) {
		while (i < j) {
			char c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
	void ReverseWords(string& s) {
		if (s.length() == 0)	return;
		Reverse(s, 0, s.length() - 1);
		int j = 0;
		for (int i = s.find(' ', 0); i != string::npos; i = s.find(' ', i + 1)) {
			Reverse(s, j, i - 1);
			j = i + 1;
		}
		Reverse(s, j, s.length() - 1);
	}
};
