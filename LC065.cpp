class Solution {
public:
	bool isNumber(string s) {
		int size = s.size();
		if (size == 0) {
			return false;
		}//if
		 // 前导0
		int start = 0;
		while (s[start] == ' ') {
			++start;
		}//while
		 // 后导0
		int end = size - 1;
		while (s[end] == ' ') {
			--end;
		}//while
		bool hasNum = false, hasPoint = false, hasE = false;
		for (int i = start; i <= end; ++i) {
			if (s[i] == '.') {
				// 如果前面已经有了'.' 或者 'e'
				if (hasPoint || hasE) {
					return false;
				}//if
				hasPoint = true;
			}//if
			else if (s[i] == 'e') {
				// 如果前面已经有了'e' 或者 没数字
				if (hasE || !hasNum) {
					return false;
				}//if
				hasE = true;
			}//else
			else if (s[i] < '0' || s[i] > '9') {
				// +2
				if (i == start && (s[i] == '+' || s[i] == '-')) {
					continue;
				}//if
				 // 1e-2
				else if ((i != 0 && s[i - 1] == 'e') && (s[i] == '+' || s[i] == '-')) {
					continue;
				}
				else {
					return false;
				}//else
			}//else
			else {
				hasNum = true;
			}//else
		}//for
		 // 最后有效位不能是'e+-'
		if (s[end] == 'e' || s[end] == '+' || s[end] == '-') {
			return false;
		}//if
		 // '.'
		if (!hasNum && hasPoint) {
			return false;
		}//if
		 // 全是空格
		if (end == -1) {
			return false;
		}//if
		return true;
	}
};