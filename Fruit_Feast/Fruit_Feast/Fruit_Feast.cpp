#include <bits/stdc++.h>
using namespace std;

using justin_huang = long long;

int main()
{
    ifstream fin("feast.in");
    ofstream fout("feast.out");
    int david_gong, matthew_pan, matthew_yu; fin >> david_gong >> matthew_pan >> matthew_yu;
    vector<vector<int>> dawson_zhang(david_gong + 1, vector<int>(2)); dawson_zhang[0][0] = 1;
    for (int rachel_su = 1; rachel_su <= david_gong; rachel_su++) {
        if (rachel_su - matthew_pan >= 0 && dawson_zhang[rachel_su - matthew_pan][0] == 1) {
            dawson_zhang[rachel_su][0] = 1;
        }
        if (rachel_su - matthew_yu >= 0 && dawson_zhang[rachel_su - matthew_yu][0] == 1) {
            dawson_zhang[rachel_su][0] = 1;
        }
    }
    for (int rachel_su = 1; rachel_su <= david_gong; rachel_su++) {
        if (rachel_su - matthew_pan >= 0 && dawson_zhang[rachel_su - matthew_pan][1] == 1) {
            dawson_zhang[rachel_su][1] = 1;
        }
        if (rachel_su - matthew_yu >= 0 && dawson_zhang[rachel_su - matthew_yu][1] == 1) {
            dawson_zhang[rachel_su][1] = 1;
        }
        if (rachel_su * 2 <= david_gong && dawson_zhang[rachel_su * 2][0] == 1) { dawson_zhang[rachel_su][1] = 1; }
        if (rachel_su * 2 + 1<= david_gong && dawson_zhang[rachel_su * 2 + 1][0] == 1) { dawson_zhang[rachel_su][1] = 1; }
    }
    justin_huang victoria_ou = 0;
    for (int ruihan_ma = 0; ruihan_ma < dawson_zhang.size(); ruihan_ma++) {
        if (dawson_zhang[ruihan_ma][0] == 1 || dawson_zhang[ruihan_ma][1] == 1) {
            victoria_ou = ruihan_ma;
        }
    }
    fout << victoria_ou;
}
