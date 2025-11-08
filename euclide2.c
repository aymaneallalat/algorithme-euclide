#include <stdio.h>

// Fonction PGCD avec l'algorithme d'Euclide simple
int pgcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// Algorithme d'Euclide étendu
int euclideEtendu(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int d = euclideEtendu(b, a % b, &x1, &y1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    return d;
}

int main() {
    int a, b, c;
    printf("=== Equation diophantienne : a*x + b*y = c ===\n");
    printf("Entrez a : ");
    scanf("%d", &a);
    printf("Entrez b : ");
    scanf("%d", &b);
    printf("Entrez c : ");
    scanf("%d", &c);

    int x0, y0;
    int d = euclideEtendu(a, b, &x0, &y0);

    printf("\nPGCD(%d, %d) = %d\n", a, b, d);

    if (c % d != 0) {
        printf(" Pas de solution entiere car %d ne divise pas %d.\n", d, c);
        return 0;
    }

    // Calcul d'une solution particulière
    int k;
    int xp = x0 * (c / d);
    int yp = y0 * (c / d);

    printf(" Il existe des solutions entieres.\n");
    printf("Solution particuliere : (x, y) = (%d, %d)\n", xp, yp);

    int alpha = b / d;
    int beta = -a / d;

    printf("Solution generale : (x, y) = (%d + %d*k, %d + %d*k), k ∈ Z\n",
           xp, alpha, yp, beta);

    return 0;
}
