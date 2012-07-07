/*
 * TITULO: Resposta P2 A do Exerc�cio T21
 * DATA: 13/Outubro/2010
 * 
 * Pode ser feito em trios no laborat�rio.
 * 
 * Considere o seguinte programa.
 * 
 * Observe que ele � um simple sistema que:
 * 	- cria uma estrutura para alunos
 *  - pede ao usu�rio que digite nome e matricula dos alunos
 *  - ordena pela matricula
 *  - imprime os dados ordenados
 *  - remove a alocacao
 *  
 *  Fa�a as seguintes altera��es no programa:
 *   - Dois processo, vamos chamar de P1 e P2
 *   - P1 ir� criar uma �rea compartilhada e solicitar ao usu�rio que
 *     a alimente. 
 *   - P2 ir� ordenar os dados
 *   - P1 ir� imprimir os dados ordenados e desalocar
 *  
 *  VEJA QUE N�O TER� MALLOC, ter�s que usar mem�ria compartilhada
*/

/* Nesta solu��o, P1 e P2 s�o realmente processos independentes
 * compilados separadamente. 
 * 
 * Este � o c�digo do P2
 **/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <termios.h>

#define STRM 300
#define TAM 2

#define CHAVE2 87654321
#define CHAVE 2030405060

typedef struct {
    char nome[STRM];
    int mat;
} DADOS;

typedef struct {
    int p1;
    int p2;
} PROCESSOS;


int lestring(char[], int);
int ordena(DADOS *, int);
int ledados(DADOS *, int);
int imprime(DADOS *, int);
int tratador10(int signal);
int tratador12(int signal2);
int tratador15(int signal3);
int lerpid();
void gravarpid();
char var[100];
int envio = 0;
int sig = 0;

int main()
{
    
  signal(10, tratador10);
  signal(12, tratador12);
  signal(15, tratador15);
  gravarpid();	

while(1){  	

    DADOS *d;
    char *controle;

    int idarea, chave, tam;

    tam = (TAM * sizeof(DADOS)) + 1;

    idarea = shmget(CHAVE, tam, IPC_EXCL);
    if (idarea == -1) {
	fprintf(stderr, "Erro no shmget. Chave %d existe? Foi craida?\n",
		CHAVE);
	return (1);
    }

    d = (DADOS *) shmat(idarea, 0, 0);
    if (d == NULL) {
	fprintf(stderr, "ERRO ao tentar se conectar a area\n");
	return (1);
    }
  while(sig == 0){
  if(envio == 12){
        printf("Ordenando pela matricula\n");
        ordena(d, TAM);
        
         int pidp = lerpid();
         sprintf(var, "kill -10 %d", pidp);
         system(var);

    
   }
   else if(envio == 10) {
	printf("Imprimindo...\n");
  	imprime(d, TAM);
   }
   else
        return (0);   	
  }
}
}
void gravarpid(){

    PROCESSOS *te2;
    int idarea2, chave2, tam2;
    tam2 = (TAM * sizeof(PROCESSOS)) + 1;
    idarea2 = shmget(CHAVE2, tam2, IPC_CREAT | 0664);
    if(idarea2 == -1) {
        fprintf(stderr, "Erro no shmget\n");
    }

    te2 = (PROCESSOS *) shmat(idarea2, 0, 0);
    if (te2 == NULL) {
        fprintf(stderr, "ERRO ao tentar se conectar a area\n");
   }
   te2[0].p2 = getpid();
   
}
   
int lerpid(){
       PROCESSOS *te2;
       int idarea2, chave2, tam2;
   
       tam2 = (TAM * sizeof(PROCESSOS)) + 1;    
   
       idarea2 = shmget(CHAVE2, tam2, IPC_EXCL);
       if(idarea2 == -1) {
           fprintf(stderr, "Erro no shmget\n");
           return (1);
       }
   
       te2 = (PROCESSOS *) shmat(idarea2, 0, 0);
       if (te2 == NULL) {
          fprintf(stderr, "ERRO ao tentar se conectar a area\n");
          return (1);
       }
       return te2[0].p1;
}

int tratador10(int signal){
	sig = 1;
	envio = 10;	   
}

int tratador12(int signal2){
	sig = 1;
	envio = 12;
}
     
int tratador15(int signal3){
	sig = 1;
	envio = 15;
}

int imprime(DADOS * d, int t)
{
    int i;
    for (i = 0; i < t; i++) {
	printf("%10d %s\n", d[i].mat, d[i].nome);
    }
}

int ledados(DADOS * d, int t)
{
    int i;

    for (i = 0; i < t; i++) {
	printf("\n[%d] Nome: ", i);
	lestring(d[i].nome, STRM);
	printf("[%d] Matricula: ", i);
	while (scanf("%d", &d[i].mat) != 1) {
	    /* Se digitou algo que nao eh numero, limpa buffer
	     * (um fflsuh moderado) */
	    while (fgetc(stdin) != '\n');
	}
    }
}

int ordena(DADOS * d, int t)
{
    int i, m, j;
    DADOS temp;

    for (i = 0; i < t; i++) {
	/* Metodo da sele��o. Horr�vel, mas simples e f�cil de implementar
	 * (e como ningu�m aqui ir� cadastrar milhares de alunos... */
	m = i;
	for (j = i + 1; j < t; j++) {
	    if (d[m].mat > d[j].mat)
		m = j;
	}
	if (m != i) {
	    temp = d[i];
	    d[i] = d[m];
	    d[m] = temp;
	}
    }
}

int lestring(char s[], int max)
{
    int i = 0;
    char letra;

    for (i = 0; i < (max - 1); i++) {
	letra = fgetc(stdin);
	if ((letra == '\n') && (i == 0)) {
	    i = i - 1;
	    continue;
	}
	if (letra == '\n')
	    break;
	s[i] = letra;
    }
    s[i] = 0;
    return (i);
}
