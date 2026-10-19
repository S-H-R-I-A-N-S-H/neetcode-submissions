class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> s;
        int lcs = 1, ccs = 1;
        if (nums.empty()) return 0;
        for (int i = 0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        for (int n : s){
            if (s.find(n-1) != s.end()) continue;
            else {
                while (s.find(n+1) != s.end()){
                    n++;
                    ccs++;
                }
                lcs = max(ccs, lcs);
            }
                ccs = 1;
        }
        return lcs;

    }
};
