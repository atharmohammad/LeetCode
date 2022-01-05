bool cmp(vector<int>const&a , vector<int>const&b){
    if((a[1]-a[0]) == (b[1] - b[0])){
        return (a[1] > b[1]);
    }
    return (a[1]-a[0]) > (b[1] - b[0]);
}
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),cmp);
        int64_t ans = 0,left = 0;
        for(auto temp : tasks){
            if(temp[1] > left){
                int64_t add = 0;
                add += (temp[1] - left);
                left = (temp[1] - temp[0]);
                ans += add;
            }else{
                left -= temp[0];
            }
        }
        return ans;
    }
};

// (1,7);(5,9);(2,3);(1,2);(2,2)
//   6     4     1     1     0
// 7 + 3 + 0 



