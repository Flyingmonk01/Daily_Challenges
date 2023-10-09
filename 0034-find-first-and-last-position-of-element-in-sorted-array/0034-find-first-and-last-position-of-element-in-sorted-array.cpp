int firstOcc(vector<int>& nums, int target){
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(nums[mid] == target){
            ans = mid;
            e = mid - 1;
        }
        else if(nums[mid]<target){
            s = mid + 1;
        }
        else if(nums[mid]>target){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}
int lastOcc(vector<int>& nums, int target){
    int s = 0;
    int e = nums.size()-1;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s<=e){
        if(nums[mid] == target){
            ans = mid;
            s = mid + 1;
        }
        else if(nums[mid]<target){
            s = mid + 1;
        }
        else if(nums[mid]>target){
            e = mid - 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> p;
        p.push_back(firstOcc(nums, target));
        p.push_back(lastOcc(nums,target));
        return p;
    }
};