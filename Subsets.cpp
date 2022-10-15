class Solution {
    private:
    void Subset(int ind,vector<int>&nums,vector<vector<int>>&ans,vector<int>&res){
        // Base  case
        if(ind>=nums.size()){
            ans.push_back(res);
            return ;
        }
        // Picking up
        res.push_back(nums[ind]);
        Subset(ind+1,nums,ans,res);
        //NotPicking
        res.pop_back();
        Subset(ind+1,nums,ans,res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>res;
    Subset(0,nums,ans,res);
    return ans;
    }
};
