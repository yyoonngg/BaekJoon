#include <bits/stdc++.h>
using namespace std;
int a2, a1, a0, b2, b1, b0;
int p2, p1, p0, q2, q1, q0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a2 >> a1 >> a0 >> b1 >> b0;

    if(b1 == 0) { // ex) g(x) = 2
        cout << "Head on\n";
        exit(0);
    }
    else if(b0 == 0) { // ex) g(x) = 2x
        p2 = b1*b1*a2;
        p1 = b1*a1;
        p0 = a0;

        q2 = a2*b1;
        q1 = a1*b1;
        q0 = a0*b1;
    }
    else { // ex) g(x) = x + 1
        p2 = a2*b1*b1;
        p1 = a2*2*b1*b0 + a1*b1;
        p0 = a2*b0*b0 + a1*b0 + a0;
        
        q2 = a2*b1;
        q1 = a1*b1;
        q0 = a0*b1 + b0;
    }
    
    int a, b, c;
    a = p2 - q2;
    b = p1 - q1;
    c = p0 - q0;
    
    if(a == 0) { // 이차 방정식이 아니라면?
        if(b == 0) { // 일차 방정식이 평행하다면?
            if(c == 0) cout << "Nice\n";
            else cout << "Head on\n";
        }
        else cout << "Remember my character\n";
        exit(0);
    }
    
    int _ret = b*b - 4*a*c;
    if(_ret > 0) {
        cout << "Go ahead\n";
    }
    else if(_ret == 0) {
        cout << "Remember my character\n";
    }
    else {
        cout << "Head on\n";
    }
}