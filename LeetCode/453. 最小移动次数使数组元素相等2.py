class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        与一开始思路相同，该表达式是经过数学化简，消项以后的结果！
        """
        return sum(nums) - len(nums) * min(nums)