int maxArea(int* height, int heightSize) {
    if(heightSize < 2) return -1;
    int res = 0, i = 0, j = heightSize - 1;
    while(i<j){
        int h = height[i]<=height[j]?height[i]:height[j];
        if(h*(j-i)>res)res = h*(j-i);
        if(height[i]<height[j])i++;
        else j--;
    }
    return res;
}