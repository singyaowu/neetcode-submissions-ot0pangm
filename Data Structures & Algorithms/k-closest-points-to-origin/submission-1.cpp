class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;
        for(auto i = 0; i < points.size(); i++){
            auto p = points[i];
            int dist = p[0]*p[0] + p[1] * p[1];
            if (!pq.size() > k && dist > pq.top().first) {
                continue;
            }
            pq.push({dist, i});
            if(pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> ret;
        while(!pq.empty()) {
            auto idx = pq.top().second;
            pq.pop();
            ret.push_back(points[idx]);
        }
        return ret;
    }
};
