#include <stdio.h>
#include <string.h>


void trocar(char *arr[], int i, int j) {
    char *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}


int particionar(char *arr[], int baixo, int alto, int *trocas, int *comparacoes) {
    char *pivot = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++) {
        (*comparacoes)++;

        if (strcmp(arr[j], pivot) <= 0) {
            i++;
            trocar(arr, i, j);
            (*trocas)++;
        }
    }
    trocar(arr, i + 1, alto);
    (*trocas)++;
    return (i + 1);
}


void quicksort(char *arr[], int baixo, int alto, int *trocas, int *comparacoes) {
    if (baixo < alto) {
        int pi = particionar(arr, baixo, alto, trocas, comparacoes);


        quicksort(arr, baixo, pi - 1, trocas, comparacoes);
        quicksort(arr, pi + 1, alto, trocas, comparacoes);
    }
}

int main() {
    char *arr[20] = {
            "maca", "banana", "pera", "uva", "laranja", "abacaxi", "limao", "manga", "abacate", "kiwi",
            "cereja", "morango", "pessego", "goiaba", "melancia", "framboesa", "amora", "caqui", "figo", "papaya"
    };
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int trocas = 0;
    int comparacoes = 0;

    printf("Vetor de entrada:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    quicksort(arr, 0, tamanho - 1, &trocas, &comparacoes);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s ", arr[i]);
    }
    printf("\n");

    printf("Numero de trocas: %d\n", trocas);
    printf("Numero de comparações: %d\n", comparacoes);


    char *mediana;
    if (tamanho % 2 == 0) {
        mediana = arr[tamanho / 2 - 1];
    } else {
        mediana = arr[tamanho / 2];
    }

    printf("Mediana: %s\n", mediana);


    FILE *arq_saida = fopen("frutas_ordenadas.txt", "w");
    if (arq_saida == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    fprintf(arq_saida, "Vetor de frutas ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        fprintf(arq_saida, "%s ", arr[i]);
    }
    fprintf(arq_saida, "\n");

    fprintf(arq_saida, "Numero de trocas: %d\n", trocas);
    fprintf(arq_saida, "Numero de comparaçoes: %d\n", comparacoes);
    fprintf(arq_saida, "Mediana: %s\n", mediana);

    fclose(arq_saida);

    return 0;
}
