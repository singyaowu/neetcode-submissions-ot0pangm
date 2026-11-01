class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ret = 0;
        int l = 0;
        int r = people.size() - 1;
        while(l <= r) {
            if (people[r] + people[l] <= limit) {
                l++;
                r--;
                ret++;
            } else {
                r--;
                ret++;
            }
        }
        return ret;
    }
};