#ifndef _AREA_PERIMETRO_H
#define _AREA_PERIMETRO_H

//DEFINICAO DO NOVO TIPO
struct ponto {
    double x;
    double y;
};

//DESCRITORES
typedef struct ponto Ponto;
typedef struct poligono* Poligono;

//FUNCOES
Poligono criarPoligono();
int adicionarPontoPoligono(Ponto ponto, Poligono poligono);
void imprimirPoligono(Poligono poligono);
Ponto primeiroPontoPoligono(Poligono poligono);
Ponto removerPontoPoligono(Poligono poligono);
int destruirPoligono(Poligono poligono);

double calcularPerimetroPoligono(Poligono poligono);
double calcularAreaPoligono(Poligono poligono);

#endif