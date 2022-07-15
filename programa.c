#include "area_perimetro.h"
#include <stdio.h>
#include <stdlib.h>

//PROGRAMA PRINCIPAL
int main() {
    //dados
    Ponto ponto;
    Poligono poligono = NULL;
  
  
  int nome;
    printf("Digite seu nome: ");
    scanf("%s",&nome);

    printf("Seja Bem Vindo %s\n", nome);





    int opcao;
    
    while (1) {
        //leitura
        do {
            printf("---MENU---\n");
           
            printf("Copyright (c) 2022 Igor Gabriel Ribeiro Dantas\n");
            printf("[1] - Criar Poligono.\n");
            printf("[2] - Adicionar um ponto ao poligono.\n");
            printf("[3] - Imprimir Pontos do Poligono.\n");
            printf("[4] - Remover Primeiro Ponto do Poligono.\n");
            printf("[5] - Calcular Perimetro do Poligono.\n");
            printf("[6] - Calcular Area do Poligono.\n");
            printf("[0] - Sair.\n");
            printf("Opcao: ");
            scanf("%d", &opcao);
            //error
            if (opcao < 0 || opcao > 6)
                printf("Error: opcao invalida! Tente Novamente!\n");
        } while (opcao < 0 || opcao > 6);

        //sair
        if (opcao == 0)
            break;

        //processamento
        switch (opcao) {
            //criar poligono
            case 1:
                if (poligono != NULL) {
                    if (!destruirPoligono(poligono))
                        printf("Error: nao foi possivel destruir o poligono anterior!\n");
                }

                poligono = criarPoligono();
                break;
            //adiciona ponto ao poligono
            case 2:
                if (poligono != NULL) {
                    printf("Informe a coordenada x do pontono plano cartesiano: ");
                    scanf("%lf", &ponto.x);

                    printf("Informe a coordenada y do ponto no plano cartesiano: ");
                    scanf("%lf", &ponto.y);

                    adicionarPontoPoligono(ponto, poligono);
                }

                break;
            //imprimir pontos
            case 3:
                if (poligono != NULL) {
                    printf("--POLIGONO--\n");
                    imprimirPoligono(poligono);
                }

                break;
            //remove primeiro ponto do poligono
            case 4:
                if (poligono != NULL) {
                    ponto = removerPontoPoligono(poligono);
                    printf("O ponto [%.2lf, %.2lf] foi removido.\n", ponto.x, ponto.y);
                }

                break;
            case 5:
                if (poligono != NULL)
                    printf("O perimetro do poligono eh: %.2lf\n", calcularPerimetroPoligono(poligono));

                break;
            case 6:
                if (poligono != NULL)
                    printf("A area do poligono eh: %.2lf\n", calcularAreaPoligono(poligono));
                
                break;
        }
    }

    //fim
    if (poligono != NULL)
        destruirPoligono(poligono);

    return 0;
}
