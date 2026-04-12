class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<unordered_set<int>> pres_set(numCourses);
        vector<vector<int>> v_to(numCourses);
        unordered_set<int>ind_set;
        for(auto i = 0; i < numCourses; i++) {
            ind_set.insert(i);
        }
        for (auto pre: prerequisites) {
            pres_set[pre[0]].insert(pre[1]);
            v_to[pre[1]].push_back(pre[0]);
            if(ind_set.count(pre[0]))
                ind_set.erase(pre[0]);
        }
        int finished = 0;
        while(!ind_set.empty()) {
            auto course = *ind_set.begin();
            for (auto to_course : v_to[course]) {
                pres_set[to_course].erase(course);
                if (pres_set[to_course].empty())
                    ind_set.insert(to_course);
            }
            ind_set.erase(course);
            finished++;
        }
        return finished == numCourses;
    }
};
