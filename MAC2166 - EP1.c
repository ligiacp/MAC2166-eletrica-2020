/***************************************************************/
/**                                                           **/
/**   Ligia Corunha Palma          11352268                   **/
/**   Exercício-Programa 1                                    **/
/**   Professor: Yoshiharu Kohayakawa                         **/
/**   Turma: 03                                               **/
/**   Nota : 8,00/9,00                                        **/
/***************************************************************/


// comentário do monitor : - Seu programa lê apenas 1 (um) número inteiro e 
// retorna se ele pode ou não ser expresso como a soma quadrática 
// de quatro primos consecutivos. O esperado era que o programa 
// conseguisse ler uma sequência de números inteiros (onde o que 
// determinaria o fim da sequencia seria digitar 0) e, para cada 
// um desses números digitados (exceto o 0), analisar se o 
// respectivo numero pode ser expresso ou não como a soma quadrática 
// de quatro primos consecutivos.


#include <stdio.h>

int main ()
{
    int N = 6;  /* quando somado com um, resulta sete, que é o quarto numrto natural primo*/
    int N1 = 0; /* é inicializado como 0, pois tanto faz seu valor inicial, visto que logo recebe o valor de N2*/
    int N2 = 2; /* é o primeiro natural primo*/
    int N3 = 3; /* é o segundo natural primo*/
    int N4 = 5; /* é o terceiro numero primo*/
    int i;
    int n;
    int X;
    printf ("Escreva X:");
    scanf ("%d" , &X);
    while ((N1 * N1) +(N2 * N2) + (N3 * N3) + (N4 * N4) < X){ /* nessa funçao, sao gerados números primos enquanto
                                                                 a equaçao for verdadeira*/
            N++; /*a cada ciclo, é incrementado uma unidade, e testado se é primo*/
            i = 0; /* é o numero de divisores de N*/
            n = 1;  /* é o divisor de N*/
            while (n <= N){
                if (N % n == 0){ /* se o resto da funçao é zeron n é divisor de N, e i aumenta uma unidade*/
                    i++;
                }
                n++; /* o proximo numero (n+1) sera testado como divisor no proximo ciclo*/
            }
            if ( i == 2 ){ /* se i=2, N é primo, visto que é divisivel por 1 e por ele mesmo*/
                 N1 = N2;
                 N2 = N3;
                 N3 = N4;
                 N4 = N;  /* dessa forma, N é relacionado com os tres numeros primos anteriores e, assim, a equação
                             pode ser testada posteriormente*/

            }

    }
    if (X == (N1 * N1) + (N2 * N2) + (N3 * N3) + (N4 * N4)){
            printf ("\n %d = (%d^2) + (%d^2) + (%d^2) + (%d^2)", X, N1, N2, N3, N4);
    }
    if (X < (N1 * N1) + (N2 * N2) + (N3 * N3) + (N4 * N4)){
            printf ("\n X nao pode ser escrito como a soma dos quadrados de quatro numeros primos consecutivos");
    }
    return 0;
}