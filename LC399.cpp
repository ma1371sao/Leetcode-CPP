class Solution {
public:
	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		unordered_map<string, double> relation;
		unordered_map<string, int> visit;
		vector<double> res;
		for (int i = 0; i < equations.size(); i++) {
			string s1 = equations[i].first + "%" + equations[i].second;
			relation[s1] = values[i];
			visit[s1] = 0;
			if (values[i] == 0)
				continue;
			string s2 = equations[i].second + "%" + equations[i].first;
			relation[s2] = 1.0 / values[i];
			visit[s2] = 0;
		}
		for (int i = 0; i < queries.size(); i++) {
			res.push_back(findResult(queries[i].first, queries[i].second, relation, 1.0, visit, 0));
			for (unordered_map<string, int>::iterator it = visit.begin(); it != visit.end(); it++)
				it->second = 0;
		}
		return res;
	}

	double findResult(string first, string target, unordered_map<string, double>& relation, double result,
		unordered_map<string, int>& visit, int flag) {
		if (first == target && flag) return result;
		for (unordered_map<string, double>::iterator it = relation.begin(); it != relation.end(); it++) {
			flag = 1;
			int mod = it->first.find('%');
			string front = it->first.substr(0, mod);
			string back = it->first.substr(mod + 1);
			if (front == first && !visit[it->first]) {
				visit[it->first] = 1;
				double nxt = findResult(back, target, relation, result * it->second, visit, flag);
				if (nxt != -1.0) return nxt;
			}
		}
		return -1.0;
	}
};