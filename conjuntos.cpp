#include<stdio.h>
#define TAM 20
void troca(int vet[], int x, int y) {
    int tmp = vet[x];
    vet[x] = vet[y];
    vet[y] = tmp;
}

void bubbleSort(int vet[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (vet[j] > vet[j + 1]) {
                troca(vet, j, j + 1);
            }
        }
    }
}

struct Conjunto {

    int n;
    int vet[TAM];

    Conjunto() {
        n = 0;
    }

    void ler() {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &vet[i]);
        }
        bubbleSort(vet, n);
    }

    void imprimir() {
        for (int i = 0; i < n; i++) {
            printf("%d\n", vet[i]);
        }
    }

    void uniao(Conjunto c2) {
        if (c2.n + n > TAM) {
            printf("Tamanho excedido\n");
            return;
        }
        for (int i = n, j = 0; j < c2.n; i++, j++) {
            vet[i] = c2.vet[j];
            n++;
        }
        bubbleSort(vet, n);
    }

    void intersecao(Conjunto c2) {
        int tmp[TAM], n2 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < c2.n; j++) {
                if (vet[i] == c2.vet[j]) {
                    tmp[n2] = vet[i];
                    n2++;
                    break;
                }
            }
        }
        for (int i = 0; i < n2; i++) {
            vet[i] = tmp[i];
        }
        n = n2;
    }

    bool iguais(Conjunto c2) {
        if (n != c2.n) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (vet[i] != c2.vet[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    Conjunto c;
    c.ler();
    Conjunto c2;
    c2.ler();
    printf("%d\n", c.iguais(c2));
    return 0;
}
