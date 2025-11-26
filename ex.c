#include <stdio.h>

int main() {
    int N;
    printf("Entrez le nombre obtenu : ");
    scanf("%d", &N);

    for (int J = 1; J <= 31; J++) {
        for (int M = 1; M <= 12; M++) {
            if (31 * J + 12 * M == N) {
                printf("Vous êtes né le %d/%d\n", J, M);
                return 0;
            }
        }
    }

    printf("Aucune date ne correspond.\n");
    return 0;
}
