#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

vector<int> ivec;
vector<vector<int>> res;
set<vector<int>> si;
void dfs(int x, int sum, vector<int>& v) {
    if (v.size() == 3) {
        if (sum == 0) {
            vector<int> tmp = v;
            sort(tmp.begin(), tmp.end());
            if (si.find(tmp) != si.end()) return;
            si.insert(tmp);
            res.push_back(tmp);
        }
        return;
    }
    for (int i = x; i < ivec.size(); i++) {
        v.push_back(ivec[i]);
        dfs(i + 1, sum + ivec[i], v);
        v.pop_back();
    }
}
int main() {
    int n;
    vector<int> v;
    while (cin >> n) {
        ivec.push_back(n);
        if (cin.get() == '\n') break;
    }
    dfs(0, 0, v);
    for (int i = res.size() - 1; i >= 0; i--) {
        sort(res[i].begin(), res[i].end());
        for (int j = 0; j < 3; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
