class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start1 = 0;
        int start2 = 0;
        int n1 = version1.length();
        int n2 = version2.length();
        int idx1 = 0, idx2 = 0;
        while (idx1 < n1 || idx2 < n2) {
            if (idx1 >= n1) {
                idx2 = version2.find(".", start2);
                if (idx2 == -1) idx2 = n2;
                int v2 = stoi(version2.substr(start2, idx2 - start2));
                
                if (v2 != 0) return -1;
                start2 = idx2 + 1;
                
            } else if (idx2 >= n2) {
                idx1 = version1.find(".", start1);
                if (idx1 == -1) idx1 = n1;
                int v1 = stoi(version1.substr(start1, idx1 - start1));
                
                if (v1 != 0) return 1;
                start1 = idx1 + 1;
                
            } else {
                idx1 = version1.find(".", start1);
                if (idx1 == -1) idx1 = n1;
                int v1 = stoi(version1.substr(start1, idx1 - start1));

                idx2 = version2.find(".", start2);
                if (idx2 == -1) idx2 = n2;
                int v2 = stoi(version2.substr(start2, idx2 - start2));

                if (v1 > v2) return 1;
                if (v1 < v2) return -1;
                start1 = idx1 + 1;
                start2 = idx2 + 1;
            }
        }
        return 0;
    }
};
