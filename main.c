/* 
ALUNO: Vinícius Schmitz Freitas de Oliveira
RA: 109887
FILEIRA 3 - MAQUINA 6
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

int matriz[1000][1000];
int vetorSomatorias[1000];

int m, n, k;

int parcela,
    resto;

typedef struct{
    int id;

} tPack;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void leMatriz()
{   int i, j;
    printf("\nEntre com a quantidade de linhas e colunas respectivamente:\n");
    scanf("%d", &m);
    scanf("%d", &n);

    for(i=0; i<m; i++)
    {
        for(j=0; j<n; j++)
        {
            matriz[i][j] = rand() % 10;
        }
    }
}

void mostraMatriz()
{
    int i, j;

    printf("\nMatriz principal:\n\n");

    printf("%5d", 0);
    for(j=1; j<n; j++)
        printf("%4d", j);
    printf("\n");

    for(i=0; i<m; i++)
    {
        printf("%d", i);
        for(j=0; j<n; j++)
        {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

}

void *funcao_da_thread(void *ptr)
{
    tPack *pack = (tPack *) ptr;

    int processado=0, aux, i, j;

    for(i=(pack->id); i<m-1; i=i+k)
    {
        printf("\n**thread %d estah fazendo a linha %d**", pack->id, i);

        pthread_mutex_lock(&mutex);
        for(j=1; j<n-1; j++)
        {
            matriz[i][j]=matriz[i-1][j]+matriz[i+1][j]+matriz[i][j-1]+matriz[i][j+1] + matriz[i-1][j-1]+matriz[i+1][j+1]+matriz[i-1][j+1]+matriz[i+1][j-1]; 
        }
        pthread_mutex_unlock(&mutex);

        // faz as somatorias
        for(j=0; j<n-1; j++)
        {
            vetorSomatorias[i-1]+=matriz[i][j];
        }

        // zera a linha
        for(j=1; j<n-1; j++)
        {
            matriz[i][j]=0;
        }
    }
}


void main(void)
{   int i;

    srand(time(NULL));

    leMatriz();

    mostraMatriz();

    printf("\nDigite a quantidade de threads:\n");
    scanf("%d", &k);

    pthread_t thread[k];
    int iret;

    tPack pack[k];

    //parcela=m/k;
    //resto=m%k;

    // inicializa o vetor auxiliar que conterah as somatorias de cada linha nas suas posicoes [0...m-2], 
    // pois nao eh incluso as linhas 0 e m-1
    for(i=0; i<m; i++)
    {
        vetorSomatorias[i]=0;
    }

    for(i=0; i<k; i++)
    {
        pack[i].id=i+1;

        iret = pthread_create(&thread[i], NULL, funcao_da_thread, (void*) &pack[i]);
    }


    for(i=0; i<k; i++)
    {
        pthread_join(thread[i], NULL);
    }

    printf("\nProcessamento feito! Agora a matriz novamente e como ela ficou. ");

    int somatoriaTotal=0;

    mostraMatriz();

    printf("\nVetor de somatorias: ");
    for(i=0; i<m-3; i++)
    {
        printf("%d, ", vetorSomatorias[i]);
        somatoriaTotal+=vetorSomatorias[i];
    }
    printf("%d", vetorSomatorias[i]);

    printf("\n\nSomatoria total: %d\n", somatoriaTotal);
}

