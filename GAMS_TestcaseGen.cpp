#include<bits/stdc++.h>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
#endif
    int r, c, u, p, m;
    /*
    r -> number of rows (each row crane doesnt work then find the min/max or something)
    c -> number of columns
    u -> number of unava slots
    p -> number of pools I want to create for the trucks to go to various cities
    m -> number of trucks
    */

    cin >> r >> c >> u >> p >> m;

    vector<vector<int>> a(r, vector<int>(c, 0));// a[i][j] = 1 if unavai.


    for (int i = 0, x, y; i < u; i++) {
        cin >> x >> y;

        a[x][y] = true;
    }

    vector<pair<int, pair<int, int>>> truck; // size, cap, mileage

    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        truck.push_back({x, {y, z}});
    }
    long double sm = 0;
    for (int i = 0; i < m; i++) {
        sm += 1. / truck[i].second.second;
    }



    vector<int> dis;
    int mxD = 0;
    for (int i = 0, x = 0; i < p; i++) {
        cin >> x;
        dis.push_back(x);
        mxD = max(mxD, x);
    }



    vector<vector<int>> z(r);

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (a[i][j] == 1) {
                continue;
            }
            int _ = j;

            while (_ < c && a[i][_] == 0) {
                _++;
            }
            z[i].push_back(_ - j);

            j = _ - (_ != j);
        }

        while (z[i].size() <= c) {
            z[i].push_back(0);
        }
    }


    /*
    i -> number of row
    j -> number of block
    k -> number of trucks
    l -> destination
    c(k) -> capicity of trucks
    */
    cout << "sets\n";

    cout << "i /";

    for (int i = 1; i <= r - 1; i++) {
        cout << i << ", ";
    }
    cout << r << "/\n";



    cout << "j /";
    for (int i = 1; i <= c; i++) {
        if (i != c) {
            cout << i << ", ";
        } else {
            cout << c << "/\n";
        }
    }




    cout << "k /";
    for (int i = 1; i <= m; i++) {
        if (i != m) {
            cout << i << ", ";
        } else {
            cout << m << "/\n";
        }
    }


    cout << "l /";
    for (int i = 1; i <= p; i++) {
        if (i != p) {
            cout << i << ", ";
        } else {
            cout << p << "/;\n\n";
        }
    }

    cout << "Parameter\n";

    cout << "c(k)\n/";

    for (int i = 0; i < m; i++) {
        cout << i + 1 << " " << truck[i].second.first;

        if (i == m - 1) {
            cout << "/";
        }
        cout << "\n";
    }

    cout << "len(k)\n/";

    for (int i = 0; i < m; i++) {
        cout << i + 1 << " " << truck[i].first;

        if (i == m - 1) {
            cout << "/";
        }
        cout << "\n";
    }

    cout << "mil(k)\n/";

    for (int i = 0; i < m; i++) {
        cout << i + 1 << " " << truck[i].second.second;

        if (i == m - 1) {
            cout << "/";
        }

        cout << "\n";
    }


    cout << "dist(l)\n/";

    for (int i = 0; i < p; i++) {
        cout << i + 1 << " " << dis[i];

        if (i == p - 1) {
            cout << "/;";
        }
        cout << "\n";
    }

    cout << "\n";

    cout << "Scalar\n";
    cout << fixed << setprecision(5);
    cout << "MaxCost /" << mxD / sm << "/;\n\n";

    cout << "Table z(i, j)\n";

    cout << " ";
    for (int i = 0; i < c; i++) {
        cout << i + 1 << " ";
    }
    cout << "\n";
    for (int i = 0; i < r; i++) {
        cout << i + 1 << "   ";
        for (int j = 0; j < c; j++) {
            cout << z[i][j] << " ";
        }

        if (i == r - 1) {
            cout << ";";
        }

        cout << "\n";
    }
    return 0;
}

/*
2 5 2 2 3

0 0
1 2

3 10 3
10 2 5
1 5 1

50 100
*/
