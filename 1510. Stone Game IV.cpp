class Solution {
public:
    bool winnerSquareGame(int n) {
         vector<int>sq;
        for(int i = 1; i*i<=n; i++){
            sq.push_back(i*i); //precalculating the squares
        }
        
        int dp[n+1];
        dp[0] = false; // 0 stones in pile, the player making the move lose
        for(int i = 1; i<=n; i++){
            bool alice = false;
            for(auto temp : sq){
                if(temp > i)break;
                int d = i - temp;
                if(dp[d] == false){
                    alice = true;
                    dp[i] = true; 
                    break;
                }
            }
            if(!alice){
                dp[i] = false;
            }
        }
        
        return dp[n];
        
    }
};