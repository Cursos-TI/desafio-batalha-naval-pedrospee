#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Nível Novato: posiciona dois navios num tabuleiro 10x10 e exibe o resultado.

#define TAMANHO  10  // lado do tabuleiro
#define NAV_TAM   3  // casas que cada navio ocupa
#define AGUA      0  // célula vazia
#define NAVIO     3  // célula ocupada

// Valida se o navio cabe dentro dos limites do tabuleiro
// Retorna 1 se válido, 0 se inválido
int posicaoValida(int linha, int coluna, int tamanho, int horizontal) {
    if (horizontal)
        return (coluna + tamanho <= TAMANHO) && (linha < TAMANHO);
    else
        return (linha + tamanho <= TAMANHO) && (coluna < TAMANHO);
}

// Verifica se as células que o navio vai ocupar ainda estão livres (sem sobreposição)
int semSobreposicao(int tabuleiro[TAMANHO][TAMANHO],
                    int linha, int coluna, int tamanho, int horizontal) {
    for (int i = 0; i < tamanho; i++) {
        int l = horizontal ? linha      : linha + i;
        int c = horizontal ? coluna + i : coluna;
        if (tabuleiro[l][c] != AGUA) return 0;
    }
    return 1;
}

// Marca as posições do navio no tabuleiro com o valor NAVIO
void posicionarNavio(int tabuleiro[TAMANHO][TAMANHO],
                     int linha, int coluna, int tamanho, int horizontal) {
    for (int i = 0; i < tamanho; i++) {
        if (horizontal)
            tabuleiro[linha][coluna + i] = NAVIO;
        else
            tabuleiro[linha + i][coluna] = NAVIO;
    }
}

// Imprime o tabuleiro: 0 = água, 3 = navio
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("\n  ");
    for (int c = 0; c < TAMANHO; c++) printf("%2d", c);  // cabeçalho de colunas
    printf("\n");

    for (int l = 0; l < TAMANHO; l++) {
        printf("%2d", l);                                  // número da linha
        for (int c = 0; c < TAMANHO; c++)
            printf("%2d", tabuleiro[l][c]);
        printf("\n");
    }
}

int main() {

    // ── Tabuleiro ─────────────────────────────────────────────────────────────
    int tabuleiro[TAMANHO][TAMANHO] = {0};  // começa todo preenchido com água

    // ── Navio 1: horizontal ───────────────────────────────────────────────────
    // Ocupa as colunas 2, 3 e 4 na linha 2
    int navio1[NAV_TAM] = {NAVIO, NAVIO, NAVIO};
    int l1 = 2, c1 = 2, horizontal1 = 1;

    if (!posicaoValida(l1, c1, NAV_TAM, horizontal1)) {
        printf("Erro: navio 1 fora dos limites do tabuleiro.\n");
        return 1;
    }
    if (!semSobreposicao(tabuleiro, l1, c1, NAV_TAM, horizontal1)) {
        printf("Erro: navio 1 se sobrepoe a outro navio.\n");
        return 1;
    }
    posicionarNavio(tabuleiro, l1, c1, NAV_TAM, horizontal1);

    // ── Navio 2: vertical ─────────────────────────────────────────────────────
    // Ocupa as linhas 5, 6 e 7 na coluna 6
    int navio2[NAV_TAM] = {NAVIO, NAVIO, NAVIO};
    int l2 = 5, c2 = 6, horizontal2 = 0;

    if (!posicaoValida(l2, c2, NAV_TAM, horizontal2)) {
        printf("Erro: navio 2 fora dos limites do tabuleiro.\n");
        return 1;
    }
    if (!semSobreposicao(tabuleiro, l2, c2, NAV_TAM, horizontal2)) {
        printf("Erro: navio 2 se sobrepoe a outro navio.\n");
        return 1;
    }
    posicionarNavio(tabuleiro, l2, c2, NAV_TAM, horizontal2);

    // ── Resultado ─────────────────────────────────────────────────────────────
    printf("=== Batalha Naval - Nivel Novato ===");
    printf("\nNavio 1 (horizontal): linha %d, colunas %d-%d", l1, c1, c1 + NAV_TAM - 1);
    printf("\nNavio 2 (vertical)  : coluna %d, linhas %d-%d", c2, l2, l2 + NAV_TAM - 1);
    exibirTabuleiro(tabuleiro);

    // ── Níveis futuros ────────────────────────────────────────────────────────

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Posicione quatro navios, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo (0 = vazio, 3 = navio).

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para cone, cruz e octaedro.
    // Sugestão: Use loops aninhados para preencher as áreas afetadas (0 = livre, 1 = atingido).
    //
    // Cone:      0 0 1 0 0      Octaedro:  0 0 1 0 0      Cruz:  0 0 1 0 0
    //            0 1 1 1 0                 0 1 1 1 0              1 1 1 1 1
    //            1 1 1 1 1                 0 0 1 0 0              0 0 1 0 0

    return 0;
}
