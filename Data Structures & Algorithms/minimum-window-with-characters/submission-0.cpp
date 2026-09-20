class Solution {
public:
    string minWindow(string s, string t) {
        int count_req = t.length();
        int n = s.length();

        unordered_map<char,int>mp;
        for(char ch : t){
            mp[ch]++;
        }

        int i =0, j=0;
        int minStart = 0;
        int minWindow = INT_MAX;
        while(j < n){
            char ch = s[j];
            if(mp.find(ch) != mp.end() && mp[ch] > 0){
                count_req--;
            }
            mp[ch]--;

            while(count_req == 0){
                if(minWindow > j-i+1){
                    minWindow = j-i+1;
                    minStart = i;
                }

                char ch_i = s[i];
                mp[ch_i]++;
                if(mp[ch_i] > 0){
                    count_req++;
                }
                i++;    
            }
            
            j++;
        }

        return minWindow == INT_MAX ? "" : s.substr(minStart,minWindow); 
    }
};
