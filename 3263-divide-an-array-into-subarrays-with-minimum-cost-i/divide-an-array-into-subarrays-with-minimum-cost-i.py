class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        # Find the two smallest elements after index 0
        smallest = float('inf')
        second_smallest = float('inf')
        
        for num in nums[1:]:
            if num < smallest:
                second_smallest = smallest
                smallest = num
            elif num < second_smallest:
                second_smallest = num
        
        return nums[0] + smallest + second_smallest
        