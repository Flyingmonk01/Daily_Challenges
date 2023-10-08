class Solution {
public:
    vector<vector<int>> dp;
    int maxDotProductHelper(vector<int>& nums1, vector<int>& nums2, int i, int j){
        if(i >= nums1.size() || j >= nums2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int inc = nums1[i]*nums2[j] + maxDotProductHelper(nums1, nums2, i+1, j+1);

        int exc = max(maxDotProductHelper(nums1, nums2, i+1, j), maxDotProductHelper(nums1, nums2, i, j+1));
        return dp[i][j] = max(inc, exc);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int max1 = INT_MIN, max2 = INT_MIN, min1 = INT_MAX, min2 = INT_MAX;
        for(auto i:nums1){
            max1 = max(max1, i);
            min1 = min(min1, i);
        }
        for(auto i:nums2){
            max2 = max(max2, i);
            min2 = min(min2, i);
        }
        if(min1 > 0 && max2 < 0) return min1*max2;
        if(min2 > 0 && max1 < 0) return min2*max1;
        dp = vector<vector<int>> (nums1.size()+1, vector<int>(nums2.size()+1, -1));
        return maxDotProductHelper(nums1, nums2, 0, 0);
    }
};