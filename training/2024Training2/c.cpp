#include <bits/stdc++.h>

using namespace std;
const int maxn = 13, maxm = 13;
string sta[maxn];
struct cube{
    string str[maxn];
    cube() {
        for(int i = 1; i <= 9; i ++) str[i] = sta[i];
    }
    void read() {
        for(int i = 1; i <= 9; i ++) cin >> str[i];
        string x = "$";
        for(int i = 1; i <= 9; i ++) str[i] = x + str[i];
    }
    int cmp() {
        int cnt = 0;
        for(int i = 1; i <= 9; i ++) {
            for(int j = 1; j <= 12; j ++) if(str[i][j] != sta[i][j]) cnt ++;
        }
        return cnt;
    }
    void Top() {
        string ptr[maxn];
        for(int i = 1; i <= 9; i ++) ptr[i] = str[i];
        ptr[4][4] = str[6][4], ptr[4][5] = str[5][4], ptr[4][6] = str[4][4];
        ptr[5][6] = str[4][5], ptr[6][6] = str[4][6];
        ptr[6][5] = str[5][6], ptr[6][4] = str[6][6], ptr[5][4] = str[6][5];
        ptr[3][4] = str[6][3], ptr[3][5] = str[5][3], ptr[3][6] = str[4][3];
        ptr[4][7] = str[3][4], ptr[5][7] = str[3][5], ptr[6][7] = str[3][6];
        ptr[7][6] = str[4][7], ptr[7][5] = str[5][7], ptr[7][4] = str[6][7];
        ptr[6][3] = str[7][6], ptr[5][3] = str[7][5], ptr[4][3] = str[7][4];
        for(int i = 1; i <= 9; i ++) str[i] = ptr[i];
    }
    void Topi() {
        Top(), Top(), Top();
    }
    void Left() {
        string ptr[maxn];
        for(int i = 1; i <= 9; i ++) ptr[i] = str[i];
        ptr[4][1] = str[6][1], ptr[4][2] = str[5][1], ptr[4][3] = str[4][1];
        ptr[5][3] = str[4][2], ptr[6][3] = str[4][3];
        ptr[6][2] = str[5][3], ptr[6][1] = str[6][3], ptr[5][1] = str[6][2];
        ptr[1][4] = str[6][12], ptr[2][4] = str[5][12], ptr[3][4] = str[4][12];
        ptr[4][4] = str[1][4], ptr[5][4] = str[2][4], ptr[6][4] = str[3][4];
        ptr[7][4] = str[4][4], ptr[8][4] = str[5][4], ptr[9][4] = str[6][4];
        ptr[6][12] = str[7][4], ptr[5][12] = str[8][4], ptr[4][12] = str[9][4];
        for(int i = 1; i <= 9; i ++) str[i] = ptr[i];
    }
    void Lefti() {
        Left(), Left(), Left();
    }
    void Right() {
        string ptr[maxn];
        for(int i = 1; i <= 9; i ++) ptr[i] = str[i];
        ptr[4][7] = str[6][7], ptr[4][8] = str[5][7], ptr[4][9] = str[4][7];
        ptr[5][9] = str[4][8], ptr[6][9] = str[4][9];
        ptr[6][8] = str[5][9], ptr[6][7] = str[6][9], ptr[5][7] = str[6][8];
        ptr[1][6] = str[4][6], ptr[2][6] = str[5][6], ptr[3][6] = str[6][6];
        ptr[4][6] = str[7][6], ptr[5][6] = str[8][6], ptr[6][6] = str[9][6];
        ptr[7][6] = str[6][10], ptr[8][6] = str[5][10], ptr[9][6] = str[4][10];
        ptr[6][10] = str[1][6], ptr[5][10] = str[2][6], ptr[4][10] = str[3][6];
        for(int i = 1; i <= 9; i ++) str[i] = ptr[i];
    }
    void Righti() {
        Right(), Right(), Right();
    }
    void Front() {
        string ptr[maxn];
        for(int i = 1; i <= 9; i ++) ptr[i] = str[i];
        ptr[7][4] = str[9][4], ptr[7][5] = str[8][4], ptr[7][6] = str[7][4];
        ptr[8][6] = str[7][5], ptr[9][6] = str[7][6];
        ptr[9][5] = str[8][6], ptr[9][4] = str[9][6], ptr[8][4] = str[9][5];
        ptr[6][1] = str[6][10], ptr[6][2] = str[6][11], ptr[6][3] = str[6][12];
        ptr[6][4] = str[6][1], ptr[6][5] = str[6][2], ptr[6][6] = str[6][3];
        ptr[6][7] = str[6][4], ptr[6][8] = str[6][5], ptr[6][9] = str[6][6];
        ptr[6][10] = str[6][7], ptr[6][11] = str[6][8], ptr[6][12] = str[6][9];
        for(int i = 1; i <= 9; i ++) str[i] = ptr[i];
    }
    void Fronti() {
        Front(), Front(), Front();
    }
    void Back() {
        string ptr[maxn];
        for(int i = 1; i <= 9; i ++) ptr[i] = str[i];
        ptr[1][4] = str[3][4], ptr[1][5] = str[2][4], ptr[1][6] = str[1][4];
        ptr[2][6] = str[1][5], ptr[3][6] = str[1][6];
        ptr[3][5] = str[2][6], ptr[3][4] = str[3][6], ptr[2][4] = str[3][5];
        ptr[4][1] = str[4][4], ptr[4][2] = str[4][5], ptr[4][3] = str[4][6];
        ptr[4][4] = str[4][7], ptr[4][5] = str[4][8], ptr[4][6] = str[4][9];
        ptr[4][7] = str[4][10], ptr[4][8] = str[4][11], ptr[4][9] = str[4][12];
        ptr[4][10] = str[4][1], ptr[4][11] = str[4][2], ptr[4][12] = str[4][3];
        for(int i = 1; i <= 9; i ++) str[i] = ptr[i];
    }
    void Backi() {
        Back(), Back(), Back();
    }
    void Bottom() {
        string ptr[maxn];
        for(int i = 1; i <= 9; i ++) ptr[i] = str[i];
        ptr[4][10] = str[6][10], ptr[4][11] = str[5][10], ptr[4][12] = str[4][10];
        ptr[5][12] = str[4][11], ptr[6][12] = str[4][12];
        ptr[6][11] = str[5][12], ptr[6][10] = str[6][12], ptr[5][10] = str[6][11];
        ptr[1][4] = str[4][9], ptr[1][5] = str[5][9], ptr[1][6] = str[6][9];
        ptr[4][1] = str[1][6], ptr[5][1] = str[1][5], ptr[6][1] = str[1][4];
        ptr[9][4] = str[4][1], ptr[9][5] = str[5][1], ptr[9][6] = str[6][1];
        ptr[6][9] = str[9][4], ptr[5][9] = str[9][5], ptr[4][9] = str[9][6];
        for(int i = 1; i <= 9; i ++) str[i] = ptr[i];
    }
    void Bottomi() {
        Bottom(), Bottom(), Bottom();
    }
    void print() {
        cout << "--------My Cube----------\n";
        for(int i = 1; i <= 9; i ++) {
            cout << str[i] << endl;
        }
        cout << "-------------------------\n";
    }
};
bool flag;
vector<pair<int, int>> dir[8];
#define fir first
#define sec second
void dfs(int k, cube cu) {
    if(flag) return ;
    if(k == 3) {
        int cnt = cu.cmp();
        if(cnt > 2) return ;
        flag = 1;
        if(cnt == 0) return cout << "No problem\n", void();
        if(cnt == 2) {
            vector<int> ans;
            for(int i = 0; i < 8; i ++) {
                bool fou = 0;
                for(auto it : dir[i]) {
                    int x = it.fir, y = it.sec;
                    if(cu.str[x][y] != sta[x][y]) fou = 1;
                }
                if(fou) {
                    for(auto it : dir[i]) {
                        int x = it.fir, y = it.sec;
                        ans.push_back(sta[it.fir][it.sec] - '0');
                    }
                    break;
                }
            }
            sort(ans.begin(), ans.end());
            for(auto it : ans) cout << it << " ";
            return cout << endl, void();
        }
        return ;
    }
    dfs(k + 1, cu);

    cu.Front();
    dfs(k + 1, cu);
    cu.Fronti(), cu.Fronti();
    dfs(k + 1, cu);
    cu.Front();

    cu.Back();
    dfs(k + 1, cu);
    cu.Backi(), cu.Backi();
    dfs(k + 1, cu);
    cu.Back();

    cu.Top();
    dfs(k + 1, cu);
    cu.Topi(), cu.Topi();
    dfs(k + 1, cu);
    cu.Top();

    cu.Left();
    dfs(k + 1, cu);
    cu.Lefti(), cu.Lefti();
    dfs(k + 1, cu);
    cu.Left();

    cu.Right();
    dfs(k + 1, cu);
    cu.Righti(), cu.Righti();
    dfs(k + 1, cu);
    cu.Right();

    cu.Bottom();
    dfs(k + 1, cu);
    cu.Bottomi(), cu.Bottomi();
    dfs(k + 1, cu);
    cu.Bottom();
}
void check() {
    cube x;
    x.read();
    flag = 0;
    // x.Front();
    // x.Fronti();
    // x.print();    
    dfs(0, x);
}
int main() {
    for(int i = 1; i <= 3; i ++) sta[i] = "$***111******";
    for(int i = 4; i <= 6; i ++) sta[i] = "$222333444555";
    for(int i = 7; i <= 9; i ++) sta[i] = "$***666******";
    dir[0].push_back({3, 4}), dir[0].push_back({4, 3}), dir[0].push_back({4, 4});
    dir[1].push_back({3, 6}), dir[1].push_back({4, 6}), dir[1].push_back({4, 7});
    dir[2].push_back({6, 3}), dir[2].push_back({6, 4}), dir[2].push_back({7, 4});
    dir[3].push_back({6, 6}), dir[3].push_back({6, 7}), dir[3].push_back({7, 6});
    dir[4].push_back({1, 4}), dir[4].push_back({4, 1}), dir[4].push_back({4, 12});
    dir[5].push_back({1, 6}), dir[5].push_back({4, 9}), dir[5].push_back({4, 10});
    dir[6].push_back({6, 1}), dir[6].push_back({6, 12}), dir[6].push_back({9, 4});
    dir[7].push_back({6, 9}), dir[7].push_back({6, 10}), dir[7].push_back({9, 6});
    cube test;
    int T;
    cin >> T;
    while(T --) {
        check();
    }
    return 0;
}
/*
***111******
***111******
***223******
226332144555
226333144555
226333144555
***444******
***666******
***666******
*/