class Solution {
public:
	unordered_map<string, int> vertex;
	unordered_map<int, string> number;
	int E[1000][1000];
	int n;
	vector<string> ans;
	vector<string> v;
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		if (tickets.size() == 0)    return ans;
		ans.push_back("JFK");
		v.push_back("JFK");
		int index = 0;
		vertex["JFK"] = index++;
		for (int i = 0; i<tickets.size(); i++) {
			if (vertex.find(tickets[i].first) == vertex.end()) {
				vertex[tickets[i].first] = index++;
				v.push_back(tickets[i].first);
			}
			if (vertex.find(tickets[i].second) == vertex.end()) {
				vertex[tickets[i].second] = index++;
				v.push_back(tickets[i].second);
			}
		}
		n = index;
		sort(v.begin(), v.end());
		for (int i = 0; i<n; i++) {
			vertex[v[i]] = i;
			number[i] = v[i];
		}
		for (int i = 0; i<tickets.size(); i++)
			E[vertex[tickets[i].first]][vertex[tickets[i].second]]++;
		DFS(tickets, 0, vertex["JFK"]);
		return ans;
	}
	bool DFS(vector<pair<string, string>>& tickets, int num, int pos) {
		if (num == tickets.size())
			return true;
		for (int i = 0; i<n; i++)
			if (E[pos][i]>0) {
				ans.push_back(number[i]);
				E[pos][i]--;
				if (DFS(tickets, num + 1, i))
					return true;
				ans.pop_back();
				E[pos][i]++;
			}
		return false;
	}
};