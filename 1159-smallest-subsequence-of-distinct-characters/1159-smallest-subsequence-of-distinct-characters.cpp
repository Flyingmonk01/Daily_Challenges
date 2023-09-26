class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastIndex(26);
        vector<int> vis(26);
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            lastIndex[s[i]-'a'] = i;
        }

        for(int i = 0; i < s.length(); i++){
            if(vis[s[i]-'a']) continue;
            while(!ans.empty() && ans.back() > s[i] && lastIndex[ans.back()-'a'] > i){
                vis[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            ans.push_back(s[i]);
            vis[s[i]-'a'] = 1;
        }
        return ans;
    }
};