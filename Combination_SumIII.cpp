class Solution {
    private:
    void Helper(int num,int sm,int k,int n,vector<vector<int>>&res,vector<int>&SubSet){
        // Base Case
        if(sm>n) return;
        if(k==0){
            if(sm==n){
                res.push_back(SubSet);
                return;
            }
            return;
        }
        // Base Case
        if(num==10) return;

        //Induction & Hypothetical

        SubSet.push_back(num);
        sm+=num;
        Helper(num+1,sm,k-1,n,res,SubSet);
        //BackTracking
        sm-=num;
        SubSet.pop_back();
        Helper(num+1,sm,k,n,res,SubSet);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>SubSet;
        Helper(1,0,k,n,res,SubSet);
        return res;
    }
};
