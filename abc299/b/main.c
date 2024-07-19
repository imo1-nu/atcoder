#include <stdio.h>

struct card{
    int color;
    int num;
};

void hantei(int *t, struct card *card, int *n)
{
    int i, max[2];
    for (i = 0, max[0] = 0, max[1] = 0; i < *n; i++) {
        if (card[i].color == *t && card[i].num > max[0]) {
            max[0] = card[i].num;
            max[1] = i;
        }
    }
    printf("%d\n", max[1] + 1);
}

int main()
{
    int n, t, i;
    scanf("%d %d", &n, &t);
    struct card card[n];

    for (i = 0; i < n; i++) {
        scanf("%d", &card[i].color);
    }

    for (i = 0; i < n; i++) {
        scanf("%d", &card[i].num);
    }

    for (i = 0; i < n; i++) {
        if (t == card[i].color) {
            hantei(&t, card, &n);
            break;
        }
    }

    if (i == n) hantei(&card[0].color, card, &n);

    return 0;
}