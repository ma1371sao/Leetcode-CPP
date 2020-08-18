/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    string hostname;
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        vector<string> ans;
        unordered_set<string> urls;
        hostname = startUrl.substr(7, startUrl.find("/", 7) - 7);
        dfs(startUrl, htmlParser, urls);
        return vector<string>(urls.begin(), urls.end());
    }

    void dfs(string startUrl, HtmlParser htmlParser, unordered_set<string>& urls) {
        if (urls.count(startUrl)) return;
        urls.insert(startUrl);
        vector<string> getUrls = htmlParser.getUrls(startUrl);
        for (string s : getUrls) {
            if (s.find(hostname) != -1) {
                dfs(s, htmlParser, urls);
            }
        }
    }
};
