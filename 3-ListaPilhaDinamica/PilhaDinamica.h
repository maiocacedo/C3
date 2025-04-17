//Arquivo PilhaDinamica.h

typedef struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}Aluno;

typedef struct elemento* Pilha;
typedef struct elemento Elem;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int tamanho_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, Aluno *al);
int pop2(Pilha* pi);
int push2(Pilha* pi, Aluno *al);
int popN(Pilha* pi, int n);
int pushN(Pilha* pi, Aluno *al, int n);
void imprimirPilha(Pilha* pi);
void imprimirPilhaRecursiva(Elem* no);
void imprimirPilhaInversaRecursiva(Elem* no);