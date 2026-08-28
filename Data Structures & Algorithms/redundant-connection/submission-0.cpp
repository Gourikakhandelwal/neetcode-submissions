class Solution {
public:
vector<int> parent;
vector<int> rank;
int func(int x){
    if(parent[x]==x)return x;
    return parent[x]=func(parent[x]);
}
bool Union(int x,int y){
    int px=func(x);
    int py=func(y);
    if(px==py)return false;
    if(rank[px]>rank[py]){
        parent[py]=px;
        rank[px]+=rank[py];
    }else{
        parent[px]=py;
        rank[py]+=rank[px];
    }
    return true;
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        parent.resize(n+1);
        rank.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
        for(auto edge:edges){
            if(!Union(edge[0],edge[1])){
                return vector<int>{edge[0],edge[1]};
            }
        }
        return {};
    }
};
