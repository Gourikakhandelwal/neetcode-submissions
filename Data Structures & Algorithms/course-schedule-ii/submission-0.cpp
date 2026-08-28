class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);
        for(auto edge:prerequisites){
            int u=edge[0];
            int v=edge[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int finish=0;
        vector<int> arr;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            arr.push_back(node);
            finish++;
            for(int val:adj[node]){
                indegree[val]--;
                if(indegree[val]==0){
                    q.push(val);
                }
            }
        }
        if(finish!=numCourses)return {};
        return arr;
    }
};
