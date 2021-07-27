class MedianFinder {
    priority_queue<int> A;//大根堆
    priority_queue<int, vector<int>, greater<int> > B;//小根堆
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if(A.size()!=B.size()){//奇数个数据
            A.push(num);
            B.push(A.top());
            A.pop();
        }
        else{//偶数个数据
            B.push(num);
            A.push(B.top());
            B.pop();
        }
    }
    
    double findMedian() {
        return A.size()!=B.size()?A.top():(A.top()+B.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
