/* TITULO: Exemplo de como remover �rea compartilhada
 * DATA: 06/Outubro/2010
 * 
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <termios.h>


int main()
{
	int area, ch;

		printf("Digite a chave a ser pesquisada (0 se n�o tem chave): ");
		scanf("%d", &ch);
		if (ch>0){
			area = shmget(ch, 100, IPC_EXCL);
			/* O IPC_EXCL n�o vai criar uma nova �rea se chave j� existir
			 * NOTA: Para encontrar, chave e valor devem bater */
			if (area == -1 ){
				fprintf(stderr,"N�o encontrei chave %d\n", ch);
				return(1);
			}
			if (shmctl(area, IPC_RMID, 0)==-1){
				fprintf(stderr, "ERRO. N�o consegui remover. Tenho permiss�o?\n");
				return(1);
			}
			printf("Segmento de memoria ID=%d chave=%d removido\n", area, ch);
			return(0);
		}
		printf ("Ent�o digite o ID da area: ");
		scanf("%d", &area);
		if (shmctl(area, IPC_RMID, 0)==-1){
				fprintf(stderr, "ERRO. N�o consegui remover. Tenho permiss�o? Area existe?\n");
				return(1);
		}
		printf("Segmento de memoria ID=%d removido\n", area);
		return(0);
}
