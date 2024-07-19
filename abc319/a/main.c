#include <stdio.h>

char P[10][30] = {
    "tourist 3858",
    "ksun48 3679",
    "Benq 3658",
    "Um_nik 3648",
    "apiad 3638",
    "Stonefeang 3630",
    "ecnerwala 3613",
    "mnbvmar 3555",
    "newbiedmy 3516",
    "semiexp 3481"
};

int main()
{
    char S[20];
    scanf("%s", S);
    int i, j, k;
    for (i = 0; i < 10; i++) {
        k = 0;
        for (j = 0; P[i][j] != ' '; j++) {
            if (S[j] != P[i][j]) {
                k = 1;
                break;
            }
        }

        if (k == 1) continue;

        if (P[i][j] == ' ') {
            printf("%s\n", P[i] + j + 1);
            break;
        }
    }
    return 0;
}