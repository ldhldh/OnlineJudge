class Solution(object):
    def pancakeSort(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        B = sorted(A)
        if A == B:
            return []
        ret = []
        for i in B[::-1]:
            index = A.index(i)
            if index != 0:
                ret.append(index + 1)
            if len(A) == 1:
                return ret
            ret.append(len(A))
            A = A[index+1:][::-1] + A[:index]
        return ret
            