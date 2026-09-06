class Solution {
public:

    map<string, multiset<string>> adj;
    vector<string> ans;

    void dfs(string src) {

        while (!adj[src].empty()) {

            // Smallest destination
            string dest = *adj[src].begin();

            // Use this ticket
            adj[src].erase(adj[src].begin());

            dfs(dest);
        }

        // No more unused tickets from src
        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");

        reverse(ans.begin(), ans.end());

        return ans;
    }
};