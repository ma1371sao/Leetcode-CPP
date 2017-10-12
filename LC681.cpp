bool cmp(const vector<int>& a, const vector<int>& b) {
	int valueA = (a[0] * 10 + a[1]) * 60 + a[2] * 10 + a[3];
	int valueB = (b[0] * 10 + b[1]) * 60 + b[2] * 10 + b[3];
	return valueA < valueB;
}
class Solution {
public:
	string nextClosestTime(string time) {
		vector<int> num;
		num.push_back(time[0] - '0');
		if (time[1] != time[0])
			num.push_back(time[1] - '0');
		if (time[3] != time[1] && time[3] != time[0])
			num.push_back(time[3] - '0');
		if (time[4] != time[3] && time[4] != time[1] && time[4] != time[0])
			num.push_back(time[4] - '0');
		vector<vector<int>> times;
		vector<int> curTime;
		dfs(times, curTime, num);
		vector<int> v;
		v.push_back(time[0] - '0');
		v.push_back(time[1] - '0');
		v.push_back(time[3] - '0');
		v.push_back(time[4] - '0');
		sort(times.begin(), times.end(), cmp);
		int nxtTimePos = 0;
		for (int i = 0; i < times.size(); i++) {
			if (times[i] == v) {
				if (i == times.size() - 1)
					nxtTimePos = 0;
				else
					nxtTimePos = i + 1;
				break;
			}
		}
		string res;
		res.push_back(times[nxtTimePos][0] + '0');
		res.push_back(times[nxtTimePos][1] + '0');
		res += ":";
		res.push_back(times[nxtTimePos][2] + '0');
		res.push_back(times[nxtTimePos][3] + '0');
		return res;
	}
	void dfs(vector<vector<int>>& times, vector<int>& curTime, vector<int>& num) {
		if (curTime.size() == 4) {
			if (valid(curTime))
				times.push_back(curTime);
			return;
		}
		for (int i = 0; i < num.size(); i++) {
			curTime.push_back(num[i]);
			dfs(times, curTime, num);
			curTime.pop_back();
		}
	}
	bool valid(vector<int> time) {
		if (time[0] * 10 + time[1] >= 24)
			return false;
		if (time[2] * 10 + time[3] >= 60)
			return false;
		return true;
	}
};