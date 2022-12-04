class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return 0
        
        min_avg_diff = math.inf
        index = -1
        
        one, two = 0, sum(nums)
        
        for i in range(n):
            one = one + nums[i]
            two = two - nums[i]
            one_avg = one//(i+1)
            
            if i == n-1:
                two_avg = 0
            else:
                two_avg = two//(n-i-1)
                
            avg_diff = abs(one_avg-two_avg)
            if avg_diff < min_avg_diff:
                min_avg_diff = avg_diff
                index = i
        return index