#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Veiculo{
  int  cpf_dono;
  char placa[8];
  char modelo[100];
};

struct Pessoa{
  char nome[100];
  int  cpf;
};

int main() {

    int option = 0;

    while(option != 5) {
        printf("BANCO DE VEÍCULOS\n");
        printf("(1) Consultar Veículo\n");
        printf("(2) Consultar Pessoa\n");
        printf("(3) Adicionar Veículo\n");
        printf("(4) Adicionar Pessoa\n");
        printf("(5) Sair\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nPlaca do Veículo:\n");
                scanf("", &plate);
            break;
            case 2:
                prinf("\nCPF da pessoa:\n");
                scanf("", &cpf);
            break;
            case 3:
                printf("\nAdicionar Novo Veículo:\n");
                printf("\nCPF do Proprietário:\n");
                scanf("", &cpf);
                printf("\nPlaca do Veículo:\n");
                scanf("", &plate);
                printf("\nModelo do Veículo:\n");
                scanf("", &model);
            break;
            case 4:
                printf("\nAdicionar Nova Pessoa:\n");
                printf("\nNome da Pessoa:\n");
                scanf("", &name);
                printf("\nCPF da Pessoa:\n");
                scanf("", &cpf);
            break;
            default:
            break;
        }
    }

    return 0;
}