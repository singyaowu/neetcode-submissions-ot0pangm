class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> cache(2, 
            vector<vector<int>>(piles.size() + 1, 
                vector<int>(piles.size() + 1, -1)));
        return recur(true, piles, cache, 0, 1);

    }
    int recur(bool alice, vector<int> & piles, vector<vector<vector<int>>> &cache, int idx, int m) {
        m = min(m, int(piles.size()));
        if (idx == piles.size()) return 0;
        if (cache[alice? 1 : 0][idx][m] != -1) return cache[alice? 1 : 0][idx][m];
        int max_sum = alice? 0 : INT_MAX;
        int turn_stone = 0;
        for (int x = 1; x <= 2 * m && idx + x - 1 < piles.size(); x++) {
            turn_stone += piles[idx + x - 1];
            if (alice) {
                max_sum = max(max_sum, turn_stone + recur(!alice, piles, cache, idx + x, max(m, x)));
            } else {
                max_sum = min(max_sum, recur(!alice, piles, cache, idx+x, max(m, x)));
            }
        }
        cache[alice? 1 : 0][idx][m] = max_sum;
        return max_sum;
    }
};