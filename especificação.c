/*

Universidade Estadual de Maringa
Departamento de Informatica

==================================================
Nome do Aluno:
RA:
Curso:
==================================================

Programacao Concorrente – Ano Letivo 2024

Prof. Ronaldo - Prova - Questao 02

14/08/2024 – das 13:30 as 15:20

Orientacoes Preliminares:

- Responda a questao diretamente neste arquivo. Ele ja contem o modelo basico de
  implementacao. Salve-o localmente.

- Preencha seu nome, RA e curso antes de iniciar a prova.

- Salve-o frequentemente para evitar perdas. Se voce perder o arquivo, nao sera
  dada outra oportunidade.

- Nao sera permitido acesso a internet. Desconecte o cabo na internet antes de
  iniciar a prova e reconecte novamente apenas quando for entregar, mas peca
  autorizacao antes.

- Nao sera permitido consulta a nenhum tipo de codigo, apenas ao documentos PDFs
  que o professor disponibilizar

- Quando terminar, informe o professor, reconecte a internet e envie-o arquivo
  .c na plataforma Moodle. Nao converta o arquivo em PDF ou em outro formato que
  nao seja este proprio.

- A implementacao deve ser feita em linguagem C, formatada e alinhada adequadamente.
  Desloque os comandos mais internos mais para a direita e alinhe as chaves
  correspondentes ao comando que pertencem, como o modelo a seguir:

		for (...)
		{
		    if (...)
		    {
			printf(...);
			gets(...);
			while (...)
			{
			    strcmp(...);
			    a[i]=a[i+1];
			}
		    }
		    scanf(...);
		    x=soma(...);
		}

- use nomes de variaveis adequadas a sua finalidade, por exemplo, "soma", "nome",
  "idade" etc. e nao use nomes que nada significam, tipo "w_p3", "xyz", "pa_daqui"
  etc.

- nao declare e nem use variaveis auxiliares/secundarias desnecessarias, que nao
  causam efeito relevante no programa.

ALERTA: Nao obtenha respostas de terceiros, senao sua prova sera anulada.

ATENCAO: Para avaliar sua resposta, a implementacao sera compilada e executada pelo
professor. Voce pode usar o codeblocks para implementar. Sua implementacao devera
funcionar.

Boa Prova!

================================================

Questao 02 (2,5 pontos):

Implemente uma aplicacao paralela/concorrente multi-threaded, usando linguagem C
com pthreads. Nao use recursos de orientacao a objetos, apenas linguagem C padrao
com as bibliotecas constante no modelo basico. Nao use outras bibliotecas. Nao use
comandos de threads que nao foram trabalhados em sala. Implemente uma aplicacao
completa, com todas as funcoes que forem necessarias, para que ela funcione de
forma segura, sem erros, ainda que raros. Desenvolva por si soh toda a codificacao
que for necessaria. Se estas instruções nao forem seguidas, sua resposta sera
anulada/zerada.

A aplicacao deve processar uma matriz A de tamanho mxn (m linhas x n Colunas. Obtenha
n e n do usuario. Gere aleatoriamente os elementos inteiros da matriz. Mostre na
tela a matriz que foi gerada. A leitura de m e n, a geração da matriz e a mostragem
na tela deve ser feita pela thread 0 (main). O processamento que deve ser feito eh
explicado a seguir.

A matriz deve ser percorrida linha por linha, elemento apos elemento, e cada elemento
deve ser modificado de acordo com os valores dos elementos vizinhos. O elemento
da posicao (i,j) deve ser substituido pela somatoria dos 8 elementos vizinhos, ou
seja, o anterior, o posterior, o acima, o abaixo e os elementos das 4 diagonais.

O proximo elemento somente poderah ser modificado depois que o anterior foi
modificado, seguindo a ordem do percurso. Algo similar ao que foi feito no primeiro
trabalho.

Esse processamento deverah ser feito por k threads, sendo k informado pelo usuario.

Cada processo ira se responsabilizar por um conjunto de linhas equidistantes. Pode
supor que o numero de linhas da matriz seja multiplo de k. Portanto, cada thread
ira processar m/k linhas.

Na medida que uma thread vai processando uma linha, os elementos ja processados
ficam disponiveis para a proxima thread, mas uma sincronizacao deve ser feita
para impedir que elementos que nao estejam prontos sejam acessados.

Alem disso, ao final do processamento de sua linha, a thread que a processou deve
somar os seus elementos e apagar a linha processada (zerar os elementos). Mas ela
somente poderah fazer isso quando a thread seguinte jah terminou seu processamento,
ou seja, jah usou toda a linha anterior.

No final da aplicacao, a thread 0 deverah informar a somatoria total de todos os
elementos processados e imprimir a matriz final (que deverah estar zerada).

Restricoes Obrigatorias:
1) A primeira e ultima linha, bem como a primeira e ultima coluna, nao
devem ser processadas, mantendo os elementos originais.
2) A solução devera utlizar no maximo um semaforo e/ou um mutex por linha.

Penalidade: o nao cumprimento das restricoes obrigatorias implica em resposta
errada.


Boa prova!

DICAS DE COMANDOS E MODELO BASICO


THREADS:

    pthread_t thread;

    iret = pthread_create(&thread, NULL, funcao_da_thread, (void*) &pack);

    pthread_join(thread, NULL);


TEMPO:

    time_t tempoSeg;

    struct tm *tempoLocal;

    time(&tempoSeg);

    tempoLocal=localtime(&tempoSeg);

    asctime(tempoLocal);


ALEATORIO:

    srand(time(NULL));

    rand()

MUTEX

Na declaracao:

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

Na execucao:

pthread_mutex_init(&mutex, NULL);
pthread_mutex_lock(&mutex);
pthread_mutex_unlock(&mutex);
if/while (pthread_mutex_trylock(&mutex)==0)

SEMAFOROS


Na declaracao:

sem_t sema;
const struct timespec timeout;

Na execucao:

sem_init(&sema, 0, valorInicial);

sem_wait(&sema);
sem_post(&sema);
if/while (sem_trywait(&sema)==0)
sem_timedwait(&sema, &timeout);


/* IMPLEMENTE A PARTIR DAQUI */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void main(void)
{

}

void *funcao_da_thread(void *ptr)
{

}
