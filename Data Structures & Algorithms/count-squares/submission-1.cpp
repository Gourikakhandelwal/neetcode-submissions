class CountSquares {
public:
map<pair<int,int>,int>freq;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        freq[{point[0],point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x=point[0];
        int y=point[1];
        int ans=0;
        for(auto it:freq){
            int px=it.first.first;
            int py=it.first.second;
            if(abs(px-x)!=abs(py-y))continue;
            if(px==x && py==y)continue;
            int x1=px;
            int y1=y;
            int x2=x;
            int y2=py;
            ans += freq[{px,py}] * freq[{x1,y1}] * freq[{x2,y2}];
        }
        return ans;
    }
};
