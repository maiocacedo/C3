//Arquivo PilhaDinamica.h


typedef struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}Aluno;

typedef struct elemento* Pilha; // Pilha de Aluno
typedef struct elemento Elem; // Elemento da pilha de Aluno

// Funções para pilha de Aluno
Pilha* criaPilha();
int tamanhoPilha(Pilha* pi);
void liberaPilha(Pilha* pi);
Pilha *copiaPilha(Pilha* pi);
int pop1(Pilha* pi);
int pop2(Pilha* pi);
int popN(Pilha* pi, int n);
int push1(Pilha* pi, Aluno x);
int push2(Pilha* pi, Aluno *al);
int pushN(Pilha* pi, Aluno *al, int n);
int consultaTopoPilha(Pilha* pi, Aluno *al);
void imprimirPilha(Pilha* pi);
void imprimirPilhaRecursiva(Elem* no);
void imprimirPilhaInversaRecursiva(Elem* no);

typedef struct elementoStr* PilhaStr; // Pilha de char
typedef struct elementoStr ElemStr; // Elemento da pilha de char

// Funções para pilha de char
PilhaStr* criaPilhaStr();
void liberaPilhaStr(PilhaStr* pi);
int tamanhoPilhaStr(PilhaStr* pi);
int consultaTopoPilhaStr(PilhaStr* pi, char *str);
PilhaStr *copiaPilhaStr(PilhaStr* pi);
int pop1Str(PilhaStr* pi);
int popNStr(PilhaStr* pi, int n);
int pushNStr(PilhaStr* pi, int* x, int n);
void imprimirPilhaStr(PilhaStr* pi);
int pilhaIgualStr(PilhaStr* pi1, PilhaStr* pi2);
int pilhaStrPalindromo(PilhaStr* pi);
int xCy(char* str);

typedef struct elementoNum* PilhaNum; // Pilha de inteiros
typedef struct elementoNum ElemNum; // Elemento da pilha de inteiros

// Funções para pilha de inteiros
PilhaNum* criaPilhaNum();
void liberaPilhaNum(PilhaNum* pi);
int tamanhoPilhaNum(PilhaNum* pi);
int consultaTopoPilhaNum(PilhaNum* pi, int *x);
PilhaNum *copiaPilhaNum(PilhaNum* pi);
int pop1Num(PilhaNum* pi);
int popNNum(PilhaNum* pi, int n);
int push1Num(PilhaNum* pi, int x);
int pushNNum(PilhaNum* pi, int* x, int n);
void imprimirPilhaNum(PilhaNum* pi);
int maiorMenorMedia(PilhaNum* pi);
int pilhaIgual(PilhaNum* pi1, PilhaNum* pi2);
PilhaStr *pilhaStrInversa(PilhaStr* pi);
int pilhasNumParImpar(PilhaNum* pi);
PilhaNum *conversorBin(int dec, PilhaNum* pi);