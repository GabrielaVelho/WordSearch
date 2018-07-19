#include <stdio.h>
#include <string.h>

typedef struct Palavra
{
    char palavra[30];
}Palavra;

int pesquisaBinaria(Palavra v[], char p[], int inicio, int fim)
{
    int meio;
    while(inicio <= fim)
    {
        meio = (inicio + fim)/2;
        if(strcmp(p, v[meio].palavra) == 0)
            return meio;
        else if(strcmp(p, v[meio].palavra) < 0)
            fim = meio - 1;
        else
            inicio = meio + 1;

        printf("Posicao: %d, Palavra: %s\n", meio, v[meio].palavra);
    }

    return -1;
}

int main()
{
    int i = 0;
    int pos;
    char p[30];
    Palavra colecao[29858];
    FILE *in = fopen("palavras.txt", "r");
    while(fscanf(in, "%s", p) != EOF)
    {
        strcpy(colecao[i].palavra, p);
        i++;
    }
    fclose(in);

    while(1)
    {
        printf("Digite uma palavra: ");
        scanf("%s", p);
        if((pos = pesquisaBinaria(colecao, p, 0, 29857)) != -1)
            printf("Linha: %d\n", pos + 1);
        else
            printf("\nPalavra não existe!\n");
    }

    printf("%s\n", colecao[23].palavra);
    return 0;
}
