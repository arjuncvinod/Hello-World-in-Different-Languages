// question link = https://leetcode.com/problems/continuous-subarray-sum/submissions/


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int, int> mapper;
        if(nums.size() == 1){
            return false;
        }
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            nums[i] = sum;
            int rem = sum % k;
            mapper[rem] = -1;
            
        }
        if(sum %k == 0) return true;
        
        for(int i=0; i<nums.size(); i++) {
            int rem = nums[i] % k;
            // nums[i] = rem;
            // cout<<"Rem: "<<rem<<endl;
            if(rem == 0 && i!=0)    return true;
            if(mapper[rem] == -1) {
                mapper[rem] = i;
            } else {
                // cout<<"i: "<<i<<endl;
                // cout<<"mapper[rem]: "<<mapper[rem]<<endl;
                if((i - mapper[rem]) >= 2) {
                    return true;
                }
            }
        }
        return false;
    }
};