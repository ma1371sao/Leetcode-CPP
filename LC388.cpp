struct Node {
	string fileName;
	vector<Node*> subFiles;
	int length;
	bool isFile;
	Node(string fileName, int length, bool isFile) : fileName(fileName), length(length), isFile(isFile) {}
};
class Solution {
public:
	int lengthLongestPath(string input) {
		Node root("", 0, false);
		Node* node = &root;
		int pos = 0;
		int longestPath = 0;
		while (pos < input.length()) {
			if (input[pos] == '\n') {
				if (input[pos + 1] == '\t') {
					node = root.subFiles.back();
				}
				else {
					node = &root;
				}
				pos++;
			}
			else if (input[pos] == '\t') {
				if (input[pos + 1] == '\t') {
					node = node->subFiles.back();
					pos++;
				}
				else {
					int nxt = input.find('\n', pos + 1);
					if (nxt == string::npos) {
						nxt = input.length();
					}
					string nxtFile = input.substr(pos + 1, nxt - pos - 1);
					bool isFile = false;
					if (nxtFile.find('.') != string::npos) {
						isFile = true;
					}
					node->subFiles.push_back(new Node(nxtFile, node->length + nxtFile.length() + 1, isFile));
					node = node->subFiles.back();
					if (isFile) {
						node->length--;
					}
					if (isFile && node->length > longestPath) {
						longestPath = node->length;
					}
					pos = nxt;
				}
			}
			else {
				int nxt = input.find('\n', pos);
				if (nxt == string::npos) {
					nxt = input.length();
				}
				string nxtFile = input.substr(pos, nxt - pos);
				bool isFile = false;
				if (nxtFile.find('.') != string::npos) {
					isFile = true;
				}
				node->subFiles.push_back(new Node(nxtFile, node->length + nxtFile.length() + 1, isFile));
				node = node->subFiles.back();
				if (isFile) {
					node->length--;
				}
				if (isFile && node->length > longestPath) {
					longestPath = node->length;
				}
				pos = nxt;
			}
		}
		return longestPath;
	}
};