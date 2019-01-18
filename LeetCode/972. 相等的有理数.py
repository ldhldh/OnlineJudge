class Solution(object):
    def isRationalEqual(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        def std(SS):
            if '.' not in SS:
                SS += '.'
            while (SS[0] == '0' and len(SS.split('.')[0]) != 1):
                SS = SS[1:]
            while(SS[-1] == '0'):
                SS = SS[:-1]
            if '(' in SS and ')' in SS and int(SS.split('(')[1].split(')')[0]) == 0:
                SS = SS.split('(')[0]
            return SS
        
        def std1(SS):
            if '(' not in SS and ')' not in SS :
                if SS[-1] == '.':
                    SS = str(int(SS[:-1]) - 1) + '.' + '(9)'
                    return SS
                SS = SS[:-1] + str(int(SS[-1]) - 1) + '(9)'
                return SS
            return SS
        
        S = std(S)
        T = std(T)
        if S == T:
            return True        
        if '(' not in S and ')' not in S and '(' not in T and ')' not in T:
            if len(S.split('.')[0]) == len(T.split('.')[0]) and int(S.replace('.','')) == int(T.replace('.','')):
                return True
            return False
       
        s = std1(S)
        t = std1(T)
        s = s.split('(')[0] + s.split('(')[1].split(')')[0] * 20
        t = t.split('(')[0] + t.split('(')[1].split(')')[0] * 20
        
        if s[:20] == t[:20]:
            return True
        return False
  