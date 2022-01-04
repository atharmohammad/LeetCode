class Solution {
    int solve(int i , vector<int>&stoneValue , int chance , int dp[][2]){
      int n = (int)stoneValue.size();
        if(n == i){ // end of vector we return 0;
            return 0;
        }
        
        if(dp[i][chance] != -1){
            return dp[i][chance];
        }
        
        int64_t score ;
        if(chance == 0){
            int64_t sum = 0 , alice = INT_MIN;
            for(int j = i; j<min(i+3,n); j++){
                sum += stoneValue[j];
                alice = max(alice,sum+solve(j+1,stoneValue,1,dp));
            }
            score = alice;
        }else{
            int64_t sum = 0 , bob = INT_MAX;
            for(int j = i; j<min(i+3,n); j++){
                sum += stoneValue[j];
                bob = min(bob,-1*sum + solve(j+1,stoneValue,0,dp));
            }
            score = bob;
        }
        
        return dp[i][chance] = score;
         
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int dp[50005][2];
        memset(dp,-1,sizeof(dp));
        
        int score = solve(0,stoneValue,0,dp); // 0 flag
        if( score == 0){
            return "Tie";
        }
        
        return (score > 0 ? "Alice" : "Bob");
        
    }
};