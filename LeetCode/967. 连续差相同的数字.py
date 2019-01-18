class Solution:
    def numsSameConsecDiff(self, N, K):
        """
        :type N: int
        :type K: int
        :rtype: List[int]
        """ 
        Law = list(range(10))
        if N == 1:
            return Law
        Dict = []
        for i in Law:
            temp = []
            if i - K in Law:
                temp.append(str(i - K))
            if i + K in Law:
                temp.append(str(i + K))
            Dict.append(temp)

        res = []
        def work(s, num):
            if s and s[0] == '0':
                s = s[1:]
            if len(s) == N:
                res.append(int(s))
                return
            if len(Dict[num]) == 0:
                return
            if len(Dict[num]) == 1:
                work(s + Dict[num][0], int(Dict[num][0]))
            if len(Dict[num]) == 2:
                work(s + Dict[num][0], int(Dict[num][0]))
                work(s + Dict[num][1], int(Dict[num][1]))

        for i in list(range(1, 10)):
            work('', i)
        res = list(set(res))
        return res