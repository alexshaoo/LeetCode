class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_set<int> s;
        
        int sum = 0, leftover = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            
            sum = (sum+nums[i])%k;
            
            if (s.find(sum) != s.end()) return true;
            
            s.insert(leftover);
            leftover = sum;
        }
        
        return false;
        
    }
};