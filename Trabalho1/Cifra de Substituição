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
   decifrado = fopen("decifrado.txt","w");    
		
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
	  		
   	  for(i=0;i<lenstr;i++)		   
	      fwrite(&x[string[i]], sizeof(char),1, cifrado);	  //Gravando números aleatórios;
	}
	
	if(opc==2){
		cifrado = fopen("cifrado.txt","r");
		lenstr = fread(string,sizeof (char),1234,cifrado);       // Lendo texto cifrado;
        lenstr = strlen(string);
		randkey = fopen ("key.txt","r");
      
		fread(x,sizeof (int),256,randkey);				/*Lendo a chave*/
		int dec[256];	
		for(i=0;i<256;i++){
			int temp = x[i];
			printf("%d\n",temp);
			dec[temp]=i;
		}
		for(i=0;i<lenstr;i++){
			//for(j=127;j>-128;j--){
		/*	for(j=0;j<256;j++){	
				if(string[i]==x[j]){
					fwrite(&j,1,1, decifrado);  // Gravando texto decifrado;
					//break;
				}
		    }*/
	//		fwrite(&dec[string[i]], sizeof(char),1, cifrado);	  //Gravando números aleatórios;
				
	   }
	}    
	fclose(randkey);
}
