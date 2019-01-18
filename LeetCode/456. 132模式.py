class Solution:
    def find132pattern(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        if len(nums) < 3: return False
        flag = 0
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                flag = 1
        if flag == 0:
            return False
        Candidate_13 = {}
        Candidate_1 = nums[0]
        def isTrue(n, d):
            for key in d:
                if n > key and n < d[key]:return True
            return False
        for i in nums:
            if i <= Candidate_1:Candidate_1 = i
            elif isTrue(i, Candidate_13) :
                    return True
            if i > Candidate_1 + 1:
                if Candidate_13.get(Candidate_1) and i < Candidate_13.get(Candidate_1):
                    continue
                Candidate_13[Candidate_1] = i
        return False