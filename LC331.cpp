class Solution {
public:
	bool isValidSerialization(string preorder) {
		if (preorder == "#")
			return true;
		int pos = 0;
		stack<pair<string, int>> st;
		while (pos<preorder.length()) {
			int nxt = preorder.find(',', pos);
			if (nxt == string::npos)
				nxt = preorder.length();
			string subs = preorder.substr(pos, nxt - pos);
			if (subs == "#") {
				if (st.empty())  return false;
				st.top().second++;
				while (!st.empty() && st.top().second == 2) {
					st.pop();
					if (!st.empty())
						st.top().second++;
				}
				if (st.empty() && nxt != preorder.length())    return false;
			}
			else
				st.push(make_pair(subs, 0));
			pos = nxt + 1;
		}
		if (st.empty())  return true;
		return false;
	}
};