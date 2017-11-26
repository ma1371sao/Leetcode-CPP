class Solution {
public:
	int wordsTyping(vector<string>& sentence, int rows, int cols) {
		vector<int> nxtPos(sentence.size());
		vector<int> times(sentence.size());
		for (int i = 0; i < sentence.size(); i++) {
			int time = 0;
			int curC = 0;
			int curPos = i;
			while (curC + sentence[curPos].length() <= cols) {
				curC += sentence[curPos++].length() + 1;
				if (curPos >= sentence.size()) {
					curPos = 0;
					time++;
				}
			}
			nxtPos[i] = curPos;
			times[i] = time;
		}
		int pos = 0;
		int time = 0;
		for (int r = 0; r < rows; r++) {
			time += times[pos];
			pos = nxtPos[pos];
		}
		return time;
	}
};