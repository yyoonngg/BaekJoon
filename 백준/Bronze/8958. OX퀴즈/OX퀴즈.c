#include <stdio.h>
#include <string.h>
int n;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        char c[84];
        scanf(" %s", c);
        int len = strlen(c);
        int sum = 0, psum = 0;

        for(int j = 0; j < len; j++) {
            if(c[j] == 'O') {
                psum++;
                sum += psum;
            }
            else {
                psum = 0;
            }
        }
        printf("%d\n", sum);
    }    
    return 0;
}
