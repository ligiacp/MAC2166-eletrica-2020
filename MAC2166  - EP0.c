/***************************************************************/
/**                                                           **/
/**   Ligia Corunha Palma          11352268                   **/
/**   Exercício-Programa 0                                    **/
/**   Professor: Yoshiharu Kohayakawa                         **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/




/*Simulação:
N=     0  1  2  3  4  5  6  7  8
f=    0  0  0  1  1  2  4  8  15
Se f=f1+f2+f3+f4 */



#include<stdio.h>
int main()
{
    /* inicialmente, f1, f2, f3 e f4 sao valores de f para N igual a 0,1,2,3.*/
    int f1 = 0;
    int f2 = 0;
    int f3 = 0;
    int f4 = 1;
    int f = 0;
    int N;
    printf (" Escreva N: ");
    scanf ("%d", &N);
    if (N < 3){
            printf ("f vale 0"); /*valor fixo*/
    }
    if (N == 3){
            printf ("f vale 1"); /*valor fixo*/
    }
    if (N>3){
            N = N-3;
        /*a equaçao só precisa ser feita a partir do momento que N é igual
    a quatro, pois antes disso os valores não seguem a equação proposta */
            while (N > 0){
                f = f1 + f2 + f3 + f4;
                f1 = f2;
                f2 = f3;
                f3 = f4;
                f4 = f;
                N--;
            /*cada vez que completa essa sequencia de comandos é necessario
    fazê-la menos uma vez, por isso reduzimos 1 de N*/
            }
            printf ("f vale %d", f);
    }
    return 0;
}


















