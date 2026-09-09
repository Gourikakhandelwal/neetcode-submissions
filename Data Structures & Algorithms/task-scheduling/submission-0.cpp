class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> mp;
   

        for(auto &it:tasks){
            mp[it]++;
        }
        priority_queue<int> pq;
        for(auto it:mp){
            pq.push(it.second);
        }
        int time=0;
        while(!pq.empty()){
            int cnt=0;
            int count=n+1;
            vector<int> temp;
            while(cnt<count && !pq.empty()){
                int node=pq.top();
                pq.pop();
                node--;
                if(node>0){
                    temp.push_back(node);
                }
                cnt++;
                time++;
            }
            for(int i:temp){
                pq.push(i);
            }
            if(pq.empty())break;
            time+=count-cnt;
        
        }
        return time;
    }
};
