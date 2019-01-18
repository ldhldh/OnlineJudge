class Solution:
    def minDeletionSize(self, A):
        """
        :type A: List[str]
        :rtype: int
        """
        def isright(i, l):#第i列是否按照严格字典序（不含相等），这里只比较l中出现的行数
            for j in l:
                if A[j][i] > A[j+1][i]:return 1
            return 0
        def isequal(i, l):#第i列是否有的情况，这里只比较l中出现的行数，有的话返回1和相等的行标号
            flag = 0
            child = []
            for j in l:
                if A[j][i] == A[j+1][i]:
                    child.append(j)
                    flag = 1
            return flag,child
        res = 0
        child = range(len(A)-1)
        for i in range(len(A[0])):
            h = isright(i, child)
            if h == 0:
                eq, child1 = isequal(i, child)
                if eq == 0:return res
                elif eq == 1:
                    child = child1
            res += h
        return res