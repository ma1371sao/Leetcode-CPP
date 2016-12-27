class Solution {
public:
	string countAndSay(int n) {
		string ans;
		string t1 = "1";
		int k;
		for (int i = 0; i<n - 1; i++)
		{
			string t;
			for (int j = 0; j<t1.length();)
			{
				char temp = t1[j];
				int count = 0;
				for (k = j; k<t1.length() && t1[k] == t1[j]; k++, count++);
				t.push_back(count + 48);
				t.push_back(t1[j]);
				j = k;
			}
			t1.assign(t);	//t1=t;
		}
		ans = t1;
		return ans;
	}
};