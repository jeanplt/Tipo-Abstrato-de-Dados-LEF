#include <stdio.h>
#include <stdlib.h>
#include "lef.h"

/* Implementacao das funcoes do TAD Lista de Eventos Futuros (LEF) 
 * Autor: 
 *    Jean Pablo Lopes Teixeira 
 *
 * Versao 1.0.0 05/10/2023
 */

struct evento_t *cria_evento (int tempo, int tipo, int dado1, int dado2)
{
    struct evento_t *novoEvento = malloc(sizeof(struct evento_t));

    /* Testa se o malloc deu certo */ 
    if (novoEvento == NULL)
        return NULL;
    
    /* Inicializa as variaveis do evento para poder retorna-lo */
    novoEvento->tempo = tempo;
    novoEvento->tipo = tipo;
    novoEvento->dado1 = dado1;
    novoEvento->dado2 = dado2;
     
    return novoEvento;
}

struct evento_t *destroi_evento (struct evento_t *e)
{
    /* Verifica se o evento existe */
    if (e == NULL)
        return NULL;
    
    /* Libera o evento e aterra o ponteiro dele */
    free(e);
    e = NULL;

    return e;
}

struct lef_t *cria_lef ()
{
    struct lef_t *novaLef = malloc(sizeof(struct lef_t));

    /* Testa se o malloc deu certo */
    if (novaLef == NULL)
        return NULL;
    
    /* Inicializa o primeiro para entao retornar */
    novaLef->primeiro = NULL;

    return novaLef;
}

struct lef_t *destroi_lef (struct lef_t *l)
{
    /* Verifica se o Lef existe */
    if (l == NULL)
        return NULL;
    
    /* Struct para os nodos da Lef */
    struct nodo_lef_t *atual = l->primeiro;

    /* Laco para desalocar gradativamente os eventos da Lef pelo nodo */
    while (atual != NULL)
    {
        struct nodo_lef_t *proximo = atual->prox;
        destroi_evento (atual->evento);
        free(atual);
        atual = proximo;
    }

    /* Libera a Lef e aterra o ponteiro */
    free (l);
    l = NULL;

    return NULL;
}

int insere_lef (struct lef_t *l, struct evento_t *e)
{
    /* Struct para o novo nodo da Lef */
    struct nodo_lef_t *novoNodo = malloc(sizeof(struct nodo_lef_t));

    /* Testa se o malloc deu certo */
    if (novoNodo == NULL) 
        return 0; 
    
    /* Passa os parametros do evento para o novo nodo */
    novoNodo->evento = e;
    novoNodo->prox = NULL;

    /* Verifica o tempo do evento inserido para organiza-lo na Lef */
    if (l->primeiro == NULL || e->tempo < l->primeiro->evento->tempo) 
    {
        novoNodo->prox = l->primeiro;
        l->primeiro = novoNodo;
    } 
    else 
    {
        /* Struct auxiliar para organizar os eventos */
        struct nodo_lef_t *atual = l->primeiro;

        /* Laco para reposionar os eventos em sequencia */
        while (atual->prox != NULL && atual->prox->evento->tempo <= e->tempo) 
            atual = atual->prox;
        
        /* Reajuste do proximo evento do novo nodo */
        novoNodo->prox = atual->prox;
        atual->prox = novoNodo;
    }

    return 1; 
}

struct evento_t *retira_lef (struct lef_t *l)
{
    /* Verifica se a Lef esta vazia */
    if (l->primeiro == NULL) 
        return NULL; 

    /* Structs auxiliares para remover o evento da Lef */
    struct nodo_lef_t *nodoRemovido = l->primeiro;
    struct evento_t *eventoRemovido = nodoRemovido->evento;

    /* Evento eh removido e o proximo evento no nodo assume essa posicao */
    l->primeiro = nodoRemovido->prox;
    free(nodoRemovido);
    nodoRemovido = NULL;

    return eventoRemovido;
}

int vazia_lef (struct lef_t *l)
{
    return (l->primeiro == NULL) ? 1 : 0;
}

void imprime_lef (struct lef_t *l)
{
    /* Stuct auxiliar para impressao e inteiro para contar os eventos */
    struct nodo_lef_t *atual = l->primeiro;
    int total = 0;

    /* Laco de impressao dos eventos */
    while (atual != NULL) 
    {
        printf("%d %d %d %d\n", atual->evento->tempo, atual->evento->tipo, 
        atual->evento->dado1, atual->evento->dado2);
        atual = atual->prox;
        total++;
    }

    printf("total %d eventos\n", total);
}
