/***************************************************************/
/** **/
/** Ligia Corunha Palma 11352268 **/
/** Exercicio-Programa 02 **/
/** Professor: Yoshiharu Kohayakawa **/
/** Turma: 03 **/
/**   nota : 10,00/10,00 **/
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BISSEC_TOL (1e-6)
#define RANDOM_SEED 1234

/* Funcoes implementadas abaixo, devem ser copiadas no seu codigo */

void ativa_sorteador(); /*sorteia aleatoriamente um numero*/
double sorteia_real();  /*divie o numero sorteado por um numero maior, para dar um numero entre zero e um*/

/* Funcoes que voces devem implementar, seguindo o prototipo abaixo */

int sorteia_voto_com_falha (double f); /*1*/
double bissecta (int N, double a, int T, double tol); /*3*/
double prob_erro (int N, double a, double f, int T); /*2*/

int votos (int N, double a, double f); /* calcula quantos votos foram p a, de acordo com f */

/* "da a partida" no gerador de numeros aleatorios */

void ativa_sorteador()
{
    #ifdef RANDOM_SEED
    srand(RANDOM_SEED);
    #else
    srand(time(NULL));
    #endif
}

/* devolve um real sorteado uniformemente no intervalo [0,1] */

double sorteia_real()
{
    return (double) rand() / RAND_MAX;
}

int main (){
    int N;
    double a;
    int T;
    double tol;
    double f; /*f é a maior probabilidade de falhas*/
    ativa_sorteador( );
    printf ("Digite o numero de votantes ( 0 < N <= 2x10^9 ):");
    scanf ("%d", &N);
    printf ("Digite a porcentagem de votos do candidato A ( 0.5 < a <= 1 ):");
    scanf ("%lf", &a);
    printf ("Digite o numero de simulacoes ( 0 < T < 2x10^9 ):");
    scanf ("%d", &T);
    printf ("Digite a probabilidade toleravel de erros ( 0 <= tol <= 1 ):");
    scanf ("%lf", &tol);
    f = bissecta (N, a, T, tol);
    printf ("Maior falha das urnas toleraveis: %.7f", f);
    return 0;
}

double bissecta( int N, double a, int T, double tol){
    double fa; /*margem inferior do bissecta*/
    double fb; /*margem superior do bissecta*/
    double f;
    double pe; /* probabilidade de erro calculada, de acordo com f */
    fa = 0.00;
    fb = 1.00;
    while ((fb - fa) >= BISSEC_TOL ) {
        f = (fa + fb) / 2;
        pe = prob_erro (N,a,f,T);
        if (pe > tol) {
            fb = f; /* a margem superior se reduz a f */
        }
        if (pe <= tol) {
            fa = f; /* margem inferior aumenta a f*/
        }
    }
    return f;
}

double prob_erro( int N, double a, double f, int T){
    int e; /*eleicoes com erro*/
    double pe;
    int i; /* numero de votos para a*/
    int s; /* recebe o numero de simulacoes */
    e = 0;
    s = T;
    while (T > 0) {
        T--;
        i = votos (N, a, f);
        if ( 2*i <= N){
            e++; /* mais uma eleicoes que deu erro */
        }
    }
    pe = (double) e/s;
    return pe;
}

int votos (int N, double a, double f){
    int vb; /* numero de pessoas que votaram com certeza em b */
    int i = 0; /* numero de votos que irao para a*/
    int va; /*numero de pessoas que votaram com certeza em a*/
    va = a * N ; /* numero de pessoas que votaram em a é a porcentagem de votos para a multiplicado pelo número total de votantes*/
    vb = N - va; /* numero de pessoas que votaram em b e o numero de votantes menos o numero de votantes de a*/
    while (va > 0){
        va --;
        if ( sorteia_voto_com_falha( f ) == 0 ) {
            i++; /*i sera incrementado a cada nao falha de votantes de a*/
            }
    }
    while (vb >  0) {
        vb--;
        if (sorteia_voto_com_falha( f ) == 1) {
            i++; /* i sera incrementado a cada falha de votantes de b*/
        }
    }
    return i;
}

int sorteia_voto_com_falha (double f) {
    if ( sorteia_real() < f){
        return 1; /* devolvera 1 se o voto tiver falha*/
    }
    else {
        return 0; /*devolvera 0 se o voto nao tiver falha*/
    }
}
