class Solution {
    bool check(string &s,string &t , int k){
        int index = 0,count = 0;
        for(int i = 0; i<(int)s.size(); i++){
            if(s[i] == t[index]){
                index++;
                if(index == (int)t.size()){
                    count++;
                    index = 0;
                    if(count == k){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        queue<string>q;
        q.push("");
        string ans = "";
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(int i = 0; i<26; i++){
                string temp = node + (char)('a' + i);
                if(check(s,temp,k)){
                    ans = temp;
                    q.push(temp);
                    // cout<<temp<<'\n';
                }
            }
        }
        return ans;
    }
};