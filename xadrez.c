#include <stdio.h>

// Constantes
#define BISPO_PASSOS 5
#define TORRE_PASSOS 5
#define RAINHA_PASSOS 8

// --------------------- NÍVEL NOVATO ---------------------
void nivelNovato() {
    printf("♟️ Nível Novato - Movimentação Simples\n");

    printf("\n➡ Bispo (Diagonal Superior Direita):\n");
    for (int i = 0; i < BISPO_PASSOS; i++) {
        printf("Cima\n");
        printf("Direita\n");
    }

    printf("\n➡ Torre (Para a Direita):\n");
    for (int i = 0; i < TORRE_PASSOS; i++) {
        printf("Direita\n");
    }

    printf("\n➡ Rainha (Para a Esquerda):\n");
    for (int i = 0; i < RAINHA_PASSOS; i++) {
        printf("Esquerda\n");
    }
}

// --------------------- NÍVEL AVENTUREIRO ---------------------
void nivelAventureiro() {
    printf("\n🏹 Nível Aventureiro - Cavalo (Movimento em L)\n");

    for (int i = 0; i < 2; i++) { // Movimento vertical
        printf("Baixo\n");
    }

    int j = 0;
    while (j < 1) { // Movimento horizontal
        printf("Esquerda\n");
        j++;
    }
}

// --------------------- NÍVEL MESTRE ---------------------

// Funções recursivas
void moverBispoRecursivo(int passos) {
    if (passos == 0) return;
    printf("Cima\n");
    printf("Direita\n");
    moverBispoRecursivo(passos - 1);
}

void moverTorreRecursivo(int passos) {
    if (passos == 0) return;
    printf("Direita\n");
    moverTorreRecursivo(passos - 1);
}

void moverRainhaRecursivo(int passos) {
    if (passos == 0) return;
    printf("Esquerda\n");
    moverRainhaRecursivo(passos - 1);
}

void moverCavaloMestre() {
    printf("\n➡ Cavalo (Movimento em L - Cima + Direita)\n");
    for (int i = 0, j = 0; i < 2 || j < 1; i++, j++) {
        if (i < 2) {
            printf("Cima\n");
            if (i == 1) continue;
        }

        if (j < 1) {
            printf("Direita\n");
            break;  // quebra após o L
        }
    }
}

void nivelMestre() {
    printf("\n👑 Nível Mestre - Movimentos Avançados com Recursão\n");

    printf("\n➡ Bispo:\n");
    moverBispoRecursivo(BISPO_PASSOS);

    printf("\n➡ Torre:\n");
    moverTorreRecursivo(TORRE_PASSOS);

    printf("\n➡ Rainha:\n");
    moverRainhaRecursivo(RAINHA_PASSOS);

    moverCavaloMestre();
}

// --------------------- MENU PRINCIPAL ---------------------
int main() {
    int opcao;

    do {
        printf("\n========= MENU MATECHECK =========\n");
        printf("1. Nível Novato\n");
        printf("2. Nível Aventureiro\n");
        printf("3. Nível Mestre\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: nivelNovato(); break;
            case 2: nivelAventureiro(); break;
            case 3: nivelMestre(); break;
            case 0: printf("Saindo do desafio. Até a próxima!\n"); break;
            default: printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}
