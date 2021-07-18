class Solution {
    vector<string> res;
    int length;
    void dfs(int x, string s){
        if(x==length-1){
            res.push_back(s);
            return;
        }
        set<int> si;
        for(int i=x; i<s.size(); i++){
            if(si.find(s[i])!=si.end()) continue;
            si.insert(s[i]);
            swap(s[i],s[x]);
            dfs(x+1, s);
            swap(s[i],s[x]);
        }
    }
public:
    vector<string> permutation(string s) {
        length = s.size();
        dfs(0, s);
        return res;
    }
};
