#include <stdio.h>

int estPremier(int x) {
    if (x < 2) return 0; // 0 et 1 ne sont pas premiers
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

int main() {
    int n;

    printf("Entrer un nombre n : ");
    scanf("%d", &n);

    // 1. Afficher tous les nombres
    printf("Tous les nombres de 1 a %d : ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }

    printf("\n");

    // 2. Afficher seulement les nombres premiers (suppression des autres)
    printf("Apres suppression des nombres non premiers : ");
    for (int i = 1; i <= n; i++) {
        if (estPremier(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
