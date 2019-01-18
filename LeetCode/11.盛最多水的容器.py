class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        i = 0
        j = len(height)-1
        res = 0;
        if j < 1: return -1;
        while(i < j):
            h = min(height[i],height[j])
            res = h*(j-i) if h*(j-i) > res else res
            if height[i] < height[j]:i+=1
            else: j-=1
        return res