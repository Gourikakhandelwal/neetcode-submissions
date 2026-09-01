class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            string word=node.first;
            int num=node.second;
            if(word==endWord){
                return num;
            }
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        st.erase(word);
                        q.push({word,num+1});
                    }
                    

                }
                word[i]=original;


            }
        
            }
            return 0;
        }
    
};
