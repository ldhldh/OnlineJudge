class Solution(object):
    def powerfulIntegers(self, x, y, bound):
        """
        :type x: int
        :type y: int
        :type bound: int
        :rtype: List[int]
        """
        def allnum(a):
            l = []
            if a == 0 or a == 1:
                l.append(a)
                return l
            i = 1
            while(i <= bound):
                l.append(i)
                i *= a
                l.append(a)
            return l
        lx = allnum(x)
        ly = allnum(y)
        ret = []
        for i in lx:
            for j in ly:
                if i + j <= bound:
                    ret.append(i + j)
        return list(set(ret))