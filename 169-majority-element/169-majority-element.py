class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        majority_check = len(nums) // 2
        
        lookup_table = {}
        
        for element in nums:
            
            if element not in lookup_table:
                
                lookup_table[element] = 1
            
            else:
                
                lookup_table[element] += 1
        
        
        for key, value in lookup_table.items():
            
            if value > majority_check:
                
                return key
            
    
        