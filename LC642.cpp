struct trieNode {
    vector<unordered_map<string, int>::iterator> matchStrs;
    unordered_map<char, trieNode*> dict;
};

struct cmp {
    bool operator()(const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second != b.second)
            return a.second > b.second;
        return a.first < b.first;
    }
};

class AutocompleteSystem {
public:
    trieNode* root;
    unordered_map<string, int> strTimes;
    string inputSentence = "";
    trieNode* cursor;
    
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root = new trieNode();
        for (int i = 0; i < sentences.size(); i++) {
            strTimes[sentences[i]] = times[i];
            insertSentence(sentences[i], 0, root);
        }
        cursor = root;
    }
    
    vector<string> input(char c) {
        vector<string> ans;
        if (c != '#') {
            inputSentence += c;
            if (cursor && cursor->dict.count(c)) {
                priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
                for (auto p : cursor->dict[c]->matchStrs) {
                    string s = p->first;
                    int times = p->second;
                    pq.push(make_pair(s, times));
                    if (pq.size() > 3)
                        pq.pop();
                }
                ans.resize(pq.size());
                int i = ans.size() - 1;
                while(!pq.empty()) {
                    auto p = pq.top();
                    pq.pop();
                    ans[i] = p.first;
                    i--;
                }
                cursor = cursor->dict[c];
                
            } else
                cursor = NULL;
            
        } else {
            if (strTimes.count(inputSentence)) {
                strTimes[inputSentence]++;
            } else {
                strTimes[inputSentence] = 1;
                insertSentence(inputSentence, 0, root);
            }
            cursor = root;
            inputSentence = "";
        }
        return ans;
    }
    
    void insertSentence(string& s, int idx, trieNode* root) {
        if (idx == s.length()) return;
        if (!root->dict.count(s[idx])) {
            root->dict[s[idx]] = new trieNode();
        }
        auto it = strTimes.find(s);
        root->dict[s[idx]]->matchStrs.push_back(it);
        insertSentence(s, idx + 1, root->dict[s[idx]]);
    }
};

int main() {
    vector<string> sentences{"i love you", "island", "ironman", "i love leetcode"};
    vector<int> times{5, 3, 2, 2};
    AutocompleteSystem as(sentences, times);
    auto ans = as.input('i');
    for (auto s : ans)
        cout << s << endl;
    cout << endl;
    
    ans = as.input(' ');
    for (auto s : ans)
        cout << s << endl;
    cout << endl;
    
    ans = as.input('a');
    for (auto s : ans)
        cout << s << endl;
    cout << endl;
    
    ans = as.input('#');
    for (auto s : ans)
        cout << s << endl;
    cout << endl;
}
