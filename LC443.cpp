class Solution {
public:
    int compress(vector<char>& chars) {
        int fast = 0;
        int slow = 0;
        while (fast < chars.size()) {
            chars[slow++] = chars[fast];
            int count = 1;
            for (;fast + 1 < chars.size() && chars[fast] == chars[fast + 1]; fast++, count++);
            if (count > 1) {
                string str_count = to_string(count);
                for (char c : str_count)
                    chars[slow++] = c;
            }
            fast++;
        }
        return slow;
    }
};
