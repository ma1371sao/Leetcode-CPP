class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int lr = ransomNote.length();
		int lm = magazine.length();
		map<char, int> m;
		int num = lr;
		if (lr>lm)
			return false;
		for (int i = 0; i<lr; i++)
		{
			if (m.find(ransomNote[i]) == m.end())
			{
				m[ransomNote[i]] = 1;
			}
			else
				m[ransomNote[i]]++;
		}
		for (int i = 0; i<lm; i++)
		{
			if (m.find(magazine[i]) != m.end() && m[magazine[i]]>0)
			{
				m[magazine[i]]--;
				num--;
			}
		}
		if (num == 0)
			return true;
		else
			return false;
	}
};