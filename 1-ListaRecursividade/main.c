/*

* 1 - Lista de Recursividade - Algoritmos e Estruturas de Dados III 
* Autores: | > Caio Macedo Lima da Cruz.....RA: 2651378
*          | > José Carlos Seben............RA: 2651130

*/

#include <stdio.h>
#include <stdlib.h>


// 1. Função recursiva para inverter um número inteiro. 
int InverteNumero(int numero) {
    if (numero == 0)return 0; // Caso base.
    if (numero < 0)return -InverteNumero(-numero); // Caso de números negativos.
    else{
        int casas = 1;
        int aux = numero;

        // Contar o número de algarismos para mover o número para posição correta na inversão.
        while ((aux / 10) > 0) {
            casas *= 10; 
            aux /= 10;
        } 
        return InverteNumero(numero / 10)  + (numero % 10) * casas; // Inverte o número recursivamente.
    }

}

/* 
? A função inverteNumero recebe um número inteiro e o inverte recursivamente, retornando um inteiro.
? Existe tratamento para números negativos, onde a inversão ocorre mas não perde o sinal de negativo.
? A lógica da inversão é a seguinte: é feita a contagem de casas do número, utilizando while para tal, onde o número
? Correspondente as casas decimais é utilizado para que o número seja posicionado corretamente na inversão.
? Com isso, a função inverteNumero é chamada recursivamente, dividindo o número por 10 e pegando o resto da divisão, 
? multiplicado pelas casas, para inverter o número.
!       input: 123  | output: 321
!       input: -123 | output: -321
*/

// 2. Função recursiva para somar os elementos de um vetor.
int SomarVetor(int *vetor, int tamanho) {
    if (tamanho == 0) return 0; // Caso base.
    if (sizeof(vetor) == 1) return vetor[0]; // Tratamento para vetor de um elemento.
    else return vetor[tamanho - 1] + SomarVetor(vetor, tamanho - 1); // Soma os elementos, começando do último, recursivamente.
}

/* 
? A função somarVetor recebe um vetor de inteiros e soma recursivamente, retornando um inteiro.
? Existe tratamento para vetores vazios e vetores de um unico elemento.
? A lógica da soma é a seguinte: a cada recursão, começando do ultimo termo, é somado o termo atual do vetor com o anterior 
? que é somado com o anterior e assim por diante, decrementando o tamanho. 
!       input: {1, 2, 3, 4, 5} | output: 15
!       input: {20, 30 , 40, 10, 80} | output: 180
*/

// 3. Função recursiva para somar os números de 1 a N.
int Somar1aN(int N) {
    if (N < 1) return 0; // Caso base e tratamento.
    else return N + Somar1aN(N - 1); // Soma N com a soma de 1 a N-1.
}

/* 
? A função somar1aN recebe um número inteiro N e soma recursivamente, todos os termos de 0 a N.
? Existe tratamento para inteiros menores que 1.
? A lógica da soma é a seguinte: a cada recursão, de N até 1, decrementando N. 
!       input: 5 | output: 15
!       input: 10 | output: 55
*/

// 4. Função recursiva para calcular a potência de um número.
int Potencia(int k, int n){
    if (n == 0) return 1; // Caso base.
    else return k * Potencia(k, n - 1); // Multiplica k por ele mesmo n vezes.
}

/*
? Função recursiva para calcular a potência de um número inteiro k elevado a n.
? O caso base é quando n é igual a 0, o que resulta em 1.
? A lógica da potência é a seguinte: a cada recursão, k é multiplicado por ele mesmo n vezes,
? decrementando n a cada chamada recursiva.
!       input: 2, 3 | output: 8
!       input: 3, 4 | output: 81
*/

// 5. Função recursiva para inverter um vetor de números reais.
float *InverteVetor(float *vetor, int tamanho){

    float aux; // Variável auxiliar para realizar a troca de posições no vetor.
    if (tamanho <= 1) return vetor; // Não há nada para ser invertido.
    else{
    
    aux = vetor[0]; // Armazena o primeiro elemento do vetor.
    vetor[0] = vetor[tamanho - 1]; // Troca o primeiro elemento pelo último.
    vetor[tamanho-1] = aux; // Troca o último elemento pelo primeiro.

    InverteVetor(vetor+1, tamanho-2); 

    return vetor; // Retorna o vetor invertido.
    
}
}

