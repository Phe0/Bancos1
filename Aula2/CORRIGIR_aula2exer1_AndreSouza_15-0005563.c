#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Carro{
  char ano[5];
  char cpf[12];
  char placa[7];
  char modelo[100];
};

void limpar(){
  getchar();
  system("clear || cls");
}

int main(){
 
  struct Carro *lista;
  int capacity;
  int n; 
  int option; 
  int i;
  FILE *fp;

  
  fp = fopen("lista.txt","r");
  if(fp==NULL){
    n = 0;
    capacity = 10;
    lista = (struct Carro *)malloc(sizeof(struct Carro)*capacity);
  }
  else{ 
    fread(&n, sizeof(int), 1, fp);
    capacity = n*2; 
    lista = (struct Carro *)malloc(sizeof(struct Carro)*capacity);
    fread(lista, sizeof(struct Carro), n, fp);
    fclose(fp);
  }
  
  do{
    printf("*** Menu ***\n");
    printf("1) Cadastrar Carro.\n");
    printf("2) Exibir Carros.\n");
    printf("3) Apagar.\n");
    printf("4) Sair.\n");
    scanf("%d",&option);
    limpar();

    if(option==1){
      if(n==capacity){
	     capacity *= 2;
         lista = realloc(lista, sizeof(struct Carro)*capacity);
      }
      printf("Digite a placa do carro: ");
      scanf(" %[^\n]",lista[n].placa);
      printf("Digite o modelo do carro: ");
      scanf(" %[^\n]",lista[n].modelo);
      printf("Digite o ano: ");
      scanf(" %[^\n]",lista[n].ano);
      printf("Digite o CPF do dono: ");
      scanf(" %[^\n]",lista[n].cpf);
      limpar();

      n++; 
    }
    else if(option==2){
      for(i=0; i<n; i++){
	    printf("\n",i+1);
        printf("Placa: %s\n",lista[i].placa);
        printf("Ano: %s\n",lista[i].ano);
	    printf("Modelo: %s\n",lista[i].modelo);
        printf("CPF: %s\n",lista[i].cpf);
        printf("\n");
      }
      limpar();
    }
    else if(option==3){
      char placa[100];
      int j;
      printf("Digite a placa:");
      scanf("%s",&placa);
      for(i=0; i<n; i++){
             if (strcmp(lista[i].placa, placa)==0){
             	for(j=i+1; j<n; j++){
                         strcpy(lista[j-1].ano,lista[j].ano);
                         strcpy(lista[j-1].cpf,lista[j].cpf);
                         strcpy(lista[j-1].placa,lista[j].placa);
                         strcpy(lista[j-1].modelo,lista[j].modelo);
                 }
               n--;
               i=n;
              }
      }
      limpar();
    }
  }while(option!=4); 
  if(n>0){
    fp = fopen("lista.txt","w");
    fwrite(&n, sizeof(int), 1, fp);
    fwrite(lista, sizeof(struct Carro), n, fp);
    fclose(fp);
  }
  free(lista);
  return 0;
}