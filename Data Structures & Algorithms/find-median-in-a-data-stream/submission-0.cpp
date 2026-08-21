class MedianFinder {
public:
  priority_queue<int> maxh;
        priority_queue<int,vector<int>,greater<int>> minh;

    MedianFinder() {
      
    }
    
    void addNum(int num) {
        maxh.push(num);
        minh.push(maxh.top());
        maxh.pop();
        if(maxh.size()<minh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(minh.size()==maxh.size())return (double)(maxh.top()+minh.top())/2;
        return maxh.top();
    }
};
