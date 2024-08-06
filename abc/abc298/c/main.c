#include <stdio.h>

struct box{
    int num[200001];
};

struct num{
    int box[200001];
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    struct box[n];
    int a, b, c, i, j, k;
    for (k = 0; )
    for (k = 0; k < q; k++) {
        scanf("%d", &a);
        switch (a) {
            case 1:
            scanf("%d %d", &i, &j);
            box[j].num[i] = 1;
            break;
        }
    }
}