class Solution(object):
    def canSortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        for i in range(len(nums)):
            for j in range(len(nums)-1):
                if bin(nums[j]).count('1')==bin(nums[j+1]).count('1') and nums[j+1]<nums[j]:
                    nums[j],nums[j+1]=nums[j+1],nums[j]
        return nums==sorted(nums)
        