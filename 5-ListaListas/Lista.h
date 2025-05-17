//Arquivo Lista.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elemento;
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);
void imprime_lista(Lista* li);

int remove_lista_rec(Lista* li, int mat); // Exercício 2
int lista_ingual_rec(Lista* li1, Lista* li2); // Exercício 2
int insere_lista_pos(Lista* li, struct aluno al, int pos); // Exercício 3 

int remove_toda_lista_rec(Lista* li, int mat); // Exercício 5
int remove_toda_lista(Lista* li, int mat); // Exercício 5

int remove_repetido_lista(Lista* li); // Exercício 7

int Troca(Lista* li, Elemento* p ); // Exercício 9

int remove_lista_rec(Lista* li, int mat); // Exercício 2
int lista_ingual_rec(Lista* li1, Lista* li2); // Exercício 2
int insere_lista_pos(Lista* li, struct aluno al, int pos); // Exercício 3 

int remove_toda_lista_rec(Lista* li, int mat); // Exercício 5
int remove_toda_lista(Lista* li, int mat); // Exercício 5

int remove_repetido_lista(Lista* li); // Exercício 7

int Troca(Lista* li, Elemento* p ); // Exercício 9

//Exercicio 1) A.:
void consulta_lista_Pmatricula(Lista *li, int matricula);

//Exercicio 1) B.:
void consulta_lista_Pposicao(Lista *li, int posicao);

//Exercicio 4:
void lista_Vetor(Lista *li, float v[], int n);

//Exercicio 6:
void concatena_listas(Lista *li, Lista *lista_floats);

//Exercicio 8:
void funde_listas_ord(Lista *li1, Lista *li2, Lista *lista_resultado);