/*
? A função inverteVetor recebe um vetor de números reais, e a ordem dos elementos é invertida recursivamente.
? O caso base é para quando o tamanho do vetor for menor ou igual a 1.
? A lógica da inversão é a seguinte: a cada recursão, o primeiro elemento do vetor é trocado pelo último, e é somado 1 no ponteiro do vetor,
? E 2 no tamanho, desse modo, o vetor aponta para o próximo elemento e os elementos já invertidos são desconsiderados. 	
? Por fim, é retornado o vetor de reais invertido.
!       input: {1, 2, 0.3, 4} | output: {4, 0.3, 2, 1}
!       input: {0.1, 0.2, 10, 1} | output: {1, 10, 0.2, 0.1}
*/

// 6. Função recursiva para calcular o máximo divisor comum entre dois numeros (n1 e n2).
int mdc(int n1, int n2){
    if (n2 == 0) return n1; // Caso base.
    if (n1 == 0) return n2; // Tratamento.
    int resto = n2 % n1; // Resto da divisão.
    return mdc(n1-resto, resto); // Chamada recursiva.
}

/*
? Função recursiva para calcular o máximo divisor comum entre dois números inteiros n1 e n2.
? O caso base é quando n2 é igual a 0, o que resulta em n1.
? A lógica do mdc é a seguinte: a cada recursão, o resto da divisão de n2 por n1 é calculado e o mdc é chamado novamente,
? Decrementando n1 pelo resto e passando o resto como novo n2.
!       input: 24, 30 | output: 6
!       input: 10, 5 | output: 5
*/

// 7. Função recursiva para contar a ocorrência de um dígito em um natural.
int Ocorrencia(int k, int n){
    if (n <= 0) return 0; // Caso base.
    return (n % 10 == k) + Ocorrencia(k, n/10); // Verifica se o último dígito do natural é igual ao dígito k e chama a função recursivamente.
}

/*
? A função Ocorrencia recebe um número inteiro k e um número natural n, e conta a ocorrência de k em n.
? O caso base é quando n é menor ou igual a 0.
? A lógica da contagem é a seguinte: a cada recursão, o último dígito de n é verificado se é igual a k,
? A partir da divisão de n por 10, em que o resto corresponde ao último dígito, e o número é reduzido a cada chamada recursiva.
? O resultado é a soma de 1 (Verdadeiro) se o dígito for igual a k, ou 0 (falso) se não for.
!       input: 3, 332232 | output: 4
!       input: 2, 222222 | output: 6
*/

// 8. Função recursiva para calcular multiplicação por soma.
int Multip_Rec(int n1,int n2){
    if (n2 <= 0) return 0; // Caso base.
    if (n2 == 1) return n1; // Caso base.
    else return n1 + Multip_Rec(n1, n2 - 1); // Multiplicação recursiva.
}

/*
? A função Multip_Rec recebe dois números inteiros n1 e n2, e calcula a multiplicação de n1 por n2 utilizando soma.
? Os casos bases são quando n2 é menor ou igual a 0, e quando n2 é igual a 1.
? A lógica da multiplicação é a seguinte: a cada recursão, n1 é somado a ele mesmo n2 vezes, decrementando n2 a cada chamada recursiva.
? O resultado é a soma de n1 com o resultado da chamada recursiva.
!       input: 4, 3 | output: 12
!       input: 5, 2 | output: 10
*/

// 9. Função recursiva para imprimir os pares de 0 a N.
void Imprimir0aNPares(int N){
    if (N<=0) return; // Caso base.
    Imprimir0aNPares(N-1); // Chamando a função recursivamente, antes de imprimir.
    if(N%2==0) printf("%d ", N); // Imprimindo se for par (divisível por 2).
}

/*
? A função Imprimir0aNPares recebe um número inteiro N e imprime os números pares de 0 a N.
? O caso base é quando N é menor ou igual a 0, não natural e 0 não é par.
? A lógica da impressão é a seguinte: a cada recursão, N é decrementado e a função é chamada novamente,
? depois, se N for par, ele é impresso.
? O resultado é a impressão dos números pares de 0 a N, em ordem crescente, devido a ordem da chamada da função e do printf.
!       input: 10 | output: 0 2 4 6 8 10
!       input: 5 | output: 0 2 4
*/

