class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        queue<int> q;
        sort(deck.begin(), deck.end());
        for (int i = 0; i < deck.size(); i++)
            q.push(i);
        vector<int> ans(deck.size());
        for (int i = 0; i < deck.size(); i++) {
            int idx = q.front();
            q.pop();
            ans[idx] = deck[i];
            q.push(q.front());
            q.pop();
        }
        return ans;
    }
};
