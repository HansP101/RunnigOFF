class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {   
        int start=0;              
        int end=nums.size()-1;  
        while(start<=end)
        {
            int k = (start+end)/2;                   
            if (target<nums[k]) end = k-1;      
            else if (target>nums[k]) start = k+1; 
            else return k;
        }
        return start;
    }
};
