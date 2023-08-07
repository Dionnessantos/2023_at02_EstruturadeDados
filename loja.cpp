#include <stdio.h>

struct Funcionario {
    char nome[100];
    char cargo[100];
    double salarioB, beneficio, descontos;
};

struct Loja {
    Funcionario funcionarios[10];
    int qtdFuncionarios;

    Loja() {
        qtdFuncionarios = 0;
    }

    void lerString(char dest[], int max_len) {
        int i = 0;
        char ch;
        while ((ch = getchar()) != '\n' && i < max_len - 1) {
            dest[i++] = ch;
        }
        dest[i] = '\0';
    }

    void cadastrarFuncionario() {
        if (qtdFuncionarios >= 10) {
            printf("Quantidade de funcionarios cheio.\n");
            return;
        }

        Funcionario novoFuncionario;
        printf("\nCadastro do Funcionario %d:\n", qtdFuncionarios + 1);

        printf("Nome: ");
        lerString(novoFuncionario.nome, 100);

        printf("Cargo: ");
        lerString(novoFuncionario.cargo, 100);

        printf("Salario base: ");
        scanf("%lf", &novoFuncionario.salarioB);

        printf("Beneficio: ");
        scanf("%lf", &novoFuncionario.beneficio);


        novoFuncionario.descontos = descontoS(novoFuncionario.salarioB);

        funcionarios[qtdFuncionarios] = novoFuncionario;
        qtdFuncionarios++;
    }

    void mostrarDadosFuncionarios() {
        printf("\nDADOS DOS FUNCIONARIOS:\n");
        for (int i = 0; i < qtdFuncionarios; i++) {
            printf("\nFuncionario %d:\n", i + 1);
            printf("Nome: %s\n", funcionarios[i].nome);
            printf("Cargo: %s\n", funcionarios[i].cargo);
            printf("Salario base: %.2lf\n", funcionarios[i].salarioB);
            printf("Beneficio: %.2lf\n", funcionarios[i].beneficio);
            printf("Descontos: %.2lf\n", funcionarios[i].descontos);
            printf("Salario liquido: %.2lf\n", funcionarios[i].salarioB + funcionarios[i].beneficio - funcionarios[i].descontos);
        }
    }


    double descontoS(double salario) {
        double descontos;
        if (salario <= 1320.0)
            descontos = salario * 0.075;
        else if (salario <= 2257.26)
            descontos = salario * 0.09;
        else if (salario <= 3856.94)
            descontos = salario * 0.12;
        else if (salario <= 7507.29)
            descontos = salario * 0.14;
        else
            descontos = 854.15;
        return descontos;
    }

    double mediaSalarial() {
        double somaSalarios = 0.0;
        if (qtdFuncionarios == 0) {
            printf("Nao tem funcionarios cadastrados\n");
            return 0.0;
        }

        for (int i = 0; i < qtdFuncionarios; i++) {
            somaSalarios += funcionarios[i].salarioB + funcionarios[i].beneficio - funcionarios[i].descontos;
        }
        return somaSalarios / qtdFuncionarios;
    }

    void MaiorSalario() {
        if (qtdFuncionarios == 0) {
            printf("Nao tem funcionarios cadastrados\n");
            return;
        }

        double maiorSalario = funcionarios[0].salarioB + funcionarios[0].beneficio - funcionarios[0].descontos;
        int indiceMaiorSalario = 0;

        for (int i = 1; i < qtdFuncionarios; i++) {
            double salarioLiquido = funcionarios[i].salarioB + funcionarios[i].beneficio - funcionarios[i].descontos;
            if (salarioLiquido > maiorSalario) {
                maiorSalario = salarioLiquido;
                indiceMaiorSalario = i;
            }
        }

        printf("\nFuncionario com maior salario:\n");
        printf("Nome: %s\n", funcionarios[indiceMaiorSalario].nome);
        printf("Cargo: %s\n", funcionarios[indiceMaiorSalario].cargo);
        printf("Salario liquido: %.2lf\n", maiorSalario);
    }
};

int main() {
    Loja l;
    int opcao;

    do {
        printf("\nMENU:\n");
        printf("1. Cadastrar Funcionario\n");
        printf("2. Mostrar Dados dos Funcionarios\n");
        printf("3. Media Salarial da Loja\n");
        printf("4. Funcionario com Maior Salario\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d%*c", &opcao);

        switch (opcao) {
            case 1:
                l.cadastrarFuncionario();
                break;
            case 2:
                l.mostrarDadosFuncionarios();
                break;
            case 3:
                l.mediaSalarial();
                break;
            case 4:
                l.MaiorSalario();
                break;
            case 0:
                break;

        }
    } while (opcao != 0);

    return 0;
}
