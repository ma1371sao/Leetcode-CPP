class Solution {
public:
    int compareVersion(string version1, string version2) {
        if (version1 == "" && version2 == "") return 0;
        if (version1 == "") version1 = "0";
        if (version2 == "") version2 = "0";
        int pointPos1 = version1.find('.');
        string s1 = (pointPos1 == string::npos) ? version1 : version1.substr(0, pointPos1);
        string rest1 = (pointPos1 == string::npos) ? "" : version1.substr(pointPos1 + 1);
        int pointPos2 = version2.find('.');
        string s2 = (pointPos2 == string::npos) ? version2 : version2.substr(0, pointPos2);
        string rest2 = (pointPos2 == string::npos) ? "" : version2.substr(pointPos2 + 1);
        if (stoi(s1) > stoi(s2)) return 1;
        else if (stoi(s1) < stoi(s2)) return -1;
        else return compareVersion(rest1, rest2);
    }
};
