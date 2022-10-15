class Solution{
    bool isSafe(int x,int y,vector<vector<int>>&visited,vector<vector<int>>&m,int n){
        if(x>=0 && x<n && y>=0 && y<n && visited[x][y]==0 && m[x][y]==1){
            return true;
        }
        else
        {
            return false;
        }
    }
    private:
    void RatInTheMaze(vector<vector<int>>&m,int n, vector<string>&ans,string &res, vector<vector<int>>&visited,int x,int y){
            if(x==n-1 && y==n-1){
                ans.push_back(res);
                return;
            }
            
            
            // visited
            visited[x][y]=1;
            
            // move Down
            int newX=x+1;
            int newY=y;
            if(isSafe(newX,newY,visited,m,n)){
                res.push_back('D');
                RatInTheMaze(m,n,ans,res,visited,newX,newY);
                res.pop_back();
                
            }
            // move Up
             newX=x-1;
             newY=y;
            if(isSafe(newX,newY,visited,m,n)){
                res.push_back('U');
                RatInTheMaze(m,n,ans,res,visited,newX,newY);
                res.pop_back();
                
            }
            // move Right
             newX=x;
             newY=y+1;
            if(isSafe(newX,newY,visited,m,n)){
                res.push_back('R');
                RatInTheMaze(m,n,ans,res,visited,newX,newY);
                res.pop_back();
                
            }
            // move Left
             newX=x;
             newY=y-1;
            if(isSafe(newX,newY,visited,m,n)){
                res.push_back('L');
                RatInTheMaze(m,n,ans,res,visited,newX,newY);
                res.pop_back();
                
            }
            
            // backtreacking
            visited[x][y]=0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
          vector<string>ans;
          // corner Case
          if(m[0][0]==0){
              return ans;
          }
          string res="";
          vector<vector<int>>visited=m;
          for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                  visited[i][j]=0;
              }
          }
          int scrx=0;
          int scry=0;
          RatInTheMaze(m,n,ans,res,visited,scrx,scry);
          sort(ans.begin(),ans.end());
          return ans;
    }
};
