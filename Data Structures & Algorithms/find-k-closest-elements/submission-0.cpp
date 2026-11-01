class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l = 0;
        int r = arr.size();
        while(l < r) {
            int mid = (l + r) / 2;
            if (arr[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        deque<int> ret;
        r = l; // first element >= x
        l = l - 1; // first element < x

        for (int i = 0; i < k; i++) {
            if (l < 0) {
                ret.push_back(arr[r++]);
            }
            else if (r == arr.size()) {
                ret.push_front(arr[l--]);
            }
            else if (abs(arr[l] - x) <= abs(arr[r] - x)) {
                ret.push_front(arr[l--]);
            } else {
                ret.push_back(arr[r++]);
            }

        }
        return vector<int>(ret.begin(), ret.end());
    }
};