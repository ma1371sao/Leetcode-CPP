class Solution {
public:
    int maxProduct(vector<string>& words) {
        int product = 0;
        vector<int> bits(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].length(); j++) {
                bits[i] |= (1 << (words[i][j] - 'a'));
            }
        }
        for (int i = 0; i < words.size(); i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((bits[i] & bits[j]) == 0)
                    product = max(product, (int)(words[i].length() * words[j].length()));
            }
        }
        return product;
    }
};