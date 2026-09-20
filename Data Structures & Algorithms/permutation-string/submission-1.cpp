class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if(n > m) return false;

        vector<int>hash_s1(26,0);
        for(char ch : s1){
            hash_s1[ch-'a']++;
        }

        vector<int>hash_s2(26,0);
        for(int i=0;i<n;i++){
            hash_s2[s2[i]-'a']++;
        }

        if(hash_s1 == hash_s2){
                return true;
        }

        int j=n;
        while(j < m){
            hash_s2[s2[j-n] - 'a']--;
            hash_s2[s2[j] - 'a']++;
            if(hash_s1 == hash_s2){
                return true;
            }
            j++;
        }
        return false; 
    }
};