// 10. Função recursiva para imprimir os naturais de N a 0.
void ImprimirNa0(int N){
    if (N<0) return; // Caso base.
    printf("%d ", N); ImprimirNa0(N-1); // Imprimindo e depois chamando a função recursivamente.
}

/*
? A função ImprimirNa0 recebe um número inteiro N e imprime os números naturais de N a 0.
? O caso base é quando N é menor que 0, não natural.
? A lógica da impressão é a seguinte: a cada recursão, N é decrementado e a função é chamada novamente,
? depois, N é impresso.
? O resultado é a impressão dos números naturais de N a 0, em ordem decrescente, devido a ordem da chamada da função e do printf.
!       input: 10 | output: 10 9 8 7 6 5 4 3 2 1 0
!       input: 5 | output: 5 4 3 2 1 0 
*/

// 11. Função recursiva para imprimir os pares de 0 a N.
void ImprimirNa0Pares(int N){
    if (N<=0) return; // Caso base.
    if(N%2==0) printf("%d ", N); // Imprimindo se for par (Divisível por 2).
    ImprimirNa0Pares(N-1); // Chamando a função recursivamente, depois de imprimir.
}

/*
? A função ImprimirNa0Pares recebe um número inteiro N e imprime os números pares de N a 0.
? O caso base é quando N é menor ou igual a 0, não natural e 0 não é par.
? A lógica da impressão é a seguinte: a cada recursão, N é decrementado e a função é chamada novamente,
? depois, se N for par, ele é impresso.
? O resultado é a impressão dos números pares de N a 0, em ordem decrescente, devido a ordem da chamada da função e do printf.
!       input: 10 | output: 10 8 6 4 2 0
!       input: 5 | output: 4 2 0   
*/

// 12. Função recursiva para calcular fatorial duplo
unsigned long int FatDuplo(unsigned long int num){
    if(num<=2) return num; // Caso base.
    else return num*FatDuplo(num-2); // Calculando o fatorial duplo recursivamente.
}

/*
? A função FatDuplo recebe um número inteiro e calcula o fatorial duplo desse número.
? O caso base é quando o número é menor ou igual a 2.
? A lógica do fatorial duplo é a seguinte: a cada recursão, o número é multiplicado pelo resultado da chamada recursiva,
? decrementando o número em 2 a cada chamada (característica do fatorial duplo).
? O resultado é o fatorial duplo do número.
!       input: 5 | output: 15
!       input: 10 | output: 55
*/

