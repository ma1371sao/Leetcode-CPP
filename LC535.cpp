class Solution {
public:
	int num;
	unordered_map<int, string> encoded;
	unordered_map<int, string> ori;
	Solution() {
		num = 0;
	}
	// Encodes a URL to a shortened URL.
	string encode(string longUrl) {
		int lastSlash = -1;
		while (longUrl.find('/', lastSlash + 1) != string::npos) {
			lastSlash = longUrl.find('/', lastSlash + 1);
		}
		string s = longUrl.substr(lastSlash + 1);
		encoded[num] = "http://" + s + "/" + to_string(num);
		ori[num] = longUrl;
		return encoded[num++];
	}

	// Decodes a shortened URL to its original URL.
	string decode(string shortUrl) {
		int lastSlash = -1;
		while (shortUrl.find('/', lastSlash + 1) != string::npos) {
			lastSlash = shortUrl.find('/', lastSlash + 1);
		}
		int num = stoi(shortUrl.substr(lastSlash + 1));
		return ori[num];
	}
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));