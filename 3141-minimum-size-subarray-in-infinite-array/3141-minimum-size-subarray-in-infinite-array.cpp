class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        long long numsSum = accumulate(nums.begin(), nums.end(), 0LL);
        int q = target/numsSum;
        int rem = target%numsSum;

        if(!rem) return q*nums.size();

        vector<int> temp = nums;
        for(auto &x:nums) temp.push_back(x);
        long long sum = 0;
        int j = 0;
        int ans = INT_MAX;
        for(int i = 0; i < temp.size(); i++){
            sum += temp[i];
            while(sum > rem){
                sum -= temp[j++];
            }
            if(sum == rem){
                ans = min(ans, i-j+1);
            }
        }
        if(ans == INT_MAX) return -1;
        return q*nums.size() + ans;
    }
};