int main() {

    int j = 13, k = 0, n = 0;
    unsigned long int fat = 0; // Variável para armazenar o fatorial duplo.
    int *vetor; 
    float *vetor2; // Ponteiro para o vetor de float.
    
    while(j!=0) {
    
        system("cls");

        printf("--------- Menu ---------\n\n");

        printf("Escolha uma função:\n");

        printf("1. InverteNumero\n");
        printf("2. SomarVetor\n");
        printf("3. Somar1aN\n");
        printf("4. Potencia\n");
        printf("5. InverteVetor\n");
        printf("6. MDC\n");
        printf("7. Ocorrencia\n");
        printf("8. Multip_Rec\n");
        printf("9. Imprimir0aNPares\n");
        printf("10. ImprimirNa0\n");
        printf("11. ImprimirNa0Pares\n");
        printf("12. FatDuplo\n");
        printf("0. Sair\n");

        printf("Digite o numero da função que deseja executar: ");
        scanf("%d", &j);
        
        switch(j) {
        case 0:
            system("pause");
            return 0;
        case 1:
            printf("Digite um numero inteiro: "); // Solicita um número inteiro ao usuário.
            scanf("%d", &n);
            printf("\n - O numero %d invertido e %d\n", n, InverteNumero(n)); // Chama a função InverteNumero e imprime o resultado.
            system("pause");
            break;
        case 2:
            printf("Digite o tamanho do vetor: "); // Solicita o tamanho do vetor ao usuário.
            scanf("%d", &n);
            
            if (n > 0) {
                vetor = malloc((unsigned int)n * sizeof(int)); // Alocação de memória para o vetor de inteiros.
            } else {
                printf("Erro: Tamanho do vetor deve ser positivo.\n");
                return 1; // Retorna erro se o tamanho for inválido.
            }

            for(int i = 0; i < n; i++) {
                printf("\nElemento %d:  ", i+1); // Solicita o elemento do vetor ao usuário.
                scanf("%d", &vetor[i]);
            }
            printf("\n - A soma do vetor e %d\n", SomarVetor(vetor, n)); // Chama a função SomarVetor e imprime o resultado.
            system("pause");
            free(vetor); // Libera a memória alocada para o vetor.
            break;
        case 3:
            printf("Digite um numero natural: "); // Solicita um número natural ao usuário.
            scanf("%d", &n);

            printf("\n - A soma de 1 a %d e %d\n", n, Somar1aN(n)); // Chama a função Somar1aN e imprime o resultado.
            system("pause");
            break;
        case 4:
            printf("Digite a base: "); // Solicita a base ao usuário.
            scanf("%d", &k);

            printf("Digite o expoente: "); // Solicita o expoente ao usuário.
            scanf("%d", &n);

            printf("\n - A potencia de %d elevado a %d e %d\n", k, n, Potencia(k, n)); // Chama a função Potencia e imprime o resultado.
            system("pause");
            break;
        case 5:
            vetor2 = malloc(100 * sizeof(float)); // Alocação de memória para o vetor de float de tamanho 100.

            printf("Digite o coeficiente para preencher o vetor de 100 elementos: "); // Solicita o coeficiente ao usuário.
            scanf("%d", &k);
            
            for (int i = 0; i < 100; i++) vetor2[i] = (float)(i + 1)/(float)(k); // Preenche o vetor com valores de 1/k a 100/k.

            // Imprime o vetor original.
            printf("\n - O vetor original e: \n - ");
            for (int i = 0; i < 100; i++) printf("%.4f |", vetor2[i]);
            

            vetor2 = InverteVetor(vetor2, 100); // Inverte o vetor.

            // Imprime o vetor invertido.
            printf("\n\n - O vetor invertido e: \n - ");
            for (int i = 0; i < 100; i++) printf("%.4f |", vetor2[i]);
            
            printf("\n\n");

            system("pause");
            free(vetor2); // Libera a memória alocada para o vetor.

            break;
        case 6:
            printf("Digite o primeiro numero: "); // Solicita o primeiro número ao usuário.
            scanf("%d", &n);
            
            printf("Digite o segundo numero: "); // Solicita o segundo número ao usuário.
            scanf("%d", &k);

            printf("\n - MDC: %d\n\n", mdc(n, k)); // Chama a função mdc e imprime o resultado.
            system("pause");
            break;
        case 7:
            printf("Digite um numero natural: "); // Solicita um número natural ao usuário.
            scanf("%d", &n);

            printf("Digite um digito para verificar: "); // Solicita um dígito ao usuário.
            scanf("%d", &k);

            printf("\n - Ocorrencia de %d em %d: %d\n\n", k, n, Ocorrencia(k, n)); // Chama a função Ocorrencia e imprime o resultado.
            system("pause");
            break;
        case 8:
            printf("Digite o primeiro numero: "); // Solicita o primeiro número ao usuário.
            scanf("%d", &n);

            printf("Digite o segundo numero: "); // Solicita o segundo número ao usuário.
            scanf("%d", &k);

            printf("\n - Multiplicacao recursiva por soma: %d x %d = %d \n", n, k, Multip_Rec(n,k)); // Chama a função Multip_Rec e imprime o resultado.
            system("pause");
            break;
        case 9:
            printf("Digite um numero natural: "); // Solicita um número natural ao usuário.
            scanf("%d", &n);

            printf("\n - Pares de 0 a %d: ", n); // Imprime os pares de 0 a N.
            Imprimir0aNPares(n);
            system("pause");
            break;
        case 10:
            printf("Digite um numero natural: "); // Solicita um número natural ao usuário.
            scanf("%d", &n);

            printf("\n - de %d a 0: ", n); // Imprime os naturais de N a 0.
            ImprimirNa0(n);
            system("pause");
            break;
        case 11:
            printf("Digite um numero natural: "); // Solicita um número natural ao usuário.
            scanf("%d", &n);

            printf("\n\n - Pares de %d a 0: ", n); // Imprime os pares de N a 0.
            ImprimirNa0Pares(n);
            system("pause");
            break;
        case 12:
            printf("Digite um numero natural: "); // Solicita um número natural ao usuário.
            scanf("%lu", &fat);

            printf("\n\n - Fatorial Duplo de %lu: %lu", fat, FatDuplo(fat)); // Chama a função FatDuplo e imprime o resultado.
            system("pause");
            break;
        }
    }
    return 0;

}
