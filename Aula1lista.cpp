#include <stdio.h>
struct No{
    int N;
    No *prox;

    No (){
    N = 0;
    prox = NULL;
    }

    No(int _N){
        N = _N;
        prox = NULL;
    }
};

struct Lista{
    No *inicio, *fim;
    int n;

    Lista(){
    inicio = NULL;
    fim = NULL;
    n = 0;
    }

    bool vazia(){
        return  inicio == NULL;
    }

    void inserirInicio(int N){//o(1)
        n++;
        No *novo = new No(N);

        if(vazia()){
            inicio = novo;
            fim = novo;
            return;
        }

        novo ->prox = inicio;
        inicio = novo;
    }

    void inserirFinal(int N){//o(1)
        n++;
        No *novo = new No(N);

        if(vazia()){
            inicio = novo;
            fim = novo;
            return;
        }
        fim ->prox = novo;
        fim = novo;

    }



    void imprimir (){//o(1)
     No *aux = inicio;

     while(aux != NULL){
        printf("%d ->",aux->N);
        aux = aux->prox;
     }
     printf("\n");
    }

    int tamanho(){

        return n;
    }

    void removerInicio(){//o(1)

        if(tamanho()<=1){
            delete (inicio);
            inicio =NULL;
            fim = NULL;
            n = 0;
            return;
        }

        No *remover = inicio;
        inicio = inicio->prox;
        delete(remover);
        n--;

    }

    void removerFinal(){//o(n)
        if (tamanho() <= 1){
            delete(inicio);
            inicio = NULL;
            fim = NULL;
            n = 0;
            return;
        }
        No *penultimo = inicio;
        while(penultimo->prox!=fim){
            penultimo=penultimo->prox;
        }
        delete(fim);
        penultimo->prox = NULL;
        fim = penultimo;
        n--;
    }


    void remover(int pos){ //o(n)

        if(pos <=1){
            removerInicio();
            return;
        }

        if (pos >= tamanho()){
            removerFinal();
            return;
        }

        No *aux1 = inicio;
        for(int i = 0; i < pos - 2; i++){
            aux1 = aux1->prox;
        }
        No *remover = aux1->prox;
        No *aux2 = remover->prox;
        aux1->prox = aux2;
        delete(remover);
        n--;


    }
    void removerSegundoElemento(){//o(1)
    if (tamanho() > 1)
    {
        No* remover = inicio->prox;
        inicio->prox = remover->prox;
        delete (remover);
        n--;
    }
    }
    void inserirTamanhoAtual(){//o(1)
    inserirFinal(tamanho());
}
void inserirNumerosAteN(int N){//o(n)
    for (int i = 1; i <= N; i++)
    {
        inserirFinal(i);
    }
}
    void inserirPenultimaPosicao(int elemento){//o(n)
    if (tamanho() <= 1){
        return;
    }
    No* aux = inicio;
    for (int i = 0; i < tamanho() - 2; i++){
        aux = aux->prox;
    }

    No* novo = new No(elemento);
    novo->prox = aux->prox;
    aux->prox = novo;
    n++;
    }

};
int main (){
    Lista l;

    l.inserirInicio(30);
    l.inserirInicio(40);
    l.inserirInicio(0);
    l.inserirFinal(200);

    l.removerSegundoElemento();
    l.inserirTamanhoAtual();
    l.inserirNumerosAteN(20);
    l.inserirPenultimaPosicao(31);
   // l.remover();
    l.imprimir();



    printf("%d\n", l.tamanho());

    return 0;
}
