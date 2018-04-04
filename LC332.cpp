class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> itinerary;
        unordered_map<string, vector<string>> from_to;
        unordered_map<string, int> ticket_num;
        for (auto it : tickets) {
            from_to[it.first].push_back(it.second);
            ticket_num[it.first + it.second]++;
        }
        for (auto it = from_to.begin(); it != from_to.end(); it++)
            sort(it->second.begin(), it->second.end());
        itinerary.push_back("JFK");
        dfs(itinerary, from_to, ticket_num, tickets.size());
        return itinerary;
    }
    
    bool dfs(vector<string>& itinerary, unordered_map<string, vector<string>>& from_to, 
             unordered_map<string, int>& ticket_num, int total) {
        if (total == 0) return true;
        string from = itinerary.back();
        if (from_to.find(from) == from_to.end()) return false;
        for (int i = 0; i < from_to[from].size(); i++) {
            string to = from_to[from][i];
            if (ticket_num[from + to] > 0) {
                ticket_num[from + to]--;
                itinerary.push_back(to);
                if (dfs(itinerary, from_to, ticket_num, total - 1)) return true;
                else {
                    ticket_num[from + to]++;
                    itinerary.pop_back();
                }
            }
        }
        return false;
    }
};