class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        for(auto &i:mp){
            int nud = i.second;
            if(nud == 1) return -1;
            ans += nud/3;
            if(nud%3) ans++;

        }
        return ans;;
    }
};