class Solution {
public:
    string numberToWords(int num) {
        if (num == 0) return "Zero";
        vector<string> v{"Billion", "Million", "Thousand"};
        vector<int> v1{1000000000, 1000000, 1000};
        string ans = "";
        for (int i = 0; i < 3; i++) {
            if (num / v1[i]) {
                ans += convertToHundred(num / v1[i]) + " " + v[i] + " ";
                num = num % v1[i];
            }
        }
        ans += convertToHundred(num);
        while (ans.back() == ' ') ans.pop_back();
        if (ans == "") return "Zero";
        return ans;
    }
    
    string convertToHundred(int num) {
        if (num == 0) return "";
        vector<string> v1{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        vector<string> v2{"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string s = "";
        if (num / 100) s += v1[num / 100] + " " + "Hundred ";
        int t = num % 100;
        if (t / 10 < 2) s += v1[num % 100] + " ";
        else s += v2[t / 10] + " " + v1[t % 10] + " ";
        while (s.back() == ' ') s.pop_back();
        return s;
    }
};
