class Solution {
    int n;
    
    int solve(int l , int e , vector<int>ones , int prefix[] , int suffix[] ,int pref[] , int suf[]){
                
        int ans = INT_MAX;
        
        for(int temp = l; temp<(int)ones.size()-e; temp++){
            int curr = ones[temp];
            int left = ones[temp-l];
            int right = ones[temp+e];
            
            int i = temp;
            int val = (suffix[left] - suffix[curr] - l*suf[curr]) + (prefix[right] - prefix[curr] - e*pref[curr]);
            ans = min(ans,val);
        }
        
        return ans;
    }
    
public:
    int minMoves(vector<int>& nums, int k) {
        n = nums.size() ;
        int pref[n],suf[n],prefix[n],suffix[n];
        vector<int>ones;
        memset(pref,0,sizeof(pref));
        memset(suf,0,sizeof(suf));
        memset(prefix,0,sizeof(prefix));
        memset(suffix,0,sizeof(suffix));
        
        pref[0] = (nums[0] == 0);
        if(nums[0]){
            ones.push_back(0);
        }
        
        for(int i = 1; i<n; i++){
            pref[i] = pref[i-1] + (nums[i] == 0);
            if(nums[i]){
                ones.push_back(i);
                prefix[i] = pref[i];
            }
        }
        suf[n-1] = (!nums[n-1]);
        for(int i = n-2; i>=0; i--){
            suf[i] = suf[i+1] + (nums[i] == 0);
            if(nums[i]){
                suffix[i] = suf[i];
            }
        }
        
        for(int i = 1; i<n; i++){
            prefix[i] += prefix[i-1];
        }
        
        for(int i = n-2; i>=0; i--){
            suffix[i] += suffix[i+1];
        }
        
        
        k--;
        if(k==0){
            return 0;
        }
        
        
        if(k&1){
            int x = k/2;
            
            return min(solve(x+1,x,ones,prefix,suffix , pref ,suf) , solve(x,x+1,ones,prefix,suffix,pref,suf));
        }else{
            return solve(k/2,k/2,ones,prefix,suffix,pref,suf);
        }
                
    }
};
