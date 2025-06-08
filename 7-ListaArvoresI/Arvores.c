#include <stdio.h>
#include <stdlib.h>
#include "Arvores.h"



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

// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 � o n� anterior a r na ordem e-r-d
    // no1 � o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}


void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

//Exercicio 2 - funcoes de varredura
/*Resolução: A linha de raciocinio que utilizei foi perceber o padrão de percurção da função ja pronta
preOrdem_ArvBin e com o material explicado na aula de as maneiras de percurção cheguei a conclusão que
precisaria apenas mudar a "direção" como que na preOrdem_ArvBin vai de raiz->esquerda->direita mudei para
emOrdem_ArvBin ir de esquerda->raiz->direita e posOrdem_ArvBin seguir a direção esquerda->direita->raiz*/
void emOrdem_ArvBin(ArvBin *raiz){
    if (raiz == NULL) return;

    if(*raiz != NULL) {
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

//Exercicio 2 - funcoes de varredura
void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL) return;

    if(*raiz != NULL) {
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

//Exercicio 3 - Conta nos
/*Resolução: A logica utilizada por tras desta função é percorrer todos os itens da esquerda e anexar a quantia de nos
percorridos a variavel countEsq e depois fazer o mesmo processo para a direita armazendando a quantia em countDir
para finalizar soma countEsq + CountDir com +1 do no atual que não vai ser contado por nenhum dos percursos*/
int totalNO_ArvBin(ArvBin *raiz){
    if(raiz == NULL || *raiz == NULL) return 0;

    int countEsq = 0;
    int countDir = 0;

    countEsq = totalNO_ArvBin(&((*raiz)->esq));
    countDir = totalNO_ArvBin(&((*raiz)->dir));

    return countEsq + countDir + 1; // +1 para contar o nó atual
}

//Exercicio 4 - Localizar valor
/*Resolução: A função vai receber um valor para analisar se esta ou não presente na arvore ira comparar os dados de *raiz->info
com o valor passado quando encontrar um valor igual ao passado o loop acaba para percorrer a matriz vai fazendo a comparação
se o valor interno do no for menor que o valor encontrado vai para direita caso contrario vai para a esquerda até percorrer a arvore toda*/
int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL) return 0;

    while (*raiz != NULL){
        if (valor == (*raiz)->info) return 1;
        if (valor > (*raiz)->info)
            raiz = &((*raiz)->dir);
        else
            raiz = &((*raiz)->esq);

    }

    return 0;
}

//Exercicio 5 - Remova um no
/*Resolução: A função remove um nó especifico de uma árvore, mantendo a hierarquia correta e relações
entre os nós. Isso é feito a partir da verificação das subarvores a esquerda, que caso seja nula, 
considera-se que o nó direito do nó a ser removido assume seu lugar, se não, procura o maior nó 
à esquerda, sempre atualizando o nóPai (ou nó anterior) e o no filho. Ao encontrar o nó, é verificado 
se o noPai é diferente de atual, porque, caso ele seja, significa que o noFilho não é filho direto de atual
o que significa que o nóFilho é o maior nó a esquerda. E então, para não perder uma possível subarvore a esquerda
o noPai->dir irá apontar para o nóFilho->esq.  Por fim, o noFilho->dir aponta para o dir do atual, e o nó
é liberado.*/
struct NO* Remove_ArvoreAtual(struct NO* atual){
    struct NO *noPai, *noFilho; 
    if(atual == NULL) return NULL; // se o nó atual for nulo, não há nada a remover
    // se o nó atual não tem filho esquerdo, retorna o filho direito de atual, e libera atual
    if(atual->esq == NULL){
        noFilho = atual->dir;
        free(atual);
        return noFilho;
    }
    // noPai é o pai de noFilho
    noPai = atual;
    noFilho = atual->esq;

    // Encontra o maior nó na subárvore esquerda
    while(noFilho->dir != NULL){
        noPai = noFilho;
        noFilho = noFilho->dir;
    }
    // se noPai for diferente de atual, significa que noFilho não é o filho direto de atual
    // ou seja, noFilho é o maior nó na subárvore esquerda
    if(noPai != atual){
        // noPai agora aponta para o filho esquerdo de noFilho
        noPai->dir = noFilho->esq; 
        noFilho->esq = atual->esq; // o filho esquerdo de atual agora é o filho esquerdo de noFilho
    }
    noFilho->dir = atual->dir; // o filho direito de atual agora é o filho direito de noFilho
    free(atual); // libera o nó atual
    return noFilho; // retorna o novo nó atual (noFilho) que substitui o nó removido
}

