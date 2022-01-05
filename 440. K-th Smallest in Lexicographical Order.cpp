class Solution {
    int64_t count(int64_t n , int64_t prefix){
        if(prefix > n){
            return 0;
        }else if(prefix == n){
           return 1; 
        }
        
        int64_t minPrefix = prefix , maxPrefix = prefix;
        int64_t count = 1;
        while(1){
            minPrefix = 10*minPrefix;
            maxPrefix = 10*maxPrefix + 9;
            if(n < minPrefix)break;
            if(minPrefix <= n && n <= maxPrefix){
                count += (n - minPrefix + 1);
                break;
            }else{
                count += (maxPrefix - minPrefix + 1);
            }
        }
        
        return count;
    }
public:
    int64_t findKthNumber(int64_t n, int64_t k,int64_t prefix = 0) {
        
        for(int i = (prefix == 0 ? 1 : 0) ; i<=9; i++){
            if(k == 0){
                return prefix;
            }
            int64_t numbers_prefix_i_less_n = count(n,prefix*10 + i);
            if(numbers_prefix_i_less_n >= k){
                return findKthNumber(n , k-1 , prefix*10 + i);
            }else{
                k -= numbers_prefix_i_less_n;
            }
        }
        return prefix;
    }
}; 
