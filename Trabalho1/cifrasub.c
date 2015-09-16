//Segurança e Auditoria de Sistemas.
//Aluno: Daniel Maicon Lauermann.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
  FILE *fp;
  char string[1234];
  int i=0,lenstr=0,x[256],j=0;
  char ch;
  FILE *randkey;
  FILE *cifrado;
  FILE *decifrado;

  fp = fopen("entrada.txt","r");

  int opc;
  printf("\nOpc: 1=Cifrar - 2=Decifrar      Selecione: ");
  scanf("%d",&opc);

  if(opc==1){
    randkey = fopen ("key.txt","w");
    cifrado = fopen("cifrado.txt","w");
    lenstr = fread(string,sizeof (char),1234,fp);

    srand( (unsigned)time(NULL) );                       	// Sincronizando com o relógio do computador para evitar repetição de números; 
    for(i=0;i<256;i++){
      // x[i]= rand() % 255;
      x[i]=i;											//Gerar números aleatórios;
      //fwrite(&x[i],sizeof(int),1, randkey);  		      				
    }
    fwrite(x,sizeof(int),256, randkey);  		      				

    for(i=0;i<lenstr;i++){
      string[i] = x[string[i]];
    }
    fwrite(string, sizeof(char),lenstr, cifrado);	  //Gravando números aleatórios;
  }

  if(opc==2){
    cifrado = fopen("cifrado.txt","r");
    decifrado = fopen("decifrado.txt","w");    
    lenstr = fread(string,sizeof (char),1234,cifrado);       // Lendo texto cifrado;
    randkey = fopen ("key.txt","r");

    fread(x,sizeof (int),256,randkey);				/*Lendo a chave*/
    int dec[256];	
    for(i=0;i<256;i++){
      int temp = x[i];
      printf("%d\n",temp);
      dec[temp]=i;
    }
    for(i=0;i<lenstr;i++){
      string[i] = dec[string[i]];
    }
    fwrite(string, sizeof(char), lenstr, decifrado);	  //Gravando números aleatórios;
  }    
  fclose(randkey);
}
