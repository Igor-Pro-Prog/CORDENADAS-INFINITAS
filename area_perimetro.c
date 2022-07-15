#include "area_perimetro.h"

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//IMPLEMENTACAO DOS DESCRITORES E DEMAIS STRUCTS NECESSARIAS
typedef struct no {
    Ponto ponto;
    struct no* proximo;
} No;

struct poligono {
    int qtd_pontos;
    No* inicio;
    No* fim;
};

//IMPLEMENTCAO DAS FUNCOES
Poligono criarPoligono() {
    Poligono poligono = (Poligono) malloc(sizeof(struct poligono));

    if (poligono != NULL) {
        poligono->qtd_pontos = 0;
        poligono->inicio = NULL;
    }

    return poligono;
}

int adicionarPontoPoligono(Ponto ponto, Poligono poligono) {
    if (poligono != NULL) {
        No* novo = (No*) malloc(sizeof(No));

        if (novo != NULL) {
            novo->ponto = ponto;
            novo->proximo = NULL;

            if (poligono->qtd_pontos == 0)
                poligono->inicio = novo;                
            else
                poligono->fim->proximo = novo;

            poligono->fim = novo;

            poligono->qtd_pontos++;

            return 1;
        }
    }

    return 0;
}

void imprimirPoligono(Poligono poligono) {
    No* atual;

    for (atual = poligono->inicio; atual != NULL; atual = atual->proximo)
        printf("|%.2f, %.2f|\n", atual->ponto.x, atual->ponto.y);
}

Ponto primeiroPontoPoligono(Poligono poligono) {
    return poligono->inicio->ponto;
}

Ponto removerPontoPoligono(Poligono poligono) {
    No* tmp = poligono->inicio;
    Ponto ponto = poligono->inicio->ponto;

    poligono->inicio = poligono->inicio->proximo;
    poligono->qtd_pontos--;

    if (poligono->qtd_pontos == 0)
        poligono->fim = NULL;

    free(tmp);

    return ponto;
}

int destruirPoligono(Poligono poligono) {
    if (poligono != NULL) {
        while (poligono->qtd_pontos > 0)
            removerPontoPoligono(poligono);
        free(poligono);

        return 1;
    }

    return 0;
}

double distanciaEntrePontos(Ponto p1, Ponto p2) {
    double a = p2.x - p1.x;
    double b = p2.y - p1.y;

    return sqrt((a * a) + (b * b));
}

double calcularPerimetroPoligono(Poligono poligono) {
    Ponto ponto1,
          ponto2;
    int i;
    double perimetro = 0.00;

    if (poligono != NULL) {
        if (poligono->qtd_pontos > 2) {
            for (i = 0; i < poligono->qtd_pontos; i++) {
                ponto1 = removerPontoPoligono(poligono);
                ponto2 = primeiroPontoPoligono(poligono);

                perimetro += distanciaEntrePontos(ponto1, ponto2);

                adicionarPontoPoligono(ponto1, poligono);
            }
        }
    }

    return perimetro;
}

double modulo(double valor) {
    return (valor > 0) ? valor : -valor;
}

double calcularAreaPoligono(Poligono poligono) {
    Ponto ponto1,
          ponto2;
    
    int i;

    double soma1 = 0.00,
           soma2 = 0.00,
           area = 0.00;

    if (poligono != NULL) {
        for (i = 0; i < poligono->qtd_pontos; i++) {
            ponto1 = removerPontoPoligono(poligono);
            ponto2 = primeiroPontoPoligono(poligono);

            soma1 += (ponto1.x * ponto2.y);

            adicionarPontoPoligono(ponto1, poligono);
        }

        for (i = 0; i < poligono->qtd_pontos; i++) {
            ponto1 = removerPontoPoligono(poligono);
            ponto2 = primeiroPontoPoligono(poligono);

            soma2 += (ponto1.y * ponto2.x);

            adicionarPontoPoligono(ponto1, poligono);
        }

        area = modulo(soma1 - soma2)/2;
    }

    return area;
}