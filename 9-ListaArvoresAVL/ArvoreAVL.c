
#include <stdio.h>
#include <stdlib.h>
#include "ArvoreAVL.h" //inclui os Prot�tipos


struct NO{
    int info;
    int altura;
    struct NO *esq;
    struct NO *dir;
};


ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento j� existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}


ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada n�
    free(raiz);//libera a raiz
}

int altura_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
    return no->altura;
}

int fatorBalanceamento_NO(struct NO* no){
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        //printf("%d\n",(*raiz)->info);
        //printf("No %d: %d\n",(*raiz)->info,fatorBalanceamento_NO(*raiz));
        printf("No %d: %d\n",(*raiz)->info,altura_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        //printf("%d\n",(*raiz)->info);
        printf("No %d: H(%d) fb(%d)\n",(*raiz)->info,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

int consulta_ArvAVL(ArvAVL *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}


//Exercicio 4 - Rotação RR
/*Resolução: A logica por traz da feição desta função apenas utilizei a função disponibilizada pelo professor como base
como na função RotacaoLL faz exatamente oque esta fução precisava fazer mas para o lado contrario apenas peguei a função
mantive exatamenta a mesma estrutura e inverti o lado para no fazer o balançeamento de um no que estava inconsistente do lado
direito reajustando os nos, movendo-os para a esquerda assim consequantemente alterando a *raiz se tornando B a nova raiz*/
void RotacaoRR(ArvAVL *raiz){
    printf("RotacaoRR\n");
    struct NO *B;
    B = (*raiz)->dir;
    (*raiz)->dir = B->esq;
    B->esq = *raiz;
    (*raiz)->altura = maior(altura_NO((*raiz)->dir),altura_NO((*raiz)->esq)) + 1;
    B->altura = maior(altura_NO(B->dir),(*raiz)->altura) + 1;
    *raiz = B;
}


//=================================
void RotacaoLL(ArvAVL *raiz){//LL
    printf("RotacaoLL\n");
    struct NO *B;
    B = (*raiz)->esq;
    (*raiz)->esq = B->dir;
    B->dir = *raiz;
    (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*raiz)->altura) + 1;
    *raiz = B;
}


void RotacaoLR(ArvAVL *raiz){//LR
    RotacaoRR(&(*raiz)->esq);
    RotacaoLL(raiz);
}

void RotacaoRL(ArvAVL *raiz){//RL
    RotacaoLL(&(*raiz)->dir);
    RotacaoRR(raiz);
}

int insere_ArvAVL(ArvAVL *raiz, int valor){
    int res;
    if(*raiz == NULL){//�rvore vazia ou n� folha
        struct NO *novo;
        novo = (struct NO*)malloc(sizeof(struct NO));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }

    struct NO *atual = *raiz;
    if(valor < atual->info){
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){
            if(fatorBalanceamento_NO(atual) >= 2){
                if(valor < (*raiz)->esq->info ){
                    RotacaoLL(raiz);
                }else{
                    RotacaoLR(raiz);
                }
            }
        }
    }else{
        if(valor > atual->info){
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){
                if(fatorBalanceamento_NO(atual) >= 2){
                    if((*raiz)->dir->info < valor){
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;

    return res;
}

struct NO* procuraMenor(struct NO* atual){
    struct NO *no1 = atual;
    struct NO *no2 = atual->esq;
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, int valor){
	if(*raiz == NULL){// valor n�o existe
	    printf("valor n�o existe!!\n");
	    return 0;
	}

    int res;
	if(valor < (*raiz)->info){
	    if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
	    }
	}

	if((*raiz)->info < valor){
	    if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1){
            if(fatorBalanceamento_NO(*raiz) >= 2){
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
	    }
	}

	if((*raiz)->info == valor){
	    if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){// n� tem 1 filho ou nenhum
			struct NO *oldNode = (*raiz);
			if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
			free(oldNode);
		}else { // n� tem 2 filhos
			struct NO* temp = procuraMenor((*raiz)->dir);
			(*raiz)->info = temp->info;
			remove_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorBalanceamento_NO(*raiz) >= 2){
				if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
					RotacaoLL(raiz);
				else
					RotacaoLR(raiz);
			}
		}
		if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
		return 1;
	}

	(*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

	return res;
}


//Exercicio 7 - Verifica se uma arvore é AVL ou não
/*Resolução: Utilizando a logica ja implementada em outras funções, como na função de altura_NO utilizando para fazer
a comparação de ser ou não AVL e depois utiliza a propria função para percorrer para a esquerda e depois para a direita
assim percorrendo a arvore toda e comparando os dados dela completa, inicia verificando se a arvore e vazia e se for fazia
ela é AVL*/
int Verifica_ArvoreAVL(ArvAVL *raiz) {
    if (raiz == NULL || *raiz == NULL)
        return 1;

    struct NO *no = *raiz;
    int balanceamento = altura_NO(no->esq) - altura_NO(no->dir);

    if (balanceamento < -1 || balanceamento > 1) {
        return 0;
    }

    if (!Verifica_ArvoreAVL(&(no->esq))) return 0;

    if (!Verifica_ArvoreAVL(&(no->dir))) return 0;

    return 1;
}

// Função auxiliar recursiva para trandormar uma arvore binária em AVL
void transformaAux(struct NO *no, ArvAVL *avl){
    if (no == NULL) return; // se o nó for nulo, retorna

    insere_ArvAVL(avl, no->info); // insere o valor do nó atual na árvore AVL

    transformaAux(no->esq, avl); // percorre a subárvore esquerda
    transformaAux(no->dir, avl); // percorre a subárvore direita
}

// Exercício 8 - Função que transforma uma árvore binária em uma árvore AVL
/**/
ArvAVL* transforma(ArvBin *raiz){
    ArvAVL *avl = cria_ArvAVL(); // cria uma nova árvore AVL

    if(raiz == NULL || *raiz == NULL) return avl; // se a árvore binária for nula, retorna a árvore AVL vazia

    transformaAux(*raiz, avl); // chama a função auxiliar para transformar a árvore binária em AVL

    return avl; // retorna a árvore AVL criada
}

