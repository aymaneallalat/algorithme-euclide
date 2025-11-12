#include <stdio.h>

// ------------------------------
// Fonction : PGCD avec etapes
// ------------------------------
int pgcd_etapes(int a, int b) {
    int reste;
    printf("\n=== Etapes du calcul du PGCD ===\n");
    while (b != 0) {
        reste = a % b;
        printf("%d = %d * (%d) + %d\n", a, b, a / b, reste);
        a = b;
        b = reste;
    }
    printf("=> PGCD = %d\n\n", a);
    return a;
}

// ------------------------------
// Algorithme d’Euclide etendu avec etapes
// ------------------------------
int euclideEtendu_etapes(int a, int b, int *x, int *y, int niveau) {
    // Affichage indenté pour visualiser les appels recursifs
    for (int i = 0; i < niveau; i++) printf("  ");

    printf("Appel: euclideEtendu(%d, %d)\n", a, b);

    if (b == 0) {
        for (int i = 0; i < niveau; i++) printf("  ");
        printf("Retour: d = %d, x = 1, y = 0\n", a);
        *x = 1;
        *y = 0;
        return a;
    }

    int x1, y1;
    int d = euclideEtendu_etapes(b, a % b, &x1, &y1, niveau + 1);

    *x = y1;
    *y = x1 - (a / b) * y1;

    for (int i = 0; i < niveau; i++) printf("  ");
    printf("Retour: d = %d, x = %d, y = %d\n", d, *x, *y);

    return d;
}

// ------------------------------
// Programme principal
// ------------------------------
int main() {
    int a, b, c;
    printf("=== Equation diophantienne : a*x + b*y = c ===\n");
    printf("Entrez a : ");
    scanf("%d", &a);
    printf("Entrez b : ");
    scanf("%d", &b);
    printf("Entrez c : ");
    scanf("%d", &c);

    // Étape 1 : Calcul du PGCD avec affichage des divisions
    int d = pgcd_etapes(a, b);

    // Étape 2 : Algorithme d'Euclide étendu avec suivi des appels
    int x0, y0;
    printf("=== Etapes de l'algorithme d'Euclide etendu ===\n");
    d = euclideEtendu_etapes(a, b, &x0, &y0, 0);

    printf("\nRésultat final : PGCD(%d, %d) = %d\n", a, b, d);
    printf("Coefficients trouves : x0 = %d, y0 = %d\n", x0, y0);

    // Étape 3 : Vérification d’existence de solution
    if (c % d != 0) {
        printf("\n Pas de solution entiere car %d ne divise pas %d.\n", d, c);
        return 0;
    }

    // Étape 4 : Calcul d'une solution particulière
    int xp = x0 * (c / d);
    int yp = y0 * (c / d);

    // Étape 5 : Solution générale
    int alpha = b / d;
    int beta = -a / d;

    printf("\n Il existe des solutions entieres !\n");
    printf("Solution particuliere : (x, y) = (%d, %d)\n", xp, yp);
    printf("Solution generale : (x, y) = (%d + %d*k, %d + %d*k), k apartient a Z\n",
           xp, alpha, yp, beta);

    return 0;
}

