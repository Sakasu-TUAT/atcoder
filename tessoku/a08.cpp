#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <cmath>
#include <iomanip>
#include <limits>
#include <deque>
#include <set>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;
using ll = long long;
#define rep(i,a,b) for (int i = (a); i < int(b); i++)


template<class T> 
class Sum2D {
using ull = unsigned long long int;

public:
    Sum2D(const std::vector<std::vector<T>>& _tb)
        :   h(_tb.size()), w(_tb[0].size()), tb_(_tb)
    {
        init();
    }

    inline void init(){
        sum2DTable.resize(h+1, std::vector<T>(w+1, 0));
        for(int i=1; i<h+1; i++){
            for(int j=1; j<w+1; j++){
                   sum2DTable[i][j] = sum2DTable[i][j-1] + tb_[i-1][j-1];
            }
        }    
        for(int i=1; i<h+1; i++){
            for(int j=1; j<w+1; j++){
                   sum2DTable[i][j] = sum2DTable[i][j] + sum2DTable[i-1][j];
            }
        }    
    }

    inline T calc(std::pair<T, T> p1, std::pair<T, T> p2){
        T ans = + sum2DTable[p2.first][p2.second] 
                - sum2DTable[p2.first][p1.second-1] 
                - sum2DTable[p1.first-1][p2.second] 
                + sum2DTable[p1.first-1][p1.second-1];   
        return ans;
    }

    inline void showTable(){
        for(const auto &v : sum2DTable){
            for(const auto &e : v){
                std::cerr << e << " ";
            }
            std::cerr << std::endl;
        }
    }

private: 
    ull h, w;
    std::vector<std::vector<T>> tb_;
    std::vector<std::vector<T>> sum2DTable;
};

int main(){
    int h, w; cin >> h >> w;
    vector<vector<int>> table(h, vector<int>(w));
    rep(i, 0, h){
        rep(j, 0, w){
            cin >> table[i][j];
        }
    }  

    Sum2D<int> sum(table);

    int q; cin >> q;
    rep(i,0,q){
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << sum.calc({a,b}, {c,d}) << endl;
    }
    sum.showTable();

    return 0;
}