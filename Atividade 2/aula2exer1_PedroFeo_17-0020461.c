#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Pessoa{
  char nome[100];
  int  cpf;
  char placa[100];
  char modelo[100];
};

void sortCars(struct Pessoa *lista, int n) {
  for(int i = 0; i <= n; i++) {
    printf("Placa: %s\n", lista[i].placa);
  }
  struct Pessoa temp;
  for(int i = 0; i <= n; i++) {
      for(int j=i+1; j <= n; j++){
          int comp = strcmp(lista[i].placa, lista[j].placa);
          if(comp > 0) {
              temp = lista[i];
              lista[i] = lista[j];
              lista[j] = temp;
          }
      }
  }
}

int buscarCarro(struct Pessoa *lista, int n, char *placa) {
  for(int i=0; i<n; i++){
    if (strcmp(lista[i].placa, placa)==0){
      return i;
    }
  }
  return -1;
}

void recuperar(struct Pessoa *lista, int n) {
  char placa[100];
  printf("Digite a Placa:");
  scanf("%s",&placa);
  int i = buscarCarro(lista, n, placa);
  if(i >= 0) {
    printf("Placa: %s\n", lista[i].placa);
    printf("Nome do prorpietario: %s\n",lista[i].nome);
    printf("cpf: %d\n",lista[i].cpf);
    printf("Modelo: %s\n",lista[i].modelo);
    printf("\n");
  }
  else {
    printf("Veículo não encontrado \n");
  }
}

void inserir(struct Pessoa *lista, int n) {
  char placa[100];
  printf("Digite a Placa:");
  scanf("%s",&placa);
  int i = buscarCarro(lista, n, placa);
  if(i >= 0) {
    printf("Veículo já registrado");
  }
  else {
      memcpy(lista[n].placa, placa, 100);
      printf("Digite o nome: ");
      scanf(" %[^\n]",lista[n].nome);
      printf("Digite o cpf: ");
      scanf("%d",&lista[n].cpf);
      printf("Digite o Modelo do carro:");
      scanf(" %[^\n]",lista[n].modelo);
      sortCars(lista, n);
  }
}

void alterar(struct Pessoa *lista, int n) {
  char placa[100];
  int j;
  printf("Digite a Placa:");
  scanf("%s",&placa);
  int i = buscarCarro(lista, n, placa);
  if(i >= 0) {
    printf("Digite o novo nome do proprietário: ");
    scanf(" %[^\n]",lista[i].nome);
    printf("Digite o novo cpf do proprietário: ");
    scanf("%d",&lista[i].cpf);
    printf("Digite o novo Modelo do carro:");
    scanf(" %[^\n]",lista[i].modelo);
  }
}

int apagar(struct Pessoa *lista, int n) {
  char placa[100];
  int j;
  printf("Digite a Placa:");
  scanf("%s",&placa);
  int i = buscarCarro(lista, n, placa);
  if(i >= 0) {
    for(j=i+1; j<n; j++){
      strcpy(lista[j-1].nome,lista[j].nome);
      lista[j-1].cpf=lista[j].cpf;
      strcpy(lista[j-1].placa,lista[j].placa);
      strcpy(lista[j-1].modelo,lista[j].modelo);
    }
    return 1;
  }
  return 0;
}

int main(){
 
  struct Pessoa *lista;
  int capacity;
  int n; 
  int option; 
  int i;
  FILE *fp;

  
  fp = fopen("lista.dat","r");

  if(fp==NULL){
    n = 0;
    capacity = 10;
    lista = (struct Pessoa *)malloc(sizeof(struct Pessoa)*capacity);
  }
  else{ 
    fread(&n, sizeof(int), 1, fp);
    capacity = n*2; 
    lista = (struct Pessoa *)malloc(sizeof(struct Pessoa)*capacity);
    fread(lista, sizeof(struct Pessoa), n, fp);
    fclose(fp);
  }
  
  do{
    printf("*** Menu ***\n");
    printf("1) Cadastrar Carro.\n");
    printf("2) Recuperar Carro.\n");
    printf("3) Apagar.\n");
    printf("4) Alterar.\n");
    printf("5) Salvar alterações e sair.\n");
    scanf("%d",&option);

    if(option==1){
      if(n==capacity){
	     capacity *= 2;
         lista = realloc(lista, sizeof(struct Pessoa)*capacity);
      }

      inserir(lista, n);
      n++;
    }
    else if(option==2){
      recuperar(lista, n);
    }
    else if(option==3){
      int hasDeleted = apagar(lista, n);
      if(hasDeleted) {
        n--;
      }
      else {
        printf("Veículo não encontrado");
      }
    }
    else if(option==4) {
      alterar(lista, n);
    }
  }while(option!=5); 
  if(n>0){
    fp = fopen("lista.dat","w");
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(lista, sizeof(struct Pessoa), n, fp);
    fclose(fp);
  }
  free(lista);
  return 0;
}