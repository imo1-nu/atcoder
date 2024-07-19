#include <stdio.h>

int main()
{
    char s[200000],t[200000];
    scanf("%s", s);
    scanf("%s", t);

    int i, j, count[2];
    int key;
    for (i = 0; s[i] !='\0'; i++) {
        if (s[i] == 'a' || s[i] == 't' || s[i] == 'c' || s[i] == 'o' || s[i] == 'd' || s[i] == 'e' || s[i] == 'r') count[0]++;
        else {
            key = 0;
            for (j = 0; t[j] !='\0'; i++) {
                if (s[i] == t[j]) {
                    key = 1;
                    break;
                }
            }
            if (key == 0) break;
        }
    }

    if (key == 0) printf("No\n");
    else {
        if (count[0] - count [1])
    }
}