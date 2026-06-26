#include <stdio.h>

int main(){

    int index;

    char * nomesAlunos[3][3] = {
        {"Aluno 0", "Português: 30", "Matemática: 90"},
        {"Aluno 1", "Português: 60", "Matemática: 60"},
        {"Aluno 2", "Português: 90", "Matemática: 30"}
    };

    printf("Digite o número do aluno que queira ver as notas... \n");
    printf("Para o Aluno 0, digite 0\n");
    printf("Para o Aluno 1, digite 1\n");
    printf("Para o Aluno 2, digite 2\n");

    scanf("%d", &index);

    printf("A nota do %s são: %s , %s... \n", nomesAlunos[index][0], nomesAlunos[index][1], nomesAlunos[index][2]);



    return 0;
}