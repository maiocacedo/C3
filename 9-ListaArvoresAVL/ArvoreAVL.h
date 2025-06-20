
#include <stdio.h>
#include <stdlib.h>


typedef struct NO* ArvAVL;
typedef struct NO* ArvBin;


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

// Exercicio 8 - Transforma uma Arvore Binária em uma AVL
ArvBin* cria_ArvBin();
void libera_NO(struct NO* no);
void libera_ArvBin(ArvBin* raiz);
int insere_ArvBin(ArvBin* raiz, int valor);
ArvAVL* transforma(ArvBin *raiz);
void transformaAux(struct NO *no, ArvAVL *avl);

//*EXERCICIOS DE EXPLICAÇÃO A BAIXO <1, 2, 3, 5, 6>

// Exercício 1 - Examine cada árvore abaixo e responda se é ou não uma AVL e justifique a resposta.
/*
  Árvore 1: Não é  AVL, pois no nó 22 a altura do esquerdo e do direito são diferentes
  Árvore 2: Não é AVL, porque, assim como na árvore 1, no nó 22 a altura do esquerdo e do direito são diferentes
  Árvore 3: É AVL, já que não existe nó direito nem esquerdo, a altura em ambos é 0, tornando a árvore balanceada.
  Árvore 4: Não é AVL, porque no nó 12, a altura entre o nó à esquerda (não existe) é 0, e entre no nó à direita é 2, tornando a 
  árvore desbalanceada
*/

// Exercício 2 - 
/*
Monte a árvore AVL (passo-a-passo) para as seguintes inserções de chaves, 
indicando a cada passo qual elemento foi inserido ou qual rotação foi realizada, 
Ilustrar graficamente/textualmente como é feito o balanceamento:

a) 50, 30, 20, 70, 40, 35, 37, 38, 10, 32, 45, 42, 25, 47, 36.
R:  insere 50 como raiz, sem balanceamento;
    insere 30 em 50->esq, sem necessidade de balanceamento;
    insere 20 em 30->esq, rotação direita simples FB(50) = 2: 
        raiz agora é 30;
        30->esq = 20;
        30->dir = 50
    insere 70 em 50->dir, sem rotação;
    insere 40 em 50->esq, sem rotação;
    insere 35 em 40->esq, com rotação Esquerda Dupla FB(30) = -2:
        rotação direita em 50 = troca 50 com 40, tornando 40 raiz da subarvóre;
        rotação esquerda em 30.
    insere 37 em 35 -> dir, sem rotaçã0;
    insere 38 em 37->dir, com rotação esquerda simples FB(35):
        37 troca com 35, então, 37->esq = 35 e 37->dir = 38.
    insere 10 em 20->esq sem rotação;
    insere 32 em 35->esq, com rotação direita dupla FB(40) =2:
        rotação esquerda em 30
        rotação direita em 40
        37 se torna raiz;
        37→esq=30; 37→dir=40; 30→esq=20; 30→dir=35; 40→esq=38; 40→dir=50; 35→esq=32
    insere 45 em 50->esq sem rotação;
    insere 42 em 45->esq com rotação Esquerda Dupla FB(40)=-2:
        rotação direita em 50
        rotação esquerda em 40 
        45 troca com 40; 40->esq = 38; 40->dir = 42; 45->dir = 50;
    insere 25 em 20->dir sem rotação;
    insere 47 em 50->esq sem rotação;
    por fim insere 36 em 35->dir, sem rotação.
    Árvore final:
        Raiz: 37
        37->esq = 30,   37->dir = 45;
        30->esq = 20,   30->dir = 35;
        20->esq = 10,   20->dir = 25;
        35->esq = 32,   35->dir = 36;
        45->esq = 40,   45->dir = 50;
        40->esq = 38,   40->dir = 42;
        50->esq = 47,   50->dir = 70;

b) 100, 80, 60, 40, 20, 70, 30, 50, 35, 45, 55, 75, 65, 73, 77.
R:  insere 100, como raiz;
    insere 80 em 100->esq
    insere 60 em 80->100 com rotação LL:
        80 vira raiz; 80->esq = 60; 80->dir = 100
    insere 40 em 60->esq sem rotação
    insere 20 em 40->esq com rotação LL:
        60 vira raiz , 60->esq = 40;60->80;
    insere 70 em 80->esq sem rotação
    insere 30 em 20->dir, co rotação LR:
        rotação à esquerda em 20
        rotação à direita em 40
    insere 50 em 40->dir  sem rotação 
    insere 35 em 50->esq
    insere 45 em 35->dir com rotação RR:
        rotação à esquerda em 30
    insere 55 em 50->dir sem rotação
    insere 75 em 70->dir sem rotação
    insere 65 em 70->esq sem rotação
    insere 73 em 75->esq com rotação LR:
        Rotação à esquerda em 70
        Rotação à direita em 80
    insere 77 em 80->esq sem rotação.
    Árvore Final:
        Raiz = 60
        60->esq = 40,      60->dir = 75;
        40->esq = 30,      40->dir = 50;
        30->esq = 20,      30->dir = 35;
        50->esq = 45,      50->dir = 55;
        75->esq = 70,      75->dir = 80;
        70->esq = 65,      70->dir = 73;
        80->esq = 77,      80->dir = 100.


c) 41,38, 31, 12, 19, 8, 27, 49.
R:  insere 41, como raiz;
    insere 38 em 41->esq, sem rotação;
    insere 31 em 38->esq, com rotação LL:
        Rotação direita em 41; 38 se torna a raiz;
    insere 12 em 31->esq sem rotação;
    insere 19 em 12->dir com rotação LR:
        rotação esquerda em 12
        rotação direita em 31
    insere 8 em 12->esq com rotação LL:
        Rotação direita em 38, 19 passa a ser raiz;
    insere 27 em 31->esq sem rotação
    insere 49 em 41->dir sem rotação.
    Árvore Final:
        Raiz: 19
        19->esq = 12,       19->dir = 38;
        12->esq = 8,        12->dir = NULL;
        38->esq = 31,       38->dir = 41;
        31->esq = 27,       31->dir = NULL;
        41->esq = NULL,     41->dir = 49.


d) 10, 21, 15, 17, 16, 19, 20
R:  insere 10 como raiz;
    insere 21 em 10->dir
    insere 15 em 21->esq com rotação RL:
        Rotação direita em 21
        rotação esquerda em 10
        15 agora é raiz;
    insere 17 em 21->esq sem rotação
    insere 16 em 17->esq com rotação LL:
        rotação direita em 21
    insere 19 em 21->esq com rotação RR:
        rotação esquerda em 15, 19 agora é raiz
    insere 20 em 19->dir sem rotação
    Árvore Final:
        Raiz: 17
        17->esq = 15,        17->dir = 21;
        15->esq = 10,        15->dir = 16;
        21->esq = 19,        21->dir = NULL;
        19->esq = NULL,      19→dir = 20;

*/

