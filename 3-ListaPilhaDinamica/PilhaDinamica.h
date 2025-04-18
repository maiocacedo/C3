//Arquivo PilhaDinamica.h

typedef struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
}Aluno;

typedef struct elemento* Pilha;
typedef struct elemento Elem;
typedef struct elementoNum* PilhaNum;
typedef struct elementoNum ElemNum;
typedef struct elementoString* PilhaStr;
typedef struct elementoString ElemStr;

Pilha* criaPilha();
void liberaPilha(Pilha* pi);
int tamanhoPilha(Pilha* pi);
int consultaTopoPilha(Pilha* pi, Aluno *al);
Pilha *copiaPilha(Pilha* pi);
PilhaStr *copiaPilhaStr(PilhaStr* pi);
int pop2(Pilha* pi);
int push2(Pilha* pi, Aluno *al);
int popN(Pilha* pi, int n);
int pushN(Pilha* pi, Aluno *al, int n);
int pushNNum(PilhaNum* pi, int* x, int n);
int push1(PilhaNum* pi, int x);
void imprimirPilha(Pilha* pi);
void imprimirPilhaRecursiva(Elem* no);
void imprimirPilhaInversaRecursiva(Elem* no);
int maiorMenorMedia(PilhaNum* pi);
int pilhaIgual(PilhaNum* pi1, PilhaNum* pi2);
int pilhaStrInversa(PilhaStr* pi);
int pilhaStrPalindromo(PilhaStr* pi);
int pilhasNumParImpar(PilhaNum* pi);
int conversorBin(int dec, PilhaNum* pi);