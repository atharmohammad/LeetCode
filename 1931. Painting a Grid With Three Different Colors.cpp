#define MOD 1000000007

int dp[100][1005];
map<int,vector<int>>G;
vector<string>comb;
void generate(string s , char prev , int m){
    if(m == 0){
        comb.push_back(s);
        return;
    }
    
    string str = "RGB";
    for(auto temp : str){
        if(temp != prev){
            generate(s+temp,temp,m-1);
        }
    }
    
    return ;
}

int solve(int u , int n){
    if(n == 0)return 1;
    
    if(dp[u][n] != -1)return dp[u][n];
    
    int ans = 0;
    for(auto v : G[u]){
        ans = ((ans + solve(v,n-1))%MOD);
    }
    
    return dp[u][n] = ans;
    
}

class Solution {
public:
    int colorTheGrid(int m, int n) {
        G.clear();
        comb.clear();
        memset(dp,-1,sizeof(dp));
        generate("",'#',m);
        int states = (int)comb.size();
        int ans = 0 ;
        for(int i = 0 ; i<states; i++){
            for(int j = 0  ; j<states ; j++){
                bool isOk = true;
                for(int k = 0; k<m; k++){
                    if(comb[i][k] == comb[j][k]){
                        isOk = false;
                        break;
                    }
                }
                if(isOk){
                    G[i].push_back(j);
                }
            }
        }

        for(int i = 0 ; i<states; i++){
            ans = ((ans + solve(i,n-1))%MOD);
        }
        
        return ans;
        
    }
};