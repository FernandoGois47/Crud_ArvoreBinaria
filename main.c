#include <stdio.h>
#include <stdlib.h>
#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_SCREEN "cls"
#else
    #include <unistd.h>
    #define CLEAR_SCREEN "clear"
#endif
#include "ArvoreBinaria.h"

// Função para limpar a tela
void limpar_tela() {
    system(CLEAR_SCREEN);
}

// Função para pausar
void pausar() {
    printf("\nPressione Enter para continuar...");
    while(getchar() != '\n'); // Limpa buffer
    getchar(); // Aguarda Enter
}

// Função para imprimir a árvore de forma visual
void imprime_arvore(ArvBin *raiz, int nivel) {
    if (raiz == NULL || *raiz == NULL) 
        return;
    
    // Primeiro imprime subárvore direita
    if ((*raiz)->dir != NULL) {
        imprime_arvore(&((*raiz)->dir), nivel + 1);
    }
    
    // Imprime o nó atual com indentação
    for (int i = 0; i < nivel; i++) {
        printf("    ");
    }
    printf("|-- %d\n", (*raiz)->info);
    
    // Depois imprime subárvore esquerda
    if ((*raiz)->esq != NULL) {
        imprime_arvore(&((*raiz)->esq), nivel + 1);
    }
}

void exibir_cabecalho() {
    limpar_tela();
    printf("==========================================================\n");
    printf("           SISTEMA CRUD - ARVORE BINARIA                 \n");
    printf("                 DE BUSCA EM C                           \n");
    printf("==========================================================\n\n");
}

void menu() {
    printf("----------------------------------------------------------\n");
    printf("                    MENU PRINCIPAL                       \n");
    printf("----------------------------------------------------------\n");
    printf("  1. Inserir valor na arvore                             \n");
    printf("  2. Remover valor da arvore                             \n");
    printf("  3. Buscar valor na arvore                              \n");
    printf("  4. Listar todos os valores (em ordem)                  \n");
    printf("  5. Mostrar estrutura visual da arvore                  \n");
    printf("  6. Informacoes detalhadas da arvore                    \n");
    printf("  0. Sair do programa                                    \n");
    printf("----------------------------------------------------------\n");
    printf("Escolha uma opcao: ");
}

int main(){
    ArvBin* raiz = cria_ArvBin();
    int opcao, valor;
    
    if(raiz == NULL) {
        printf("Erro: Nao foi possivel criar a arvore!\n");
        return 1;
    }
    
    exibir_cabecalho();
    printf("Arvore criada com sucesso!\n");
    pausar();
    
    do {
        exibir_cabecalho();
        menu();
        
        // Validação de entrada
        if(scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Digite apenas numeros.\n");
            while(getchar() != '\n'); // Limpa buffer
            pausar();
            continue;
        }
        
        switch(opcao) {
            case 1: // CREATE - Inserir
                printf("\nINSERCAO DE VALOR\n");
                printf("Digite o valor para inserir: ");
                
                if(scanf("%d", &valor) != 1) {
                    printf("Valor invalido!\n");
                    while(getchar() != '\n'); // Limpa buffer
                    break;
                }
                
                if(insere_ArvBin(raiz, valor)) {
                    printf("Valor %d inserido com sucesso!\n", valor);
                } else {
                    printf("Erro ao inserir %d (valor ja existe ou erro de memoria)\n", valor);
                }
                break;
                
            case 2: // DELETE - Remover
                printf("\nREMOCAO DE VALOR\n");
                if(estaVazia_ArvBin(raiz)) {
                    printf("Arvore esta vazia! Nada para remover.\n");
                } else {
                    printf("Valores atuais na arvore: ");
                    emOrdem_ArvBin(raiz);
                    printf("\n\nDigite o valor para remover: ");
                    
                    if(scanf("%d", &valor) != 1) {
                        printf("Valor invalido!\n");
                        while(getchar() != '\n'); // Limpa buffer
                        break;
                    }
                    
                    if(remove_ArvBin(raiz, valor)) {
                        printf("Valor %d removido com sucesso!\n", valor);
                    } else {
                        printf("Valor %d nao encontrado na arvore!\n", valor);
                    }
                }
                break;
                
            case 3: // READ - Buscar
                printf("\nBUSCA DE VALOR\n");
                if(estaVazia_ArvBin(raiz)) {
                    printf("Arvore esta vazia!\n");
                } else {
                    printf("Digite o valor para buscar: ");
                    
                    if(scanf("%d", &valor) != 1) {
                        printf("Valor invalido!\n");
                        while(getchar() != '\n'); // Limpa buffer
                        break;
                    }
                    
                    if(consulta_ArvBin(raiz, valor)) {
                        printf("Valor %d ENCONTRADO na arvore!\n", valor);
                    } else {
                        printf("Valor %d NAO ENCONTRADO na arvore!\n", valor);
                    }
                }
                break;
                
            case 4: // READ - Listar todos
                printf("\nLISTAGEM DE VALORES\n");
                if(estaVazia_ArvBin(raiz)) {
                    printf("Arvore esta vazia!\n");
                } else {
                    printf("Valores na arvore (em ordem crescente):\n");
                    printf("[ ");
                    emOrdem_ArvBin(raiz);
                    printf("]\n");
                }
                break;
                
            case 5: // READ - Mostrar estrutura
                printf("\nESTRUTURA VISUAL DA ARVORE\n");
                if(estaVazia_ArvBin(raiz)) {
                    printf("Arvore esta vazia!\n");
                } else {
                    printf("Estrutura da arvore (leia de cima para baixo):\n\n");
                    imprime_arvore(raiz, 0);
                }
                break;
                
            case 6: // READ - Informações
                printf("\nINFORMACOES DETALHADAS\n");
                if(estaVazia_ArvBin(raiz)) {
                    printf("Arvore esta vazia!\n");
                } else {
                    printf("------------------------------------------\n");
                    printf("           ESTATISTICAS                  \n");
                    printf("------------------------------------------\n");
                    printf("Total de nos: %d\n", totalNO_ArvBin(raiz));
                    printf("Altura da arvore: %d\n", altura_ArvBin(raiz));
                    printf("------------------------------------------\n\n");
                    
                    printf("------------------------------------------\n");
                    printf("             PERCURSOS                   \n");
                    printf("------------------------------------------\n");
                    printf("Pre-ordem:  ");
                    preOrdem_ArvBin(raiz);
                    printf("\nEm-ordem:   ");
                    emOrdem_ArvBin(raiz);
                    printf("\nPos-ordem:  ");
                    posOrdem_ArvBin(raiz);
                    printf("\n------------------------------------------\n");
                }
                break;
                
            case 0: // Sair
                printf("\nFinalizando programa...\n");
                printf("Liberando memoria...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Escolha um numero de 0 a 6.\n");
        }
        
        if(opcao != 0) {
            pausar();
        }
        
    } while(opcao != 0);
    
    libera_ArvBin(raiz);
    printf("Memoria liberada com sucesso!\n");
    printf("Programa finalizado!\n\n");
    
#ifdef _WIN32
    system("pause");
#endif
    
    return 0;
}
