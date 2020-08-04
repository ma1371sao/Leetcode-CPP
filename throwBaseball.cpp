int totalScore(vector<string>& marks) {
    stack<int> scoreStack;
    for (string mark : marks) {
        if (mark == "X") {
            int lastScore = 0;
            if (!scoreStack.empty()) {
                lastScore = scoreStack.top();
            }
            scoreStack.push(2 * lastScore);
        } else if (mark == "+") {
            int lastScore1 = 0;
            int lastScore2 = 0;
            if (scoreStack.size() > 0) {
                lastScore1 = scoreStack.top();
                scoreStack.pop();
                if (scoreStack.size() > 0) {
                    lastScore2 = scoreStack.top();
                }
                scoreStack.push(lastScore1);
            }
            scoreStack.push(lastScore1 + lastScore2);
        } else if (mark == "Z") {
            if (!scoreStack.empty()) {
                scoreStack.pop();
            }
        } else {
            int val = stoi(mark);
            scoreStack.push(val);
        }
    }
    
    int sum = 0;
    while (!scoreStack.empty()) {
        sum += scoreStack.top();
        scoreStack.pop();
    }
    return sum;
}

int main() {
    vector<string> input{"5", "-2", "4", "Z", "X", "9", "+", "+"};
    cout << totalScore(input) << endl;
    return 0;
}
