#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "grafos_ep21adj.h"
#include "grafos_ep21m.h"

int main()
{
	int m1,m2,m3,v,w,x1 = 0,d1 = 0,d2 = 0,x2 = 0;
	adj_Digraph AG;
	adj_Digraph AD;
	Digraph MG;
	Digraph MD;
	do{
        system("cls");
	    printf("--------------------------------------------------------------\n");
        printf("--------------Menu Principal: Teoria dos grafos---------------\n");
        printf("--------------------------------------------------------------\n\n");
        printf("1 - Nao Orientado (Grafo)\n");
        printf("2 - Orientado (Digrafo)\n");
        printf("3 - Reset\n");
        printf("9 - Sair\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d",&m1);
        switch(m1)
        {
            case 1://grafos
                do{
                    system("cls");
                    printf("-------------------------------\n");
                    printf("------------Grafos-------------\n");
                    printf("-------------------------------\n\n");
                    printf("1 - Matriz de adjacencias\n");
                    printf("2 - Lista de adjacencias\n");
                    printf("9 - Voltar\n\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d",&m2);
                    switch(m2)
                    {
                        case 1://Matriz de adjacencia
                            do{
                                printf("\n");
                                free(lbl);
                                free(dist);
                                free(parent);
                                printf("-------------------------------------\n");
                                printf("----Grafos: Matriz de Adjacencias----\n");
                                printf("-------------------------------------\n\n");
                                printf("1 - Criar grafo\n");
                                printf("2 - Inserir aresta\n");
                                printf("3 - Busca em largura\n");
                                printf("4 - Caminhos minimos\n");
                                printf("9 - Voltar\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d",&m3);
                                switch(m3)
                                {
                                    case 1:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Criar Grafo------------\n");
                                        printf("--------------------------------\n\n");
                                        if(d1 == 0)
                                        {
                                            v = -1;
                                            while(v <= 0 || v > USHRT_MAX)
                                            {
                                                printf("Informe o numero de vertices: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            MG = Matriz_DIGRAPHInit(v);
                                            Matriz_DIGRAPHShow(MG);
                                            printf("\n");
                                            d1 = 1;
                                        }
                                        else
                                            printf("Nao foi possivel criar um novo conjunto de vertices!\n\nSelecione a opcao Reset no menu principal!\n\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("-----------------------------------\n");
                                        printf("---------Inserir Aresta------------\n");
                                        printf("-----------------------------------\n\n");
                                        if(d1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MG);
                                            v = w = -1;
                                            while(v < 0 || v >= MG->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            while(w < 0 || w >= MG->V)
                                            {
                                                printf("\nInforme o vertice final: ");
                                                scanf("%d",&w);
                                            }
                                            printf("\n____________________________\n\n");
                                            Matriz_GRAPHInsertE(MG, v, w);
                                            Matriz_DIGRAPHShow(MG);
                                            printf("\n");
                                        }
                                        else printf("V(G) inexistente!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("----------------------------------------\n");
                                        printf("------------Busca em Largura------------\n");
                                        printf("----------------------------------------\n\n");
                                        if(d1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MG);
                                            v = -1;
                                            while(v < 0 || v >= MG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            Matriz_DIGRAPHbfs(MG, v);
                                        }
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("----------Caminhos Minimos-----------\n");
                                        printf("-------------------------------------\n\n");
                                        if(d1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MG);
                                            v = -1;
                                            while(v < 0 || v >= MG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            Matriz_DIGRAPHdist(MG, v);
                                        }
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("Opcao invalida!\n\n");
                                        system("pause");
                                }
                            }while(m3 != 9);
                            break;
                        case 2://Lista de adjacencias
                            do{
                                printf("\n");
                                free(lbl);
                                free(dist);
                                free(parent);
                                printf("--------------------------------------\n");
                                printf("-----Grafos: Lista de Adjacencias-----\n");
                                printf("--------------------------------------\n\n");
                                printf("1 - Criar grafo\n");
                                printf("2 - Inserir aresta\n");
                                printf("3 - Busca em largura\n");
                                printf("4 - Caminhos minimos\n");
                                printf("9 - Voltar\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d",&m3);
                                switch(m3)
                                {
                                    case 1:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Criar Grafo------------\n");
                                        printf("--------------------------------\n\n");
                                        if(d2 == 0)
                                        {
                                            v = -1;
                                            while(v <= 0 || v > USHRT_MAX)
                                            {
                                                printf("Informe o numero de vertices: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            AG = adj_DIGRAPHInit(v);
                                            adj_DIGRAPHShow(AG);
                                            printf("\n");
                                            d2 = 1;
                                        }
                                        else
                                            printf("Nao foi possivel criar um novo conjunto de vertices!\n\nSelecione a opcao Reset no menu principal!\n\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Inserir Aresta---------\n");
                                        printf("--------------------------------\n\n");
                                        if(d2 == 1)
                                        {
                                            adj_DIGRAPHShow(AG);
                                            v = w = -1;
                                            while(v < 0 || v >= AG->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            while(w < 0 || w >= AG->V)
                                            {
                                                printf("Informe o vertice final: ");
                                                scanf("%d",&w);
                                            }
                                            printf("\n");
                                            adj_GRAPHInsertE(AG, w, v);
                                            adj_DIGRAPHShow(AG);
                                        }
                                        else printf("Grafo inexistente!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("----------Busca em Largura-----------\n");
                                        printf("-------------------------------------\n\n");
                                        if(d2 == 1)
                                        {
                                            adj_DIGRAPHShow(AG);
                                            v = -1;
                                            while(v < 0 || v >= AG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            adj_DIGRAPHbfs(AG, v);
                                        }
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("-----------------------------------\n");
                                        printf("----------Caminhos Minimos---------\n");
                                        printf("-----------------------------------\n\n");
                                        if(d2 == 1)
                                        {
                                            adj_DIGRAPHShow(AG);
                                            v = -1;
                                            while(v < 0 || v >= AG->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_DIGRAPHdist(AG, v);
                                        }
                                        else
                                            printf("Grafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("Opcao invalida!\n");
                                }
                            }while(m3 != 9);
                            break;
                        case 9://voltar
                            break;
                        default:
                            printf("Opcao invalida!\n\n");
                            system("pause");
                    }
                }while(m2 != 9);
                break;
            case 2://Digrafos
                do{
                    system("cls");
                    printf("---------------------------------------\n");
                    printf("----------------Digrafos---------------\n");
                    printf("---------------------------------------\n\n");
                    printf("1 - Matriz de adjacencias\n");
                    printf("2 - Lista de adjacencias\n");
                    printf("9 - Voltar\n\n");
                    printf("Escolha uma das opcoes: ");
                    scanf("%d",&m2);
                    switch(m2)
                    {
                        case 1://Matriz de adjacencia
                            do{
                                printf("\n");
                                free(lbl);
                                free(dist);
                                free(parent);
                                printf("--------------------------------------\n");
                                printf("----Digrafos: Matriz de Adjacencia----\n");
                                printf("--------------------------------------\n\n");
                                printf("1 - Criar digrafo\n");
                                printf("2 - Inserir arco\n");
                                printf("3 - Busca em largura\n");
                                printf("4 - Caminhos minimos\n");
                                printf("9 - Voltar\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d",&m3);
                                switch(m3)
                                {
                                    case 1:
                                        system("cls");
                                        printf("----------------------------------\n");
                                        printf("---------Criar Digrafo------------\n");
                                        printf("----------------------------------\n\n");
                                        if(x1 == 0)
                                        {
                                            v = -1;
                                            while(v <= 0 || v > USHRT_MAX)
                                            {
                                                printf("Informe o numero de vertices: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            MD = Matriz_DIGRAPHInit(v);
                                            Matriz_DIGRAPHShow(MD);
                                            printf("\n");
                                            x1 = 1;
                                        }
                                        else
                                            printf("V(G) jah definido!\n\nSelecione a opcao Reset no menu principal!\n\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("----------------------------------\n");
                                        printf("---------Inserir Arco-------------\n");
                                        printf("----------------------------------\n\n");
                                        if(x1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MD);
                                            v = w = -1;
                                            while(v < 0 || v >= MD->V)
                                            {
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            while(w < 0 || w >= MD->V)
                                            {
                                                printf("\nInforme o vertice final: ");
                                                scanf("%d",&w);
                                            }
                                            Matriz_DIGRAPHInsertA(MD, v, w);
                                            printf("\n");
                                            Matriz_DIGRAPHShow(MD);
                                            printf("\n");
                                        }
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("----------Busca em Largura-----------\n");
                                        printf("-------------------------------------\n\n");
                                        if(x1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MD);
                                            v = -1;
                                            while(v < 0 || v >= MD->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            Matriz_DIGRAPHbfs(MD, v);
                                        }
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Caminhos Minimos-------\n");
                                        printf("--------------------------------\n\n");
                                        if(x1 == 1)
                                        {
                                            Matriz_DIGRAPHShow(MD);
                                            v = -1;
                                            while(v < 0 || v >= MD->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            Matriz_DIGRAPHdist(MD, v);
                                        }
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("Opcao invalida!\n\n");
                                        system("pause");
                                }
                            }while(m3 != 9);
                            break;
                        case 2://Lista de adjacencias
                            do{
                                printf("\n");
                                free(lbl);
                                free(dist);
                                free(parent);
                                printf("--------------------------------------\n");
                                printf("----Digrafos: Lista de Adjacencias----\n");
                                printf("--------------------------------------\n\n");
                                printf("1 - Criar digrafo\n");
                                printf("2 - Inserir arco\n");
                                printf("3 - Busca em largura\n");
                                printf("4 - Caminhos minimos\n");
                                printf("9 - Voltar\n\n");
                                printf("Escolha uma opcao: ");
                                scanf("%d",&m3);
                                switch(m3)
                                {
                                    case 1:
                                        system("cls");
                                        printf("----------------------------------\n");
                                        printf("---------Criar Digrafo------------\n");
                                        printf("----------------------------------\n\n");
                                        if(x2 == 0)
                                        {
                                            v = -1;
                                            while(v <= 0 || v > USHRT_MAX)
                                            {
                                                printf("\nInforme o numero de vertices: ");
                                                scanf("%d",&v);
                                            }
                                            printf("\n");
                                            AD = adj_DIGRAPHInit(v);
                                            adj_DIGRAPHShow(AD);
                                            printf("\n");
                                            x2 = 1;
                                        }
                                        else
                                            printf("Nao foi possivel criar um novo conjunto de vertices!\n\nSelecione a opcao Reset no menu principal!\n\n");
                                        break;
                                    case 2:
                                        system("cls");
                                        printf("--------------------------------\n");
                                        printf("---------Inserir Arco-----------\n");
                                        printf("--------------------------------\n\n");
                                        if(x2 == 1)
                                        {
                                            adj_DIGRAPHShow(AD);
                                            printf("\n");
                                            v = w = -1;
                                            while(v < 0 || v >= AD->V)
                                            {
                                                printf("Informe o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            while(w < 0 || w >= AD->V)
                                            {
                                                printf("\nInforme o vertice final: ");
                                                scanf("%d",&w);
                                            }
                                            printf("\n");
                                            adj_DIGRAPHInsertA(AD, v, w);
                                            adj_DIGRAPHShow(AD);
                                            printf("\n");
                                        }
                                        else printf("Digrafo inexistente!\n");
                                        break;
                                    case 3:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("---------Busca em Largura------------\n");
                                        printf("-------------------------------------\n\n");
                                        if(x2 == 1)
                                        {
                                            adj_DIGRAPHShow(AD);
                                            printf("\n");
                                            v = -1;
                                            while(v < 0 || v >= AD->V)
                                            {
                                                printf("Informe o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_DIGRAPHbfs(AD,v);
                                        }
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 4:
                                        system("cls");
                                        printf("-------------------------------------\n");
                                        printf("---------Caminhos Minimos------------\n");
                                        printf("-------------------------------------\n\n");
                                        v = -1;
                                        if(x2 == 1)
                                        {
                                            adj_DIGRAPHShow(AD);
                                            while(v < 0 || v >= AD->V){
                                                printf("\nInforme o vertice de origem: ");
                                                scanf("%d",&v);
                                            }
                                            adj_DIGRAPHdist(AD, v);
                                        }
                                        else
                                            printf("Digrafo inexistente!\n");
                                        break;
                                    case 9:
                                        break;
                                    default:
                                        printf("Opcao invalida!\n\n");
                                        system("pause");
                                }
                            }while(m3 != 9);
                            break;
                        case 9://voltar
                            break;
                        default:
                            printf("Opcao invalida!\n\n");
                            system("pause");
                    }
                }while(m2 != 9);
                break;
            case 3:
                system("cls");
                printf("----------------------\n");
                printf("---------Reset--------\n");
                printf("----------------------\n\n");
                printf("1 - Deletar Grafo\n");
                printf("2 - Deletar Digrafo\n");
                printf("9 - Voltar\n\n");
                printf("Escolha uma opcao: ");
                scanf("%d",&m2);
                switch(m2)
                {
                    case 1:
                        do{
                            system("cls");
                            printf("-----------------------\n");
                            printf("------Deletar Grafo----\n");
                            printf("-----------------------\n\n");
                            printf("1 - Deletar Matriz\n");
                            printf("2 - Deletar Lista\n");
                            printf("9 - Voltar\n\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d",&m3);
                            switch(m3)
                            {
                                case 1:
                                    MG = Matriz_DIGRAPHdel();
                                    d1 = 0;
                                    printf("Matriz deletada!\n\n");
                                    system("pause");
                                    break;
                                case 2:
                                    AG = adj_DIGRAPHdel();
                                    d2 = 0;
                                    printf("Lista deletada!\n\n");
                                    system("pause");
                                    break;
                                case 9:
                                    break;
                                default:
                                    printf("Opcao invalida!\n\n");
                                    system("pause");
                            }
                        }while(m3 != 9);
                        break;
                    case 2:
                        do{
                            system("cls");
                            printf("-------------------------\n");
                            printf("------Deletar Digrafo----\n");
                            printf("-------------------------\n\n");
                            printf("1 - Deletar Matriz\n");
                            printf("2 - Deletar Lista\n");
                            printf("9 - Voltar\n\n");
                            printf("Escolha uma opcao: ");
                            scanf("%d",&m3);
                            switch(m3)
                            {
                                case 1:
                                    MD = Matriz_DIGRAPHdel();
                                    x1 = 0;
                                    printf("\nMatriz deletada!\n\n");
                                    system("pause");
                                    break;
                                case 2:
                                    AD = adj_DIGRAPHdel();
                                    x2 = 0;
                                    printf("\nLista deletada!\n\n");
                                    system("pause");
                                    break;
                                case 9:
                                    break;
                                default:
                                    printf("Opcao invalida!\n\n");
                                    system("pause");
                            }
                        }while(m3 != 9);
                        break;
                    default:
                        printf("Opcao invalida!\n\n");
                        system("pause");
                }
                break;
            case 9://voltar para menu 1
                break;
            default:
                printf("Opcao invalida!\n\n");
                system("pause");
        }
    }while(m1 != 9);
    return 0;
}
