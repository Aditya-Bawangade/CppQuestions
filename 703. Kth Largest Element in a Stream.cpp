class KthLargest {
    priority_queue<int, vector<int>, greater<int>> heap ;
    int lim ;
public:
    KthLargest(int k, vector<int>& nums) {
        lim = k ;
        for(auto i : nums) heap.push(i) ;
    }
    
    int add(int val) {
        heap.push(val) ;
        while(heap.size() > lim){
            heap.pop() ;
        }
        return heap.top() ;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */