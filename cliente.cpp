#include<stdio.h>
#include<string.h>

struct Data {

    int dia, mes, ano;
    int diaAtual = 16, mesAtual = 8, anoAtual = 2023;

    Data() {
        dia = 0,mes = 0,ano = 0;
    }

    void ler() {
        printf("Dia: ");
        scanf("%d", &dia);
        printf("Mes: ");
        scanf("%d", &mes);
        printf("Ano: ");
        scanf("%d", &ano);
    }

    void imprimir() {
        printf("%02d/%02d/%04d\n", dia, mes, ano);
    }

    int calcularIdade() {
        bool fezAniversario = false;
        if (mes < mesAtual) {
            fezAniversario = true;
        }
        if (mes == mesAtual && dia <= diaAtual) {
            fezAniversario = true;
        }
        if (fezAniversario) {
            return anoAtual - ano;
        } else {
            return (anoAtual - ano) - 1;
        }
    }

};

struct Cliente {

    char nome[100];
    Data nascimento;
    char sexo;
    int idade;

    Cliente() {
        strcpy(nome, "");
        sexo = ' ';
        idade = 0;
    }

    void ler() {
        fflush(stdin);
        printf("Nome: ");
        scanf("%[^\n]s", nome);
        fflush(stdin);
        printf("Sexo: ");
        scanf("%c", &sexo);
        nascimento.ler();
        idade = nascimento.calcularIdade();
    }

    void imprimir() {
        printf("Nome: %s\nSexo: %c\nIdade: %d\nNascimento: ",
               nome, sexo, idade);
        nascimento.imprimir();
    }

};

int menu() {
    printf("Menu\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Listar Clientes\n");
    printf("3. Sair\n");
    int resp;
    scanf("%d", &resp);
    return resp;
}

int main() {

    Cliente c[50];
    int id = 0, resp;

    do {
        resp = menu();

        if (resp == 1) {
            c[id++].ler();
        } else if (resp == 2) {
            for (int i = 0; i < id; i++) {
                c[i].imprimir();
            }
        }
    } while (resp == 1 || resp == 2);

    return 0;
}
