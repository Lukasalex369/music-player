#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#include<string.h>
#pragma warning(disable : 4996) //Visual studio fica dando este erro, desabilitei. nao achei solucao

#define MAX 100

struct musicplayer { // struc criada apartir da aula 2
    char* nomedamusica;
    int tempodeduracao;
    char* cantoroubanda;
}Head[MAX];

void exibirMenu() { // MENU 
    setlocale(LC_ALL, "Portuguese");
    printf("\n\tSelecione umas das opções a seguir:\n");
    printf("\tDigite 1 para dicionar uma nova Musica\n"
        "\tDigite 2 para ver a lista de musicas\n"
        "\tDigite 3 para reproduzir musica\n"
        "\tDigite 4 para sair\n\n");
}

char* addnaemoria(int tamanho) {
    char* info = NULL;
    info = (char*)malloc(sizeof(tamanho) * sizeof(char));

    if (info == NULL) {
        printf("falha ao adicionar (memoria insuficiente!)");
        exit(1);
    }
    return info;
}

void adicionarmusica(int registro) {
    char dados[MAX];
    printf("\n\t\tNome da musica: ");
    scanf_s("%[^\n]s", dados, _countof(dados));
    setbuf(stdin, NULL);
    Head[registro].nomedamusica = addnaemoria(strlen(dados)); // alocacao e copia de dados
    strcpy(Head[registro].nomedamusica, dados);

    printf("\t\tTempo de duracao em minutos: ");
    scanf_s("%d", &Head[registro].tempodeduracao);
    setbuf(stdin, NULL);

    printf("\t\tCantor ou banda: ");
    scanf_s("%[^\n]s", dados, _countof(dados));
    setbuf(stdin, NULL);
    Head[registro].cantoroubanda = addnaemoria(strlen(dados)); // alocacao e copia de dados
    strcpy(Head[registro].cantoroubanda, dados);

}
// funcao para listar musicas alocadas na struct
void listademusica(int musicasnalista) {
    int i;
    int contagem = 1;
    for (i = 0; i < musicasnalista; i++) {
        printf("\n\tMusica nº: %d\n", contagem++);
        printf("\tNome da musica: %s\n", Head[i].nomedamusica);
        printf("\tTempo de duracao da musica: %d\n", Head[i].tempodeduracao);
        printf("\tBanda: %s\n", Head[i].cantoroubanda);
    }
    printf("\n\n");
}

void exibirMusica(int indice) {
    printf("\n\tNome da musica: %s\n", Head[indice].nomedamusica);
    printf("\tTempo de duracao da musica: %d\n", Head[indice].tempodeduracao);
    printf("\tNome do cantor ou da banda: %s\n", Head[indice].cantoroubanda);
}

int pesquisarMusica(int musicasnalista, char* mostrarnomedamusica) {
    int i;

    for (i = 0; i < musicasnalista; i++) {
        if (strcmp(mostrarnomedamusica, Head[i].nomedamusica) == 0)
            return i;
    }
    return -1;
}


int leitor() {
    int opcao;

    printf("\n\tA opção selecionada foi: ");
    scanf_s("%d", &opcao);
    setbuf(stdin, NULL);

    return opcao;
}

int main() { // funcao do menu com switch
    int numerodamusica = 0;
    int opcaoselecionada;

    do {
        exibirMenu();
        opcaoselecionada = leitor();

        switch (opcaoselecionada) {
        case 1:
            adicionarmusica(numerodamusica++);
            break;
        case 2:
            listademusica(numerodamusica);
            break;
        case 4:
            printf("\n\tSaindo...");
            break;
        default:
            printf("\n\tReproduzindo musica...\n"); // Nao foi implementadado esta funcao
            exibirMenu();
            opcaoselecionada = leitor();
        }

    } while (opcaoselecionada != 4);
}