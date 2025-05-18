#include <bits/stdc++.h>
using namespace std;

int a, b, c, tt[100], t1, t2, sum;

int main() {
    cin >> a >> b >> c;

    for(int i = 0; i < 3; i++) {
        cin >> t1 >> t2;
        for(int j = t1; j < t2; j++) {
            tt[j]++;
        }
    }

    for(int i = 0; i < 100; i++) {
        if(tt[i] == 1) sum += tt[i]*a;
        else if(tt[i] == 2) sum += tt[i]*b;
        else sum += tt[i]*c;
    }

    cout << sum;

    return 0;
}