public class Solution
{
    public int MaxArea(int[] height)
    {
        if (height.Length < 2) return -1;
        int i = 0, j = height.Length - 1, res = 0;
        while (i < j)
        {
            int h =  height[i] <= height[j] ? height[i] : height[j];
            //if((j - i) * h > res)res = (j - i) * h;
            res = (j - i) * h > res ? (j - i) * h : res;
            if (height[i] < height[j]) i++;
            else j--;
        }
        return res;
    }
}