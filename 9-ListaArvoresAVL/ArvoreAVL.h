#include <stdio.h>
#include <stdlib.h>

typedef struct NO* ArvAVL;

ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, int data);
int remove_ArvAVL(ArvAVL *raiz, int valor);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, int valor);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

//Exercicio 4 - Rotação RR
void RotacaoRR(ArvAVL *raiz);

//Exercicio 7 - Verifica se é Arvore AVL
int Verifica_ArvoreAVL(ArvAVL *raiz);

//*EXERCICIOS DE EXPLICAÇÃO A BAIXO <5, 6>

/*
!Exercicio 5 - Explicação função insere_ArvAVL

    int insere_ArvAVL(ArvAVL *raiz, int valor){         //todo: cabeçalho da função
    int res;                                            //todo: inicializa uma variavel para o resultado
    if(*raiz == NULL){//�rvore vazia ou n� folha      //todo: faz a verificação de se a Arvore é vazia ou se é um no folha
        struct NO *novo;                               //todo: inicializa um novo no auxiliar
        novo = (struct NO*)malloc(sizeof(struct NO));  //todo: faz a alocação de memoria para este novo no
        if(novo == NULL)                               //todo: verifica se o novo é vazio, se for retorna
            return 0;

        novo->info = valor;                            //todo: o novo no->info recebe valor
        novo->altura = 0;                              //todo: ajusta a altura no novo no como 0
        novo->esq = NULL;                              //todo: ajusta seu ponteiro esquerdo como nulo
        novo->dir = NULL;                              //todo: ajusta seu ponteiro direito como nulo
        *raiz = novo;                                  //todo: *raiz recebe novo, então novo se torna a raiz da arvore
        return 1;                                      //todo: retorna 1 como sucesso de ter alocado um novo no como a raiz
    }

    struct NO *atual = *raiz;                                   //todo: aponta para atual
    if(valor < atual->info){                                    //todo: inicia a comparação se o valor for menor que o atual->info
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1){    
            if(fatorBalanceamento_NO(atual) >= 2){              //todo: verifica o balancemaento se for igual ou maior que 2 esta desbalanceado
                if(valor < (*raiz)->esq->info ){                //todo: verifica se o valor é meor que o do ponteiro esquerdo comparando com o valor do ponteiro esquerdo
                    RotacaoLL(raiz);                            //todo: no caso de desbalanceamento aplicam as rotaçoes simples ou se preciso a dupla
                }else{                                          //todo: da esquerda para a direita
                    RotacaoLR(raiz);
                }
            }
        }
    }else{                                                      //todo: faz a comparação se o valor for maior vai pra direita
        if(valor > atual->info){   
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1){  
                if(fatorBalanceamento_NO(atual) >= 2){          //todo: comparação de balanceamento assim como do outro lado
                    if((*raiz)->dir->info < valor){             //todo: em caso de desbalanceamento faz as ações de balanceamente simples ou duplo mas agora indo da direita para a esquerda
                        RotacaoRR(raiz);
                    }else{
                        RotacaoRL(raiz);
                    }
                }
            }
        }else{
            printf("Valor duplicado!!\n");                      //todo: Se o valor ja existir na arvore retorna a 0
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1; //todo: utiliza filhos como base para atualizar a altura do pai

    return res;                                                 //todo: retorna o resultado
}
*/

//!Exercicio 6 - Explicação função remove_ArvAVL   
/*
Resolução: Nesta função recebe um valor como parametro vai fazer as comparações até encontrar o no com o valor como do parametro informado
remove o seguinte no e faz os ajustes para que depois dos ajustes a arvore se mantenha balanceada e continue sendo uma arvore AVL

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
*/