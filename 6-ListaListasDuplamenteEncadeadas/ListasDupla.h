struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct elemento* Lista;



Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct aluno *al);
int consulta_lista_mat(Lista* li, int mat, struct aluno *al);
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);


//Exercicio 1.:
int remove_lista_Pmat(Lista* li, int mat);




//Exercicio 2.:
int insere_lista_ordenada(Lista *li, struct aluno al);


//Exercicio 3.:
int conta_lista_nota(Lista* li, int n1);


// Exercicio 4.:
int insere_lista_circular_inicio(Lista* li, struct aluno al);
int insere_lista_circular_final(Lista* li, struct aluno al);
int remove_lista_circular_inicio(Lista* li);
int remove_lista_circular_final(Lista* li);
int percorre_lista_circular(Lista* li);
void libera_lista_circular(Lista* li);

// Exercicio 5.:

typedef struct nodesc *noDesc;
int inicializa_noDesc(noDesc *no);
int enfileirar(noDesc *desc, int elem);
int desenfileirar(noDesc *desc, int *elem);
void imprime_fila(noDesc *desc);

