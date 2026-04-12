class MedianFinder {
public:
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {}
    
    void addNum(int num) {
        if(max_heap.empty() || max_heap.top() > num) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        while (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        while (max_heap.size() < min_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }
    
    double findMedian() {
        if ((max_heap.size() + min_heap.size())%2) {
            return max_heap.top();
        }
        return (max_heap.top() + min_heap.top()) / (double)2.0;
    }
};
