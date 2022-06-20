/*Faça um programa que busque o ponto (x, y) mínimo ou máximo de uma função quadrática. Lembre-se:

y igual a f parêntese esquerdo x parêntese direito igual a a x ao quadrado mais b x mais c

Gráfico da Função do 2º Grau - PrePara ENEM

O programa deve ler os coeficientes a, b e c digitados pelo usuário. Ao término do processamento, 
mostrar o valor aproximado do ponto (x, y) e informar se é um ponto de máximo ou mínimo.

Dica: faça uma varredura dos valores de x para a direita ou para esquerda.*/


#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

// Declaracao de constantes

#define GRAU_FNC 2

#define DELTA_X 1e-5

#define ERRO 1e-10

// Declaracao dos prototipos das funcoes e procedimentos

void ler_coeficientes(double *coef);

void mostrar_funcao(double *coef);

double calcular_valor_funcao(double *coef, double x);

double calcular_valor_derivada_primeira(double *coef, double x);

double procurar_ponto_minimo(double *coef);

double procurar_ponto_maximo(double *coef);

// Implementacao da funcao principal

int main(void) {

double coef[GRAU_FNC + 1], x;

char str[30];

ler_coeficientes(&coef[0]);

mostrar_funcao(coef);

if (coef[0] > 0) {

strcpy(str, "Ponto de Minimo");

x = procurar_ponto_minimo(coef);

} else if (coef[0] < 0) {

strcpy(str, "Ponto de Maximo");

x = procurar_ponto_maximo(coef);

} else {

printf("Não é função quandrática!");

return 0;

}

printf("\n=======================");

printf("\nRESULTADO FINAL");

printf("\n=======================");

mostrar_funcao(coef);

printf("\nTipo: %s", str);

printf("\ny = f(%lf) = %lf", x, calcular_valor_funcao(coef, x));

return 0;

}

// Implementacao das funcoes e procedimentos

void ler_coeficientes(double *coef) {

printf("\ny = f(x) = ");

for (int i = 0; i <= GRAU_FNC; i++) {

printf("a%d * x^%d", i + 1, GRAU_FNC - i);

if (i < GRAU_FNC) {

printf ("+");

}

}

printf("\nDigite os coeficientes:");

for (int i = 0; i <= GRAU_FNC; i++) {

printf("a%d = ", i + 1);

scanf("%lf", (coef + i)); // (coef + 1) = &coef[i]

}

}

void mostrar_funcao(double *coef) {

printf("\ny = f(x) = ");

for (int i = 0; i <= GRAU_FNC; i++) {

printf("%lf * x^%d", *(coef + i), GRAU_FNC - i);

if (i < GRAU_FNC) {

printf(" + ");

}

}

}

double calcular_valor_funcao(double *coef, double x) {

double y = 0;

for (int i = 0; i <= GRAU_FNC; i++) {

y += *(coef + i) * pow(x, GRAU_FNC - i);

}

return y;

}

double calcular_valor_derivada_primeira(double *coef, double x) {

double dydx = 0;

for (int i = 0; i < GRAU_FNC; i++) {

dydx += (GRAU_FNC - i) * *(coef + i) * pow(x, GRAU_FNC - i -1);

// *(coef + i) -> coef[i]

}

return dydx;

}

double procurar_ponto_minimo(double *coef) {

double x, dydx;

x = 0;

dydx = calcular_valor_derivada_primeira(coef, x);

while (fabs (dydx) > ERRO) { // Comparar com zero

if (dydx > 0) {

x -= DELTA_X; // x = x - DELTA_X

} else {

x += DELTA_X;

}

dydx = calcular_valor_derivada_primeira(coef, x);

printf("\ny' %lf", dydx);

}

return x;

}

double procurar_ponto_maximo(double *coef) {

double x, dydx;

x = 0;

dydx = calcular_valor_derivada_primeira(coef, x);

while (fabs (dydx) > ERRO) { // Comparar com zero

if (dydx > 0) {

x += DELTA_X; // x = x - DELTA_X

} else {

x -= DELTA_X;

}

dydx = calcular_valor_derivada_primeira(coef, x);

printf("\ny' %lf", dydx);

}

return x;

}#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <string.h>

// Declaracao de constantes

#define GRAU_FNC 2

#define DELTA_X 1e-5

#define ERRO 1e-10

// Declaracao dos prototipos das funcoes e procedimentos

void ler_coeficientes(double *coef);

void mostrar_funcao(double *coef);

double calcular_valor_funcao(double *coef, double x);

double calcular_valor_derivada_primeira(double *coef, double x);

double procurar_ponto_minimo(double *coef);

double procurar_ponto_maximo(double *coef);

// Implementacao da funcao principal

