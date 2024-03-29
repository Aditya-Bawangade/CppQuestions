class MedianFinder {
    priority_queue<int> maxHeap ; 
    priority_queue<int, vector<int>, greater<>> minHeap ;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(minHeap.empty() || minHeap.top() <= num){
            minHeap.push(num) ;
            if(minHeap.size() > maxHeap.size() + 1){
                maxHeap.push(minHeap.top()) ;
                minHeap.pop() ;
            }
        }else{
            maxHeap.push(num) ;
            if(maxHeap.size() > minHeap.size()){
                minHeap.push(maxHeap.top()) ;
                maxHeap.pop() ;
            }
        }
    }
    
    double findMedian() {
        if((minHeap.size() + maxHeap.size()) %2 == 0){
            return (double(minHeap.top()) + double(maxHeap.top()) )/2 ;
        }
        return minHeap.top() ;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */