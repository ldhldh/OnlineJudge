import re
class Solution:
    def spellchecker(self, wordlist, queries):
        """
        报错案例：
        输入：
            ["wg","uo","as","kv","ra","mw","gi","we","og","zu"]
            ["AS","in","yc","kv","mw","ov","lc","os","wm","Mw"]
        输出：
            ["as","","","kv","mw","kv","","as","","mw"]
        预期：
            ["as","","","kv","mw","","","as","","mw"]
        :type wordlist: List[str]
        :type queries: List[str]
        :rtype: List[str]
        """
        d1 = {}
        d2 = {}
        for word in wordlist:
            d1[word] = word
            if not d2.get(word.lower()):
                d2[word.lower()] = word
        
        def Query(query):
            r = d1.get(query)
            if r:
                return r
            r = d2.get(query.lower())
            if r:
                return r
            # pattern = re.sub('[aeiouAEIOU]','.',query)
            pattern1 = re.sub('[aeiou]','.',query.lower())
            # for word in wordlist:
            #     if re.match(pattern, word):
            #         return d1[word]
            for word in d2.keys():
                if re.match(pattern1, word):
                    return d2[word]
            return ''
        
        res = []
        for query in queries:
            res.append(Query(query))
        return res
            
                