class Solution:
    def minMoves(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        ��һ��ʼ˼·��ͬ���ñ��ʽ�Ǿ�����ѧ���������Ժ�Ľ����
        """
        return sum(nums) - len(nums) * min(nums)