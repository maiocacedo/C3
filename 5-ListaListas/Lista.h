//Arquivo ListaDinEncad.h

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

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