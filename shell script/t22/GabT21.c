/*
 * TITULO: Resposta P1 A do Exerc�cio T21
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
 **/
#include <stdio.h>
#include <stdlib.h>

#define STRM 300
#define TAM 3

typedef struct {
    char nome[STRM];
    int mat;
} DADOS;

int lestring(char[], int);
int ordena(DADOS *, int);
int ledados(DADOS *, int);
int imprime(DADOS *, int);

int main()
{
    DADOS *d;

    d = (DADOS *) malloc(TAM * sizeof(DADOS));
    if (d == NULL) {
	fprintf(stderr, "ERRO ao tentar alocar\n");
	return (1);
    }
    printf("Digite os dados para %d alunos\n", TAM);
    ledados(d, TAM);

    printf
	("Voce digitou com sucesso %d alunos. Ordenando pela matricula\n",
	 TAM);
    ordena(d, TAM);

    printf("Imprimindo...\n");
    imprime(d, TAM);

    free(d);
    return (0);
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
