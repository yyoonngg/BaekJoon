#include <bits/stdc++.h>
using namespace std;

int h, w;
int a[104][104];
string s;
char tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> h >> w;

    for(int i = 0; i < h; i++) {
        cin >> s;
        for(int j = 0; j < w; j++) {
            tmp = s[j];
            if(tmp == 'c') a[i][j] = 0;
            else a[i][j] = -1;

        }
    }

    for(int i = 0; i < h; i++) {
        int c = -1;
        for(int j = 0; j < w; j++) {
            if(a[i][j] == 0) {
                c = 0;
            }
            else if(c >= 0) {
                if(a[i][j] == -1 && c == 0) c = 1;
                else c++;
                a[i][j] = c;
            }
            cout << a[i][j] << " ";   
        }
        cout << "\n";
    }
    
    return 0;

}