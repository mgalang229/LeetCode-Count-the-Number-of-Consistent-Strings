class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        bool present[26];
        memset(present, false, sizeof(present));
        for (char& c : allowed) {
            present[c-'a'] = true;
        }
        bool checker[26];
        int cnt = 0;
        for (string word : words) {
            memset(checker, false, sizeof(checker));
            for (char& c : word) {
                checker[c-'a'] = true;
            }
            bool ok = true;
            for (int i = 0; i < 26; i++) {
                if (checker[i] && !present[i]) {
                    ok = false;
                }
            }
            cnt += ok;
        }
        return cnt;
    }
};
