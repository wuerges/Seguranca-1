//Aluno: Daniel Maicon Lauermann.
#include <stdio.h>
#include <stdlib.h>

void cifrar(char *l, int key, int lenstr){
    int i, f =0;
    FILE *arq1;
    
    arq1 = fopen("Cifrado.txt","a+");   	
    for(i=0;i<lenstr; i++){
		 putc((l[i]  + key) % 256, arq1);
    
	}
	fclose(arq1);
	
}
void descifrar(char *l , int key, int lenstr){
    int i;
    FILE *desc;
    desc = fopen("Descifrado.txt","a+");   		
    for(i=0;i<lenstr; i++) putc(l[i] - key, desc); 

	fclose(desc);
}

int main()
{
   FILE *fp;
   char *string=NULL;
   int i=0, key=0, menu=0, lenstr=0;
   char ch;
   printf("Sua entrada deve estar no arquivo Entrada.txt\n\n");
   printf("Tecle 1 para cifrar e 2 para descifrar: ");
   scanf("%d",&menu);
   printf("Entre com a chave: ");
   scanf("%d",&key);
   fflush(stdin);
   fp = fopen("Entrada.txt","a+");   	
   if(!fp)
    {
      printf( "Erro na abertura do arquivo");
      exit(0);
    }
    
    while((ch=fgetc(fp)) != EOF){
        string = (char *)realloc(string, (++lenstr) * sizeof(char));
    	string[lenstr - 1] = ch;
    
    }
    if(menu==1)
    cifrar(string, key, lenstr);
    if(menu==2)
    descifrar(string, key, lenstr);
   return 0;
}
//Créditos: Partes do código foram desenvolvidas com ajuda do colega Dalton.
