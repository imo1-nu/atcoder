#include <stdio.h>

int H, W, passed[501][502] = {}, ans = 0;
char S[501][502] = {};
char str[10] = "snuke";

int maze(int i, int j, int order)
{
    passed[i][j] = order + 1;
    if (i == H && j == W) return 1;
    if (i - 1 > 0 && passed[i - 1][j] == 0 && S[i - 1][j] == str[(passed[i][j]) % 5]) {
        if (maze(i - 1, j, order + 1) == 1) return 1;
    }
    if (i + 1 <= H && passed[i + 1][j] == 0 && S[i + 1][j] == str[(passed[i][j]) % 5]) {
        if (maze(i + 1, j, order + 1) == 1) return 1;
    }
    if (j - 1 > 0 && passed[i][j - 1] == 0 && S[i][j - 1] == str[(passed[i][j]) % 5]) {
        if (maze(i, j - 1, order + 1) == 1) return 1;
    }
    if (j + 1 <= W && passed[i][j + 1] == 0 && S[i][j + 1] == str[(passed[i][j]) % 5]) {
        if (maze(i, j + 1, order + 1) == 1) return 1;
    }
    
    passed[i][j] = 0;
    return 0;
}

int main()
{
    int i;
    scanf("%d %d", &H, &W);
    for (i = 1; i <= H; i++) {
        scanf("%s", S[i] + 1);
    }

    if (S[1][1] == 's') {
        ans = maze(1, 1, 0);
    }

    if (ans == 1) printf("Yes\n");
    else printf("No\n"); 
    return 0;
}