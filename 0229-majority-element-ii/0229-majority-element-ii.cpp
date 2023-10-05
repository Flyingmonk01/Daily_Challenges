class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // unordered_map<int, int> mp;
        // vector<int> ans;
        // int val = nums.size()/3;
        // for(int i = 0; i < nums.size(); i++){
        //     mp[nums[i]]++;
        // }
        // for(auto &i:mp){
        //     if(i.second > val){
        //         ans.push_back(i.first);
        //     }
        // }
        // return ans;
        vector<int> ans;
        int num1 = 0, num2 = 1, c1 = 0, c2 = 0;
        for(auto &num : nums){
            if(num == num1){
                c1++;
            }
            else if(num == num2){
                c2++;
            }
            else if(c1 == 0){
                num1 = num;
                c1 = 1;
            }
            else if(c2 == 0){
                num2 = num;
                c2 = 1;
            }
            else{
                c1--, c2--;
            }
        }
        if(count(nums.begin(), nums.end(), num1) > nums.size()/3){
            ans.push_back(num1);
        }
        if(count(nums.begin(), nums.end(), num2) > nums.size()/3){
            ans.push_back(num2);
        }
        return ans;
    }
};