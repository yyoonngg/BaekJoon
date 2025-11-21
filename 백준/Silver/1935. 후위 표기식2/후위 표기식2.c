#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int n, a[30];
char c[104];
double stack[104];
int stk = 0;

int main() {
    scanf(" %d", &n);
    scanf(" %s", c);

    for(int i = 0; i < n; i++) {
        int tmp;
        scanf(" %d", &tmp);
        a[i] = tmp;
    }

    int lenc = strlen(c);
    for(int i = 0; i < lenc; i++) {
        if(c[i] >= 'A' && c[i] <= 'Z') {
            stack[stk++] = (double)a[c[i]-'A'];
        }
        else {
            double s = stack[--stk];
            double f = stack[--stk];
            if(c[i] == '*') {
                stack[stk++] = (double)f*s;
            }
            else if(c[i] == '+') {
                stack[stk++] = (double)f+s;
            }
            else if(c[i] == '/') {
                stack[stk++] = (double)f/s;
            }
            else if(c[i] == '-') {
                stack[stk++] = (double)f-s;
            }
        }
    }
    printf("%.2f\n", stack[0]);
    return 0;
}