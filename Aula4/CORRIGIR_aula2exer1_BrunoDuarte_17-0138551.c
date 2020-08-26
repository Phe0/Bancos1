#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>


typedef struct {
    long long int cpf;
    char placa[100];
    char color[50];
    char model[100];
} Car;


struct Pessoa {
    long long int cpf;
    int age;
    char nome[100];
};

//Este mergesort está com alguns problema de implementação 
void merge( struct Pessoa * s, int left, int mid, int right)
{
    int size = right-left + 1;

    struct Pessoa * tmp = malloc(size * sizeof(s));
    int l = 0;
    int leftPos = left;
    int r = mid+1;

    while(leftPos <= mid && r <= right)
    {
        if(s[leftPos].cpf < s[r].cpf)
        {
            strcpy(tmp[l].nome,s[leftPos].nome);
            tmp[l].cpf = s[leftPos].cpf;
            tmp[l].age = s[leftPos].age;
            l++;
            leftPos++;
        }
        else
        {
            strcpy(tmp[l].nome,s[r].nome);
            tmp[l].cpf = s[r].cpf;
            tmp[l].age = s[r].age;
            l++;
            r++;
        }

    }
    while(leftPos <= mid)
    {
      strcpy(tmp[l].nome,s[leftPos].nome);
      tmp[l].cpf = s[leftPos].cpf;
      tmp[l].age = s[leftPos].age;
      l++;
      leftPos++;}

    while(r <= right)
    {
            strcpy(tmp[l].nome,s[r].nome);
            tmp[l].cpf = s[r].cpf;
            tmp[l].age = s[r].age;
            l++;
            r++;
    }

    for(l = 0; l < size; l++){
        strcpy(s[l].nome,tmp[l].nome);
        s[l].cpf = tmp[l].cpf;
        s[l].age = tmp[l].age;
      }

    free(tmp);
}

static void mergeSort( struct Pessoa * s, int left, int right)
{

    if(left < right)
    {
        int mid = (left+right)/2;
        mergeSort(s, left, mid);
        mergeSort(s, mid+1, right);
        merge(s, left, mid, right);
    }
}


int main(){

    Car *cars; 
    struct Pessoa *pessoas;    
    cars = (Car *)malloc(1000*sizeof(Car));
    pessoas = (struct Pessoa *)malloc(sizeof(struct Pessoa)*1000);

    char name[100];
    long long int cpf;
    int idade;
    char cpfs[100000];
    char final[1000000];
    int size = 0, flag = 1, cont = 0, cc = 0, option;

    FILE * file;
    file = fopen("pessoas.csv", "r+");
    
    // load file
    
    if(file!= NULL){
       while(fscanf(file, "%lld,%s,%d\n", &cpf, name, &idade) != EOF){
            printf("%s\n", name);
            pessoas->cpf = cpf;
            strcpy(pessoas->nome, name);
            pessoas->age = idade;
            pessoas++;
            cont++;
       }
    }

    while(flag){

        printf("======================ESCOLHA UM OPÇÃO=================================\n");    
        printf("1 - Cadastrar Pessoa\n");
        printf("2 - Cadastrar Veículo\n");
        printf("3 - Consultar\n");
        printf("4 - Sair\n");
        printf("=================================================================\n");    

        scanf("%d", &option);
        system("clear");

        switch (option)
        {
        case 1:

            file = fopen("pessoas.csv", "w");
            printf("Digite o CPF da Pessoa: ");
            //(scanf("%lld", &pessoas->cpf) == 1) ? printf("cpf valido\n") : printf("cpf invalido");  
            if(scanf("%lld", &pessoas->cpf) == 1){
                printf("CPF válido, prossiga\n");
            }
             else {   
                printf("CPF Inválido. Tente Novamente\n");
                //break;
                return 0;
            }
            while ((getchar()) != '\n'); 
            printf("Digite o nome: "); scanf("%[^\n]", pessoas->nome);
            printf("Informe a idade: "); scanf("%d", &pessoas->age);       
            //fprintf(file, "%lld,%s,%d\n", pessoas->cpf, pessoas->nome, pessoas->age);
            pessoas++;
            cont++;
            break;
        
        case 2:

            file = fopen("cars.csv", "w");
            printf("Digite CPF do Proprietário do Veículo: "); scanf("%lld", &cars->cpf);
            
            if(scanf("%lld", &pessoas->cpf) == 1){
                printf("CPF válido, prossiga\n");
            }
             else {   
                printf("CPF Inválido. Tente Novamente\n");
                return 0;
            }

            while ((getchar()) != '\n'); 
            printf("Digite a Placa do Carro(id): ");scanf("%s", cars->placa);
            printf("Informe o modelo: "); scanf("%s", cars->model);
            printf("Informe a cor do veículo: "); scanf("%s", cars->color);       
            //fprintf(file, "%s,%s,%s\n", cars->placa, cars->model, cars->color);
            cars++;
            cc++;

            break;

        case 3: 
            printf("Digite o CPF do proprietário do Veículo: "); scanf("%lld", &cpf);
            printf("=================Dados Correspondentes==================\n");
            cars -= cc;
            for (int i = 0; i < cc; i++){
                if(cars->cpf == cpf){
                    printf("%lld\n", cars->cpf);
                    printf("Modelo: %s\n", cars->model);
                    printf("Cor: %s\n", cars->color);
                    printf("Placa: %s\n", cars->placa);
                }
               cars++;
            
            }
                        
            printf("========================================================\n");


            break;
        default:
            pessoas -= cont;
            mergeSort(pessoas, 0, cont - 1); 

            
            for (int i = 0; i < cont; i++)
              fprintf(file,"%lld,%s,%d\n", pessoas[i].cpf, pessoas[i].nome, pessoas[i].age);
            
            cars -= cc;
            for (int i = 0; i < cc; i++, cars++)
                fprintf(file, "%s,%s,%s\n", cars->placa, cars->model, cars->color);
        

            
            return 0;
        }
    }
    

    return 0;
}

/*

void CadastrarPessoa(Pessoa * pessoas){


    //Pessoa * pessoas;
    int capacity = 10;
    pessoas = (Pessoa *)malloc(sizeof(Pessoa)*capacity);
    //Pessoa *lista_pessoas;
    FILE * file;
    int cont = 0;

    file = fopen("pessoas.csv", "a");
    
    printf("Digite o CPF da Pessoa: ");scanf("%lld", &pessoas->cpf);
    while ((getchar()) != '\n'); 
    printf("Digite o nome: "); scanf("%[^\n]", pessoas->nome);
    printf("Informe a idade: "); scanf("%d", &pessoas->age);
    

    fprintf(file, "%lld,%s,%d\n", pessoas->cpf, pessoas->nome, pessoas->age);
    pessoas++;

    //return pessoas;
}
*/


