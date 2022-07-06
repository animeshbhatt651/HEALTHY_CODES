class Solution {
public:
            int removeElement(vector<int>& nums, int val) {
        int MAX = INT_MAX;
        int cnt = nums.size();
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == val){
                nums[i] = MAX;
                cnt--;
            }   
        }
        sort(nums.begin(), nums.end());
        return cnt;
    }
        
};