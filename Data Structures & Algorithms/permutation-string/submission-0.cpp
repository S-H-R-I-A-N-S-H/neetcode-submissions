class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.length();
        int n = s2.length();
        if (k > n)
            return false;
        vector<int> key1(26, 0);
        vector<int> key2(26, 0);

        for (int i = 0; i < k; i++) {
            key1[s1[i] - 'a']++;
            key2[s2[i] - 'a']++;
        }
        if (key1 == key2)
                return true;
        for (int i = 1; i < n - k + 1; i++) {
            key2[s2[i - 1] - 'a']--;
            key2[s2[k + i - 1] - 'a']++;
            if (key1 == key2)
                return true;
        }
        return false;
    }
};