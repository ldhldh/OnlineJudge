class Solution:
    def maxChunksToSorted(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        ʹ��Ԫ����ȼ��ϣ��б��е�Ԫ���Ǽ��ϲ��Ĺ�ϵ
        """
        unsilp = []
        def Interval_and(l, tuple):
            if l == []:
                l.append(tuple)
                return l
            l.sort()
            for i in range(len(l)):
                if l[i][0] <= tuple[0]:#��һ���࣬ԭ���������������ϸ��Ϊԭ��������һ������������ң�ԭ��������n������������ң����²��������������
                    if l[i][1] >= tuple[1]:
                        return l
                    elif tuple[0] <= l[i][1]:
                        j = i + 1
                        while j < len(l) and tuple[1] >= l[j][0]:
                            j += 1
                        l[i] = (l[i][0], max(tuple[1],l[j -1][1]))
                        if j == i + 1:
                            return l
                        while j != i + 1:
                            del l[j - 1]
                            j -= 1
                        return l
                    if i < len(l) - 1:
                        print(len(l) - 1)
                        continue
                    l.append(tuple)
                    l.sort()
                    return l
                # if tuple[0] < l[i][0]:�ڶ����࣬�²��������������
                if tuple[1] < l[i][0]:
                    l.append(tuple)
                    return l.sort()
                # if tuple[1] >= l[i][0]:
                j = i + 1
                while j < len(l) and tuple[1] >= l[j][0]:
                    j += 1
                l[i] = (tuple[0], max(tuple[1], l[j - 1][1]))
                if j == i + 1:
                    return l
                while j != i + 1:
                    del l[j - 1]
                    j -= 1
                return l
        def isin_Interval(item, l, m=None):#�������
            l.sort
            if m==None:
                for i in l:
                    if item >= i[0] and item <= i[1]:
                        return True
                return False
            # if m!=None:
            for i in l:
                if item > i[0] and item < i[1]:
                    return True
            return False
        for i in range(len(arr)):
            if i != arr[i]:
                unsilp = Interval_and(unsilp, (min(i, arr[i]), max(i, arr[i])))
        res = len(unsilp)
        for i in range(len(arr)):
            if isin_Interval(i,unsilp) == False:
                res += 1
        return res

                        