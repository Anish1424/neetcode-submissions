class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 1;
        int j= numbers.size();
        while(i<j){
            if(numbers[i-1] + numbers[j-1] == target){
                return {i,j};
            }
            else if(numbers[i-1] + numbers[j-1] < target){
                i++;
            }
            else{
                j--;
            }
        }
        return {};
    }
};
