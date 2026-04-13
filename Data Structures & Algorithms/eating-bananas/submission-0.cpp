class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r) {
            int mid = l + (r - l) / 2;
            auto hr = 0;
            for (auto p : piles) {
                hr += p / mid + (p % mid ? 1 : 0);
            }
            if (hr > h) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
