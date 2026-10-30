class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int max1 = -1, max2 = -1, cnt1 = 0, cnt2 = 0;
        for (auto n : nums) {
            if (cnt1 == 0) {
                max1 = n;
                cnt1++;
            } else if (cnt1 != 0 && max1 != n && cnt2 == 0) {
                max2 = n;
                cnt2++;
            }
            else if (max1 == n) {
                cnt1++;
            } else if (max2 == n){
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ret;
        cnt1 = 0;
        cnt2 = 0;
        for (auto n : nums) {
            if (n == max1) cnt1++;
            if(n == max2) cnt2++;
        }
        if (cnt1 > nums.size()/3) ret.push_back(max1);
        if (cnt2 >  nums.size()/3) ret.push_back(max2);
        
        return ret;
    }
};