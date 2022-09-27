class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        
        output = []
        
        # sort the list so it's not bad
        nums.sort()
        
        # loop through each non-positive number and do 2-sum on it
        for ind, value in enumerate(nums):
            
            # duplicates (also account for initialization case)
            if ind == 0 or nums[ind - 1] != value:
                left = ind + 1
                right = len(nums)-1

                # pointers
                while left < right:
                    
                    if nums[left] + nums[right] == -value:
                        output.append([value, nums[left], nums[right]])
                        
                        # update left pointer
                        while nums[left+1] == nums[left] and left+1 < right:
                            left += 1
                        
                        left += 1
                        
                    elif nums[left] + nums[right] > -value:
                        right -= 1

                    else:
                        left += 1
            
            
        return output