#include <stdio.h>

int main()
{
    int D[200];
    D['A'] = 0;
    D['B'] = 3;
    D['C'] = 4;
    D['D'] = 8;
    D['E'] = 9;
    D['F'] = 14;
    D['G'] = 23;

    char p, q;
    scanf("%c %c", &p, &q);
    if (D[p] - D[q] > 0) printf("%d\n", D[p] - D[q]);
    else printf("%d\n", D[q] - D[p]);
    return 0;
}