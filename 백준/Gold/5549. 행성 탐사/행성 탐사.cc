#include <bits/stdc++.h>
using namespace std;
int n, m, k, psum[1004][1004][3];
char a[1004][1004];
struct A {
    int a, b, c, d;
};
vector<A> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> k;
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'J') {
                psum[i][j][0] = psum[i][j - 1][0] + 1; 
                psum[i][j][1] = psum[i][j - 1][1]; 
                psum[i][j][2] = psum[i][j - 1][2]; 
            }
            else if(a[i][j] == 'O') {
                psum[i][j][0] = psum[i][j - 1][0]; 
                psum[i][j][1] = psum[i][j - 1][1] + 1; 
                psum[i][j][2] = psum[i][j - 1][2]; 
            }
            else if(a[i][j] == 'I') {
                psum[i][j][0] = psum[i][j - 1][0]; 
                psum[i][j][1] = psum[i][j - 1][1]; 
                psum[i][j][2] = psum[i][j - 1][2] + 1; 
            }
        }
    }
    for(int i = 0; i < k; i++) {
        int ta, tb, tc, td;
        cin >> ta >> tb >> tc >> td;
        v.push_back({ta, tb, tc, td});
    }

    for(int i = 0; i < k; i++) {
        A here = v[i];
        int jSum = 0, oSum = 0, iSum = 0;
        for(int j = here.a; j <= here.c; j++) {
            jSum += psum[j][here.d][0] - psum[j][here.b - 1][0]; 
            oSum += psum[j][here.d][1] - psum[j][here.b - 1][1]; 
            iSum += psum[j][here.d][2] - psum[j][here.b - 1][2]; 
        }
        cout << jSum << " " << oSum << " " << iSum << "\n";
    }
    // 정글 J, 바다 O, 얼음 I
    return 0;
}