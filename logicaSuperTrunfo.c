#include <stdio.h>
#include <string.h>

// Função para exibir o menu de atributos, ocultando o atributo já escolhido
void exibirMenu(int excluir) {
    printf("Escolha um atributo:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
}

// Função auxiliar para retornar o valor correspondente de um atributo de uma carta
float obterValor(int opcao, int pop, float area, float pib, int pontos, float densidade) {
    switch(opcao) {
        case 1: return pop;
        case 2: return area;
        case 3: return pib;
        case 4: return pontos;
        case 5: return densidade;
        default: return 0;
    }
}

// Função auxiliar para retornar o nome do atributo, usado na exibição
const char* nomeAtributo(int opcao) {
    switch(opcao) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    // === Dados fixos da carta 1 ===
    char pais1[50] = "Brasil";
    int pop1 = 213000000;
    float area1 = 8515767.0;
    float pib1 = 1800000.0;
    int pontos1 = 50;
    float densidade1 = pop1 / area1;  // cálculo da densidade demográfica

    // === Dados fixos da carta 2 ===
    char pais2[50] = "Argentina";
    int pop2 = 45000000;
    float area2 = 2780400.0;
    float pib2 = 500000.0;
    int pontos2 = 30;
    float densidade2 = pop2 / area2;

    int attr1 = 0, attr2 = 0; // variáveis para guardar os atributos escolhidos

    printf("=== SUPER TRUNFO: COMPARAÇÃO COM DOIS ATRIBUTOS ===\n");

    // === Primeira escolha do jogador ===
    exibirMenu(0); // mostra todos os atributos
    scanf("%d", &attr1); // lê a escolha

    // Validação da primeira opção
    if (attr1 < 1 || attr1 > 5) {
        printf("Opção inválida!\n");
        return 1; // encerra o programa
    }

    // === Segunda escolha, menu dinâmico sem repetir a primeira opção ===
    printf("\nAgora escolha o segundo atributo (diferente do primeiro):\n");
    exibirMenu(attr1); // mostra os demais atributos, exceto o já escolhido
    scanf("%d", &attr2);

    // Validação da segunda opção
    if (attr2 < 1 || attr2 > 5 || attr2 == attr1) {
        printf("Opção inválida ou repetida!\n");
        return 1; // encerra o programa
    }

    // === Obter os valores dos atributos para cada carta ===
    float valor1_attr1 = obterValor(attr1, pop1, area1, pib1, pontos1, densidade1);
    float valor2_attr1 = obterValor(attr1, pop2, area2, pib2, pontos2, densidade2);

    float valor1_attr2 = obterValor(attr2, pop1, area1, pib1, pontos1, densidade1);
    float valor2_attr2 = obterValor(attr2, pop2, area2, pib2, pontos2, densidade2);

    // === Exibição clara dos dados ===
    printf("\nComparação entre %s e %s\n", pais1, pais2);
    printf("Atributo 1: %s\n", nomeAtributo(attr1));
    printf("  %s: %.2f\n", pais1, valor1_attr1);
    printf("  %s: %.2f\n", pais2, valor2_attr1);

    printf("Atributo 2: %s\n", nomeAtributo(attr2));
    printf("  %s: %.2f\n", pais1, valor1_attr2);
    printf("  %s: %.2f\n", pais2, valor2_attr2);

    // === Avaliação da pontuação: cada atributo vale 1 ponto ===
    float pontuacao1 = 0, pontuacao2 = 0;

    // Verifica quem ganha no atributo 1
    pontuacao1 += (attr1 == 5) ? (valor1_attr1 < valor2_attr1 ? 1 : 0) : (valor1_attr1 > valor2_attr1 ? 1 : 0);
    pontuacao2 += (attr1 == 5) ? (valor2_attr1 < valor1_attr1 ? 1 : 0) : (valor2_attr1 > valor1_attr1 ? 1 : 0);

    // Verifica quem ganha no atributo 2
    pontuacao1 += (attr2 == 5) ? (valor1_attr2 < valor2_attr2 ? 1 : 0) : (valor1_attr2 > valor2_attr2 ? 1 : 0);
    pontuacao2 += (attr2 == 5) ? (valor2_attr2 < valor1_attr2 ? 1 : 0) : (valor2_attr2 > valor1_attr2 ? 1 : 0);

    // === Soma final dos valores (não da pontuação) para decidir o vencedor ===
    float soma1 = valor1_attr1 + valor1_attr2;
    float soma2 = valor2_attr1 + valor2_attr2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", pais1, soma1);
    printf("%s: %.2f\n", pais2, soma2);

    // === Resultado final ===
    if (soma1 > soma2) {
        printf("\nResultado final: %s venceu!\n", pais1);
    } else if (soma2 > soma1) {
        printf("\nResultado final: %s venceu!\n", pais2);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0; // fim do programa
}
