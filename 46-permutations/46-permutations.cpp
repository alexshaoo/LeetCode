class Solution {
public:
    
    void help(vector<int>& nums, const int& size, int ind, vector<vector<int>>& fin) {
        
        // generated everything by now, base case
        if (ind == size) {
            fin.push_back(nums);
            return;
        }
        
        // generate recursively by scrambling current and calling function on next
        for (int i = ind; i < size; ++i) {
            swap(nums[i], nums[ind]);
            help(nums, size, ind+1, fin);
            swap(nums[i], nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> perms;
        help(nums, nums.size(), 0, perms);
        return perms;
    }
};