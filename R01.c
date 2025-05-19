#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

// Déclarations des fonctions
void calculatrice(void);
void verifier_nombre_premier(void);

// Menu principal
void menu() {
    int choix;
    do {
        printf("\n--- MENU ---\n");
        printf("1. Calculatrice\n");
        printf("2. Vérifier si un nombre est premier\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: calculatrice(); break;
            case 2: verifier_nombre_premier(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide.\n");
        }
    } while (choix != 0);
}

// Fonction pure pour vérifier si un nombre est premier
bool est_premier(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Fonction avec interface utilisateur pour tester plusieurs nombres
void verifier_nombre_premier() {
    int nombre;
    char buffer[100];
    char continuer;

    printf("=== Vérificateur de nombres premiers ===\n\n");

    do {
        // Boucle de saisie sécurisée
        while (1) {
            printf("Entrez un nombre : ");
            if (scanf("%d", &nombre) == 1) {
                // Vider le buffer après scanf
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
                break;
            } else {
                printf("\nEntrée invalide. Veuillez entrer un entier.\n\n");
                // Vider le buffer
                int c;
                while ((c = getchar()) != '\n' && c != EOF);
            }
        }

        // Résultat
        printf("\n--- Résultat ---\n");
        if (est_premier(nombre)) {
            printf("%d est un nombre premier.\n", nombre);
        } else {
            printf("%d n'est pas un nombre premier.\n", nombre);
        }
        printf("---------------\n\n");

        // Boucle de validation o/n
        while (1) {
            printf("Voulez-vous vérifier un autre nombre ? (o/n) : ");
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                if (strlen(buffer) > 1 && buffer[strlen(buffer) - 1] != '\n') {
                    int c;
                    while ((c = getchar()) != '\n' && c != EOF);
                }

                continuer = tolower(buffer[0]);
                if (continuer == 'o' || continuer == 'n') break;

                printf("\nRéponse invalide. Tapez 'o' pour oui ou 'n' pour non.\n\n");
            }
        }

    } while (continuer == 'o');

    printf("=== Programme terminé ===\n");
}

void calculatrice() {
    int a, b, resultat;
    char op;

    printf("\n=== Calculatrice simple ===\n");
    printf("Entrez votre opération (ex: 5 + 3) : ");

    if (scanf("%d %c %d", &a, &op, &b) != 3) {
        printf("Erreur : format invalide.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF); // vider le buffer
        return;
    }

    switch (op) {
        case '+':
            resultat = a + b;
            printf("Résultat : %d + %d = %d\n", a, b, resultat);
            break;
        case '-':
            resultat = a - b;
            printf("Résultat : %d - %d = %d\n", a, b, resultat);
            break;
        case '*':
            resultat = a * b;
            printf("Résultat : %d * %d = %d\n", a, b, resultat);
            break;
        case '/':
            if (b == 0) {
                printf("Erreur : division par zéro.\n");
                break;
            }
            resultat = a / b;
            printf("Résultat : %d / %d = %d\n", a, b, resultat);
            break;
        case '%':
            if (b == 0) {
                printf("Erreur : modulo par zéro.\n");
                break;
            }
            resultat = a % b;
            printf("Résultat : %d %% %d = %d\n", a, b, resultat);
            break;
        default:
            printf("Erreur : opérateur non reconnu.\n");
    }

    int c;
    while ((c = getchar()) != '\n' && c != EOF); // vider le buffer
}

int main() {
    menu();
    return 0;
}

