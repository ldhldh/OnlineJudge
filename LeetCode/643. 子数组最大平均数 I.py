class Solution:
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """
        key_max = 0
        value = 0
        for i in range(k):
            value += nums[i]
        value_max = value
        for i in range(1,len(nums) - k + 1):
            value = value - nums[i-1] + nums[i+k-1]
            value_max = max(value_max, value)
        return value_max/k