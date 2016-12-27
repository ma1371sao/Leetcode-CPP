class Solution {
public:
	bool isHappy(int n) {
		map<int, int>m;
		map<int, int>record;
		for (int i = 0; i<10; i++)
			m[i] = i*i;
		int k = n;
		while (record.find(k) == record.end() && k != 1)
		{
			record[k] = 1;
			vector<int>sn;
			split(sn, k);
			int t = 0;
			for (int i = 0; i<sn.size(); i++)
				t = t + m[sn[i]];
			k = t;
		}
		if (k == 1)
			return true;
		else
			return false;
	}
	void split(vector<int>& sn, int tmp)
	{
		while (tmp)
		{
			sn.push_back(tmp % 10);
			tmp = tmp / 10;
		}
	}
};