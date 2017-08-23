class Solution {
public:
	vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
		vector<pair<int, int>> queue;
		vector<pair<int, int>> dyPeople = people;
		vector<bool> visit(people.size(), false);
		int num = people.size();
		while (queue.size() < people.size()) {
			int frontHeight = INT_MAX;
			int id;
			for (int i = 0; i < dyPeople.size(); i++) {
				if (!visit[i] && dyPeople[i].second == 0 && dyPeople[i].first < frontHeight) {
					frontHeight = dyPeople[i].first;
					id = i;
				}
			}
			visit[id] = true;
			queue.push_back(people[id]);
			for (int i = 0; i < dyPeople.size(); i++) {
				if (!visit[i] && dyPeople[i].first <= dyPeople[id].first) {
					dyPeople[i].second--;
				}
			}
		}
		return queue;
	}
};