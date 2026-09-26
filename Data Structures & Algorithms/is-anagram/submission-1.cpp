class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp1, mp2;
        if (s.length() != t.length()){
            return false;
        }
        for (int i =0; i<s.length() ; i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        
        for (const auto&[character, freq] : mp1){
            auto it = mp2.find(character);
            if (it == mp2.end()){
                return false;
            }
            if (it->second != freq){
                return false;
            }
        }
        return true;
    }
};
