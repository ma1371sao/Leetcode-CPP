class Solution {
public:
	string validIPAddress(string IP) {
		int numSign = 0;
		int start = 0;
		if (IP.find('.') != string::npos) {
			if (IP.find(':') != string::npos) return "Neither";
			while (IP.find('.', start) != string::npos) {
				numSign++;
				if (numSign > 3) return "Neither";
				int posSign = IP.find('.', start);
				if (start == posSign) return "Neither";
				string num = IP.substr(start, posSign - start);
				if (num.length() > 1 && num[0] == '0') return "Neither";
				if (num.length() > 3) return "Neither";
				for (int i = 0; i < num.length(); i++) {
					if (num[i] < '0' || num[i] > '9')
						return "Neither";
				}
				int numInt = stoi(num);
				if (numInt < 0 || numInt > 255) return "Neither";
				start = posSign + 1;
			}
			if (numSign != 3 || start >= IP.length()) return "Neither";
			string num = IP.substr(start);
			if (num.length() > 1 && num[0] == '0') return "Neither";
			if (num.length() > 3) return "Neither";
			for (int i = 0; i < num.length(); i++) {
				if (num[i] < '0' || num[i] > '9')
					return "Neither";
			}
			int numInt = stoi(num);
			if (numInt < 0 || numInt > 255) return "Neither";
			return "IPv4";
		}
		if (IP.find(':') != string::npos) {
			while (IP.find(':', start) != string::npos) {
				numSign++;
				if (numSign > 7) return "Neither";
				int posSign = IP.find(':', start);
				if (start == posSign) return "Neither";
				string num = IP.substr(start, posSign - start);
				if (num.length() > 4) return "Neither";
				for (int i = 0; i < num.length(); i++) {
					if (!((num[i] >= '0' && num[i] <= '9') || (num[i] >= 'a' && num[i] <= 'f') || (num[i] >= 'A' && num[i] <= 'F')))
						return "Neither";
				}
				start = posSign + 1;
			}
			if (numSign != 7 || start >= IP.length()) return "Neither";
			string num = IP.substr(start);
			if (num.length() > 4) return "Neither";
			for (int i = 0; i < num.length(); i++) {
				if (!((num[i] >= '0' && num[i] <= '9') || (num[i] >= 'a' && num[i] <= 'f') || (num[i] >= 'A' && num[i] <= 'F')))
					return "Neither";
			}
			return "IPv6";
		}
		return "Neither";
	}
};