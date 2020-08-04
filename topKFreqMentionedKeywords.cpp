struct cmp {
   bool operator() (const pair<string, int>& a, const pair<string, int>& b) {
       if (a.second != b.second)
           return a.second < b.second;
       return a.first > b.first;
   }
};

vector<string> topKFreqMentionedKeywords(vector<string>& reviews, vector<string> keywords, int k) {
    vector<string> res;
    unordered_map<string, int> keyWordFreq;
    for (string word : keywords) {
        keyWordFreq[word] = 0;
    }
    
    for (string s : reviews) {
        unordered_set<string> words;
        string low;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z')
                low += s[i];
            else if (s[i] >= 'A' && s[i] <= 'Z')
                low += s[i] - 'A' + 'a';
            else {
                if (keyWordFreq.find(low) != keyWordFreq.end()) {
                    if (words.find(low) == words.end()) {
                        words.insert(low);
                        keyWordFreq[low]++;
                    }
                }
                low = "";
            }
        }
        
        if (low != "") {
            if (keyWordFreq.find(low) != keyWordFreq.end()) {
                if (words.find(low) == words.end()) {
                    keyWordFreq[low]++;
                }
            }
        }
    }
    
    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    for (auto& p : keyWordFreq) {
        pq.push(make_pair(p.first, p.second));
    }
    
    while(res.size() < k && !pq.empty()) {
        res.push_back(pq.top().first);
        pq.pop();
    }
    return res;
}

int main() {
    vector<string> keyWords{"anacell", "cetracular", "betacellular"};
    vector<string> reviews{
        "Anacell provides the best services in the city",
        "betacellular has awesome services",
        "Best services provided by anacell, everyone should use anacell"};
    vector<string> res = topKFreqMentionedKeywords(reviews, keyWords, 2);
    for (string s : res) {
        cout << s << endl;
    }
}
