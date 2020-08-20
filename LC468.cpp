class Solution {
public:
    string validIPAddress(string IP) {
        if (IP.find(".") != -1) {
            int start = 0;
            for (int i = 0; i < 4; i++) {
                int idx = IP.find(".", start);
                if (i < 3 && idx == -1) return "Neither";
                if (i == 3) {
                    if (idx != -1) return "Neither";
                    idx = IP.length();
                }
                
                string sub = IP.substr(start, idx - start);
                if ((sub[0] == '0' && sub.length() > 1) || sub.length() > 3 || sub.length() == 0) return "Neither";
                for (int i = 0; i < sub.length(); i++) {
                    if (sub[i] < '0' || sub[i] > '9') return "Neither";
                }
                int d = stoi(sub);
                if (d > 255) return "Neither";
                start = idx + 1;
            }
            return "IPv4";
        }
        int start = 0;
        for (int i = 0; i < 8; i++) {
            int idx = IP.find(":", start);
            if (i < 7 && idx == -1) return "Neither";
            if (i == 7) {
                if (idx != -1) return "Neither";
                idx = IP.length();
            }
            
            string sub = IP.substr(start, idx - start);
            if (sub.length() > 4 || sub.length() == 0) return "Neither";
            for (int i = 0; i < sub.length(); i++) {
                if (!(
                    (sub[i] >= '0' && sub[i] <= '9') || (sub[i] >= 'a' && sub[i] <= 'f') || (sub[i] >= 'A' && sub[i] <= 'F')
                ))
                    return "Neither";
            }
            start = idx + 1;
        }
        return "IPv6";
    }
};
