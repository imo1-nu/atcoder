#include <stdio.h>

int func(char a, char b)
{
    if (a == b) return 1;
    else if (a == '1' && b == 'l') return 1;
         else if (a == 'l' && b == '1') return 1;
              else if (a == '0' && b == 'o') return 1;
                   else if (a == 'o' && b == '0') return 1;
                        else return 0; 
}

int main()
{
    int n;
    scanf("%d", &n);
    char s[n], t[n];
    scanf("%s", s);
    scanf("%s", t);
    int i, k = 1;
    for (i = 0; i < n; i++) {
        if (func(s[i], t[i]) == 0) {
            k = 0;
            break;
        }
    }

    if (k == 0) printf("No\n");
    else printf("Yes\n");

    return 0;
}