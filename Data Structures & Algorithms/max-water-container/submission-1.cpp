class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxWater = 0;
        int n = heights.size();
        int left = 0; int right = n- 1;
        while(left < right){
            int width = right - left;
            int containerHeight = min(heights[left],heights[right]);
            maxWater = max(maxWater, width * containerHeight);

            if(heights[left] < heights[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return maxWater;
    }
};
