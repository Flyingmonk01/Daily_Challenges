class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<bool> temp(k+1, false);
        int cnt = 0;
        while(!nums.empty()){
            int a = 0;
            int num = nums.back();
            nums.pop_back();
            temp[num] = true;
            cnt++;
            for(int i = 1; i <= k; i++){
                if(temp[i] == 1){
                    a++;
                }
            }
            if(a == k) break;
        }
        return cnt;
    }
};