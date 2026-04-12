class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<int>> adj_lists;
        unordered_map<char, int> degs;

        for(int i = 0; i < words.size() -1; i++) {
            auto word1 = words[i];
            auto word2 = words[i+1];
            int min_len = min(word1.size(), word2.size());
            int j = 0;
            while(j < min_len && word1[j] == word2[j])
                j++;
            if (j < min_len) {
                char a = word1[j], b = word2[j];
                adj_lists[a].push_back(b);
                if (!degs.count(a)) {
                    degs[a] = 0;
                }
                degs[b]++;
            } else if (min_len == word2.size() && word2.size() < word1.size()) {
                return "";
            }
        }
        vector<int> idle_set;
        for (auto [c, deg] : degs) {
            if(deg == 0){
                idle_set.push_back(c);
            }
        }

        int set_i = 0;
        while(set_i < idle_set.size()) {
            auto u = idle_set[set_i];
            for (auto v: adj_lists[u]) {
                degs[v]--;
                if (degs[v] == 0) {
                    idle_set.push_back(v);
                }
            }
            set_i++;
        }
        if (degs.size() != idle_set.size())
            return "";

        unordered_set<char> dicts;
        for (auto w : words) {
            dicts.insert(w.begin(), w.end());
        }
        for (char v : idle_set) {
            dicts.erase(v);
        }
        return string(idle_set.begin(), idle_set.end()) + string(dicts.begin(), dicts.end());

    }
};
