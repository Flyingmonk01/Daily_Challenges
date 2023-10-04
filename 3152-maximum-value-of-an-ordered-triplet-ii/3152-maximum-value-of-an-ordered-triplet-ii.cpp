class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int maxDiff = 0;
        int maxi = 0;
        for(int i = 0; i < nums.size(); i++){
            int num = nums[i];
            ans = max(ans, 1LL*maxDiff*num);
            maxDiff = max(maxDiff, maxi-num);
            maxi = max(maxi, num);
        }
        return ans;
    }
};