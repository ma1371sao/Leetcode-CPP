class Solution {
public:
	string getHint(string secret, string guess) {
		map<char, int> ms;
		map<char, int> mg;
		int l = secret.size();
		int A = 0, B = 0;
		for (int i = 0; i<l; i++)
		{
			if (secret[i] == guess[i])
				A++;
			else
			{
				if (ms.find(secret[i]) == ms.end())
					ms.insert(pair<char, int>(secret[i], 1));
				else
					ms[secret[i]]++;
				if (mg.find(secret[i]) != mg.end() && mg[secret[i]]>0)
				{
					B++;
					mg[secret[i]]--;
					ms[secret[i]]--;
				}

				if (mg.find(guess[i]) == mg.end())
					mg.insert(pair<char, int>(guess[i], 1));
				else
					mg[guess[i]]++;
				if (ms.find(guess[i]) != ms.end() && ms[guess[i]]>0)
				{
					B++;
					mg[guess[i]]--;
					ms[guess[i]]--;
				}

			}
		}
		string ca = "";
		string cb = "";
		int tmp;
		tmp = A;
		do
		{
			char c = tmp % 10 + 48;
			ca = ca + c;
			tmp = tmp / 10;
		} while (tmp);
		string aa;
		for (int i = ca.size() - 1; i >= 0; i--)
			aa.push_back(ca[i]);

		tmp = B;
		do
		{
			char c = tmp % 10 + 48;
			cb = cb + c;
			tmp = tmp / 10;
		} while (tmp);
		string bb;
		for (int i = cb.size() - 1; i >= 0; i--)
			bb.push_back(cb[i]);

		string ans = "";
		ans = aa + 'A' + bb + 'B';
		return ans;
	}
};