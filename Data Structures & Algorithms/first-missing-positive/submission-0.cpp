class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (nums.empty())
            return 0;
        if (find(nums.begin(), nums.end(), 1) != nums.end()) {
            for (int i = 0; i < n; i++) {
                if (nums[i] > n || nums[i] < 1)
                    nums[i] = 1;
            }
            for (int i : nums) {
                if (abs(i) == n) {
                    nums[0] = -abs(nums[0]);
                }
                else {
                    nums[abs(i)] = -abs(nums[abs(i)]);
                }
            }
            for (int i = 2; i < n; i++) {
                if (nums[i] > 0)
                    return i;
            }
            if (nums[0] > 0)
                return n;
            return n + 1;
        }
        else
            return 1;
    }
};