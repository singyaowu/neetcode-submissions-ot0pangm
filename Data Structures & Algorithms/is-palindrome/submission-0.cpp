class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        auto not_aphanumeric = [](char c) {
            return ('a' > c || c > 'z') &&
                ('0' > c || c > '9') && 
                ('A' > c || c > 'Z');
        };
        while (i < j) {
            while( i < j && not_aphanumeric(s[i]) ) {
                i++;
            }
            while( i < j && not_aphanumeric(s[j]) ) {
                j--;
            }
            if (i >= j) break;
            auto ci = s[i];
            if ('A' <= ci && 'Z' >= ci)
                ci = ci - 'A' + 'a';
            auto cj = s[j];
            if ('A' <= cj && 'Z' >= cj)
                cj = cj - 'A' + 'a';
            if (ci != cj) return false;
            i++;
            j--;
        }
        return true;
    }
};