int main(void) {

double coef[GRAU_FNC + 1], x;

char str[30];

ler_coeficientes(&coef[0]);

mostrar_funcao(coef);

if (coef[0] > 0) {

strcpy(str, "Ponto de Minimo");

x = procurar_ponto_minimo(coef);

} else if (coef[0] < 0) {

strcpy(str, "Ponto de Maximo");

x = procurar_ponto_maximo(coef);

} else {

printf("Não é função quandrática!");

return 0;

}

printf("\n=======================");

printf("\nRESULTADO FINAL");

printf("\n=======================");

mostrar_funcao(coef);

printf("\nTipo: %s", str);

printf("\ny = f(%lf) = %lf", x, calcular_valor_funcao(coef, x));

return 0;

}

// Implementacao das funcoes e procedimentos

void ler_coeficientes(double *coef) {

printf("\ny = f(x) = ");

for (int i = 0; i <= GRAU_FNC; i++) {

printf("a%d * x^%d", i + 1, GRAU_FNC - i);

if (i < GRAU_FNC) {

printf ("+");

}

}

printf("\nDigite os coeficientes:");

for (int i = 0; i <= GRAU_FNC; i++) {

printf("a%d = ", i + 1);

scanf("%lf", (coef + i)); // (coef + 1) = &coef[i]

}

}

void mostrar_funcao(double *coef) {

printf("\ny = f(x) = ");

for (int i = 0; i <= GRAU_FNC; i++) {

printf("%lf * x^%d", *(coef + i), GRAU_FNC - i);

if (i < GRAU_FNC) {

printf(" + ");

}

}

}

double calcular_valor_funcao(double *coef, double x) {

double y = 0;

for (int i = 0; i <= GRAU_FNC; i++) {

y += *(coef + i) * pow(x, GRAU_FNC - i);

}

return y;

}

double calcular_valor_derivada_primeira(double *coef, double x) {

double dydx = 0;

for (int i = 0; i < GRAU_FNC; i++) {

dydx += (GRAU_FNC - i) * *(coef + i) * pow(x, GRAU_FNC - i -1);

// *(coef + i) -> coef[i]

}

return dydx;

}

double procurar_ponto_minimo(double *coef) {

double x, dydx;

x = 0;

dydx = calcular_valor_derivada_primeira(coef, x);

while (fabs (dydx) > ERRO) { // Comparar com zero

if (dydx > 0) {

x -= DELTA_X; // x = x - DELTA_X

} else {

x += DELTA_X;

}

dydx = calcular_valor_derivada_primeira(coef, x);

printf("\ny' %lf", dydx);

}

return x;

}

double procurar_ponto_maximo(double *coef) {

double x, dydx;

x = 0;

dydx = calcular_valor_derivada_primeira(coef, x);

while (fabs (dydx) > ERRO) { // Comparar com zero

if (dydx > 0) {

x += DELTA_X; // x = x - DELTA_X

} else {

x -= DELTA_X;

}

dydx = calcular_valor_derivada_primeira(coef, x);

printf("\ny' %lf", dydx);

}

return x;

}#include <stdio.h>

#include <stdlib.h>

#include <math.h>

// Declaracao de constantes

#define GRAU_FNC 2

// Declaracao dos prototipos das funcoes e procedimentos

void ler_coeficientes(double *coef);

void mostrar_funcao(double *coef);

double calcular_valor_funcao(double *coef, double x);

double calcular_valor_derivada_primeira(double *coef, double x);

// Implementacao da funcao principal

int main(void) {

  double coef[GRAU_FNC + 1];

  ler_coeficientes(&coef[0]);

  mostrar_funcao(coef);

  printf("\n%lf", calcular_valor_funcao(coef, -5));

}

// Implementacao das funcoes e procedimentos

void ler_coeficientes(double *coef) {

  printf("\ny = f(x) = ");

  for (int i = 0; i <= GRAU_FNC; i++) {

    printf("a%d * x^%d", i + 1, GRAU_FNC - i);

    if (i < GRAU_FNC) {

      printf ("+");

    }

  }

  printf("\nDigite os coeficientes:");

    for (int i = 0; i <= GRAU_FNC; i++) {

      printf("a%d = ", i + 1);

      scanf("%lf", (coef + i)); // (coef + 1) = &coef[i]

    }


}

void mostrar_funcao(double *coef) {

  printf("\ny = f(x) = ");

  for (int i = 0; i <= GRAU_FNC; i++) {

    printf("%lf * x^%d", *(coef + i), GRAU_FNC - i);

    if (i < GRAU_FNC) {

      printf(" + ");



    }

  }



}



double calcular_valor_funcao(double *coef, double x) {

  double y = 0;

  for (int i = 0; i <= GRAU_FNC; i++) {

    y += *(coef + i) * pow(x, GRAU_FNC - i);



  }

  return y;



}





double calcular_valor_derivada_primeira(double *coef, double x) {



  return 0;

}
