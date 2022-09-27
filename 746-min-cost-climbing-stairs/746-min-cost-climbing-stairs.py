class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0] * len(cost)
        
        dp[0] = cost[0]
        dp[1] = cost[1]
        
        for ind, val in enumerate(cost[2:]):
            dp[ind+2] = val+min(dp[ind+1], dp[ind])
            
        return min(dp[-1], dp[-2])