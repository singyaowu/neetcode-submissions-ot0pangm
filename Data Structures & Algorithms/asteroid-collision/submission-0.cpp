class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;
        for (auto a : asteroids) {
            if(s.empty() || (s.back() < 0 && a > 0)) {
                s.push_back(a);
            } else {
                bool destroy = false;
                while(!s.empty() && (s.back() > 0 && a < 0)) {
                    int back = s.back();
                    if (abs(back) <= abs(a)) {
                        s.pop_back();
                    }
                    if (abs(back) >= abs(a)){
                        destroy = true;
                        break;
                    }
                }
                if(!destroy) s.push_back(a);
            }
        }
        return s;
    }
};