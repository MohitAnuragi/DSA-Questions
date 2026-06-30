class Solution {
public:
    int numberOfSubstrings(string s) {
        int l = 0,ans=0;
        vector<int> freq(3,0);
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            freq[s[i]-'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0)
            {
                ans += n-i;
                freq[s[l]-'a']--;
                l++;
            }
        }
        return ans;
    }
};