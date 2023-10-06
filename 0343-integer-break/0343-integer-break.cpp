class Solution {
public:
    vector<int> dp;
    int helper(int n){
        if(n <= 3) return n;
        if(dp[n] != -1) return dp[n];
        int ans = n;

        for(int i = 2; i <= n; i++){
            ans = max(ans, i*helper(n-i));
        }
        return dp[n] = ans;
    }

    int integerBreak(int n) {
        if(n <= 3) return n-1;
        dp = vector<int>(n+1, -1);
        return dp[n] = helper(n);
        // return tab(n);
    }
};