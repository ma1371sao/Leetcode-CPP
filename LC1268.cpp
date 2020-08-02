class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> sugProds(searchWord.length());
        for (string prod : products) {
            for (int i = 0; i < prod.length(); i++) {
                if (prod.substr(0, i + 1) == searchWord.substr(0, i + 1)) {
                    sugProds[i].push_back(prod);
                    sort(sugProds[i].begin(), sugProds[i].end());
                    if (sugProds[i].size() > 3)
                        sugProds[i].pop_back();
                }
            }
        }
        return sugProds;
    }
};
