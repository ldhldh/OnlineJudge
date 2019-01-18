class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 1:
            return 0
        nums.sort()
        max_num = 0
        for i in reversed(nums):
            if i == nums[-1]:max_num += 1
        ret = 0
        i = len(nums)
        while i and max_num + 1 <= len(nums):
            ret += (nums[-1] - nums[-max_num - 1]) * max_num
            nums[-1] = nums[-max_num - 1]
            temp = 0
            if i == 1:
                break
            for j in nums[-max_num - 1::-max_num]:
                if j == nums[-max_num - 1]:
                    temp += 1
            max_num += temp
            i = len(nums) - max_num
        return ret
        