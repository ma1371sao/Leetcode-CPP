class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = n - 1;
        int end = 0;
        int profit = gas[start] - cost[start];
        while (end < start) {
            if (profit >= 0) {
                profit += gas[end] - cost[end];
                end++;
            }
            else {
                start--;
                profit += gas[start] - cost[start];
            }
        }
        return profit >= 0 ? start : -1;
    }
};
