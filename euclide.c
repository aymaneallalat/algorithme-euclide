#include <stdio.h>

int main() {
    int a, b, reste;

    printf("Entrez le premier entier : ");
    scanf("%d", &a);
    printf("Entrez le deuxième entier : ");
    scanf("%d", &b);

    printf("\n--- Étapes du calcul ---\n");

    while (b != 0) {
        reste = a % b;
        printf("a = %d, b = %d, reste = %d\n", a, b, reste);
        a = b;
        b = reste;
    }

    printf("\nLe PGCD est : %d\n", a);

    return 0;
}
