class Solution {
public:
    int getSum(int a, int b) {
        int cout = 0;
        int ret = 0;
        for(int i = 0; i < 32; i++) {
            ret ^= (cout ^ (a&1) ^ (b&1)) << i;
            cout = (cout && (a&1)) | (cout && (b&1)) | ((b&1) && (a&1));
            a >>= 1;
            b >>= 1;
        }
        return ret;
    }
};
