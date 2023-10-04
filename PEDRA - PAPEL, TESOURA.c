#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Pedra 1
#define Papel 2
#define Tesoura 3
int VitoriaJogador = 0;
int VitoriaMaquina = 0;
int empate = 0;
char nome[50];
const char *Escolha(int item)
{
    if (item == Pedra)
        return "PEDRA";
    else if (item == Papel)
        return "PAPEL";
    else
        return "TESOURA";
}
int ganhador(int EscolhaJogador, int EscolhaMaquina)
{
    // empate 0
    // jogador 1
    // maquina 2
    int ganhador;
    if (EscolhaJogador == EscolhaMaquina)
        ganhador = 0;
    else if (EscolhaJogador == 1 && EscolhaMaquina == 2)
        ganhador = 2;
    else if (EscolhaJogador == 2 && EscolhaMaquina == 1)
        ganhador = 1;

    else if (EscolhaJogador == 2 && EscolhaMaquina == 3)
        ganhador = 2;
    else if (EscolhaJogador == 3 && EscolhaMaquina == 2)
        ganhador = 1;

    else if (EscolhaJogador == 1 && EscolhaMaquina == 3)
        ganhador = 1;
    else if (EscolhaJogador == 3 && EscolhaMaquina == 1)
        ganhador = 2;

    return ganhador;
}

void jogo()
{
    int EscolhaJogador, EscolhaMaquina, vitoria;

    printf("\n%s, qual sua escolha?\n", nome);
    printf(" 1 - Pedra\n 2 - Papel\n 3 - Tesoura\n");
    printf("Sua escolha sera: ");
    scanf(" %d", &EscolhaJogador);
    printf("Voce: ");
    printf("%s\n", Escolha(EscolhaJogador));

    EscolhaMaquina = rand() % 3 + 1;
    printf("MAQUINA:");
    printf("%s\n", Escolha(EscolhaMaquina));
    puts("");

    vitoria = ganhador(EscolhaJogador, EscolhaMaquina);
    if (vitoria == 0)
    {
        printf("Empate\n");
        empate++;
    }
    else if (vitoria == 1)
    {
        printf("%s ganhou\n", nome);
        VitoriaJogador++;
    }
    else
    {
        printf("Vitoria da maquina\n");
        VitoriaMaquina++;
    }
}

int main()
{
    srand(time(NULL));
    int x = 0; // jogar outra vez
    puts(" ______________________________________");
    puts("|                                      |");
    puts("| BEM VINDO AO PEDRA - PAPEL - TESOURA |");
    puts("|______________________________________|\n");
    printf(" Qual seu nome? ");
    scanf("%s", &nome);
    do
    {
        jogo();
        puts("");
        printf("Deseja jogar novamente?\n");
        printf("1 - SIM\n2 - NAO\n");
        scanf("%d", &x);
    } while (x == 1);
    printf("%s %d X %d Maquina\n", nome, VitoriaJogador, VitoriaMaquina);
    if (empate > 0)
        printf("com um total de %d empate(s)\n", empate);
    puts(" ______________________________________");
    puts("          Obrigado por jogar!          ");
    puts(" ______________________________________");
    return 0;
}