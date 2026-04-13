class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int mk = 1;
    KthLargest(int k, vector<int>& nums) {
        priority_queue<int> max_heap;
        for(auto num: nums) {
            max_heap.push(num);
        }
        for(int i = 0; i < k; i++) {
            if (max_heap.empty())
                break;
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        mk = k;
    }

    int add(int val) {
        if(min_heap.size() < mk) {
            min_heap.push(val);
        } else {
            if (val > min_heap.top()) {
                min_heap.push(val);
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};
