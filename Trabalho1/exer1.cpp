#include <stdio.h>
#include <stdlib.h>



void cifrar(char *l, int key, int lenstr){
    int i, f =0;
    FILE *arq1;
    
    arq1 = fopen("Cifrado.txt","a+");   		/* Arquivo ASCII, para escrita */
    for(i=0;i<lenstr; i++){
		 putc((l[i]  + key) % 256, arq1);/* Grava a string, caractere a caractere */
    
	}
	fclose(arq1);
	
}
void descifrar(char *l , int key, int lenstr){
    int i;
    FILE *desc;
    desc = fopen("Descifrado.txt","a+");   		/* Arquivo ASCII, para escrita */
    for(i=0;i<lenstr; i++) putc(l[i] - key, desc); /* Grava a string, caractere a caractere */

	fclose(desc);
}

int main()
{
   FILE *fp;
   char *string=NULL;
   int i=0, key=0, menu=0, lenstr=0;
   char ch;
   
   printf("Tecle 1 para cifrar e 2 para descifrar: ");
   scanf("%d",&menu);
   //fflush(stdin);
   printf("Entre com a chave: ");
   scanf("%d",&key);
   fflush(stdin);
   fp = fopen("Entrada.txt","a+");   		/* Arquivo ASCII, para escrita */
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
 // for(i=0; string[i]; i++) putc(string[i] + 5, fp); /* Grava a string, caractere a caractere */
  fclose(fp);
   return 0;
}

