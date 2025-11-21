#include <stdio.h>
#include <string.h>
char a[2504], b[54], ret;

int main() {
    fgets(a, sizeof(a), stdin);
    fgets(b, sizeof(b), stdin);
    int lena = strlen(a);
    int lenb = strlen(b);
    if(a[lena-1] == '\n') a[lena-1] = '\0';
    if(b[lenb-1] == '\n') b[lenb-1] = '\0';

    char *pos = a;
    while(1) {
        char *p = strstr(pos, b);
        if(p == NULL) break;

        ret++;
        pos = p + lenb-1;
    }

    printf("%d", ret);
    return 0;
}