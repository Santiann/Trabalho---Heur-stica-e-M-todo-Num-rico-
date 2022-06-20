// Pergunta 01.

/* O quebra-cabeça 15 (também chamado de Gem Puzzle, Boss Puzzle, Game of Fifteen, Mystic Square e muitos outros) 
 é um quebra-cabeça deslizante com 15 peças quadradas numeradas de 1 a 15 em uma moldura de 4 peças de altura e 4 
de largura, deixando uma desocupada posição do ladrilho. Os ladrilhos na mesma linha ou coluna da posição aberta 
podem ser movidos deslizando-os horizontalmente ou verticalmente, respectivamente. O objetivo do quebra-cabeça 
é colocar as peças em ordem numérica. O programa inicializa uma matriz numérica inteira 4 x 4 e procura colocar 
as peças do quebra-cabeça em ordem crescente.*/

/* Para cada peça no lugar certo, o programa conta 1 ponto, o seu programa deve tentar maximizar a quantidade de 
pontos mas não é obrigado a resolver o quebra cabeça totalmente. Ao término do processamento, mostrar o quabra 
cabeça original, o que o computador ordenou e a quantidade de pontos. */

#include <stdio.h>

#include <stdlib.h>


// declaracao das constantes

#define DIM 4

#define VAZIO -1

#define MAX_ITER 1e10

#define NUM_MOV 4


// declaracao de variaveis globais

int tabuleiro[DIM][DIM] = {{15, 2, 1, 12}, {8, 5, 6, 11}, {4, 9, 10, 7}, {3, 14, 13, VAZIO}};

int gabarito[DIM][DIM] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, VAZIO}};

int opostos[NUM_MOV] = {2, 1, 4, 3};


// prototipo de funcoes / procedimentos

int calcularDistanciaManhattan();

int* localizarVazio();

int moverParaCima();

int moverParaBaixo();

int moverParaEsquerda();

int moverParaDireita();

void mostrarTabuleiro();

int buscarMelhorMovimento(int ultimoMovimento);

int sortearMovimento(int ultimoMovimento);


// implementacao da rotina principal

int main(char** args) {

mostrarTabuleiro();

int i = 1, movimento, ultimoMovimento = 0;

while (i <= MAX_ITER) {

movimento = buscarMelhorMovimento(ultimoMovimento);

if (movimento == 0) {

movimento = sortearMovimento(ultimoMovimento);

}

switch (movimento)

{

case 1:

moverParaCima();

ultimoMovimento = 1;

break;

case 2:

moverParaBaixo();

ultimoMovimento = 2;

break;

case 3:

moverParaEsquerda();

ultimoMovimento = 3;

break;

case 4:

moverParaDireita();

ultimoMovimento = 4;

break;

default:

break;

}

i++;

mostrarTabuleiro();

}

return EXIT_SUCCESS;

}


// implementacao de funcoes / procedimentos

int calcularDistanciaManhattan() {

int d = 0;

for (int i0 = 0; i0 < DIM; i0++) {

for (int j0 = 0; j0 < DIM; j0++) {

for (int i1 = 0; i1 < DIM; i1++) {

for (int j1 = 0; j1 < DIM; j1++) {

if (tabuleiro[i0][j0] == gabarito[i1][j1]) {

d += abs(i1 - i0) + abs(j1 - j0);

}

}

}

}

}

return d / 2;

}


int* localizarVazio() {

static int ij[2];

for (int i = 0; i < DIM; i++) {

for (int j = 0; j < DIM; j++) {

if (tabuleiro[i][j] == VAZIO) {

ij[0] = i;

ij[1] = j;

return ij;

}

}

}

}


int moverParaCima() {

int aux;

int *ij = localizarVazio();

if (ij[0] == 0) {

return 0;

} else {

tabuleiro[ij[0]][ij[1]] = tabuleiro[ij[0] -1][ij[1]];

tabuleiro[ij[0] - 1][ij[1]] = VAZIO;

return 1;

}

}


int moverParaBaixo() {

int aux;

int *ij = localizarVazio();

if (ij[0] == DIM - 1) {

return 0;

} else {

tabuleiro[ij[0]][ij[1]] = tabuleiro[ij[0] + 1][ij[1]];

tabuleiro[ij[0] + 1][ij[1]] = VAZIO;

return 1;

}

}


int moverParaEsquerda() {

int aux;

int *ij = localizarVazio();

if (ij[1] == 0) {

return 0;

} else {

tabuleiro[ij[0]][ij[1]] = tabuleiro[ij[0]][ij[1] - 1];

tabuleiro[ij[0]][ij[1] - 1] = VAZIO;

return 1;

}

}


int moverParaDireita() {

int aux;

int *ij = localizarVazio();

if (ij[1] == DIM - 1) {

return 0;

} else {

tabuleiro[ij[0]][ij[1]] = tabuleiro[ij[0]][ij[1] + 1];

tabuleiro[ij[0]][ij[1] + 1] = VAZIO;

return 1;

}

}


void mostrarTabuleiro() {

for (int i = 0; i < DIM; i++) {

printf("\n");

for (int j = 0; j < DIM; j++) {

printf("\t%d\t", tabuleiro[i][j]);

}

}

printf("\nd = %d", calcularDistanciaManhattan());

}


int buscarMelhorMovimento(int ultimoMovimento) {

int d[] = {-1, 1e5, 1e5, 1e5, 1e5}, movimento = 1;


d[0] = calcularDistanciaManhattan();


if (moverParaCima()) {

d[1] = calcularDistanciaManhattan();

moverParaBaixo();

}


if (moverParaBaixo()) {

d[2] = calcularDistanciaManhattan();

moverParaCima();

}


if (moverParaEsquerda()) {

d[3] = calcularDistanciaManhattan();

moverParaDireita();

}


if (moverParaDireita()) {

d[4] = calcularDistanciaManhattan();

moverParaEsquerda();

}


for (int i = 1; i < NUM_MOV + 1; i++) {

if (d[i] < d[movimento] && ultimoMovimento != opostos[i - 1]) {

movimento = i;

}

}


return d[movimento] < d[0] ? movimento : 0;

}


int sortearMovimento(int ultimoMovimento) {

int movimento;

do {

movimento = 1 + rand() % NUM_MOV;

} while (ultimoMovimento == opostos[movimento]);

return movimento;

}