// Exercício 3 - 
/*
Um certo professor Amongus afirma que a ordem pela qual um conjunto fixo de elementos é inserido 
em uma árvore AVL não interessa –sempre resulta na mesma árvore. Apresente um pequeno exemplo 
que prove que ele está errado.
R: Ele está errado porque se eu inserir os números do seguinte conjunto em um árvore, de formas diferentes,
o resulta muda:
conjunto: {10,20,30,40,50}

inserindo 10,20,30,40,50

    insere 10 como raiz
    insere 20 em 10->dir sem rotação
    insere 30 em 20->dir com rotação RR:
        rotação a esquerda em 10, 20 se torna raiz
    insere 40 em 30->dir sem rotação
    insere 50 em 40->dir com rotação RR:
        rotação a esquerda em 30
    Árvore Final(10,20,30,40,50):
        Raiz = 20
        20->esq = 10,   20->dir = 40;
        40->esq = 30,   40->dir = 50;
    
inserindo 50,40,30,20,10

    insere 50 como raiz
    insere 40 em 50->esq, sem rotação
    insere 30 em 40->esq, com rotação LL:
        rotação à direita em 50, 40 se torna raiz
    insere 20 em 30->esq sem rotação
    insere 10 em 20->esq com rotação LL:
        rotação à direita em 30
    Árvore final(50,40,30,20,10):
        Raiz = 40
        40->esq = 20,     40→dir = 50;
        20->esq = 10,     20→dir = 30;

Ou seja, o professor está equivocado a respeito da importância da ordem de inserção dos elementos de um 
conjunto.


*/
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

ArvAVL* transforma(ArvAVL *raiz)

*/