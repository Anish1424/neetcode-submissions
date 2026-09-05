class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int startIndex= -1; int res = 0;
        vector<int>hash(255,-1);
        for(int i=0;i<n;i++){
            if(hash[s[i]] != -1 && hash[s[i]] > startIndex){
                startIndex = hash[s[i]];
            }
            res = max(res, i - startIndex);
            hash[s[i]] = i;
        }
        return res;
    }
};
