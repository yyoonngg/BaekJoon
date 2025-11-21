#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char a[2504], b[54], ret;

void substr(char *dest, const char *src, int start, int length) {
    strncpy(dest, src+start, length);
    dest[length] = '\0';
}

int main() {
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);
    int lena = strlen(a)-1;
    int lenb = strlen(b)-1;
    a[lena] = '\0';
    b[lenb] = '\0';
    for(int i = 0; i < lena; i++) {
        char part1[54];
        substr(part1, a, i, lenb);
        if(strcmp(part1, b) == 0) {
            ret++;
            i+=(lenb-1);
        }
    }
    printf("%d", ret);

    return 0;
}