#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>
#include "Jogo.h"
#include "vetores.h"
#define COR 8 //cor das letras e menu igual a cinza(COR)sssss
char vet[9][9];
char vetor[2][2];
char d,e,c,b,i0,j0;
int i,j;
char p,q,gming,ltre, ctre,lfou,cfou;
int contador = 0;   //Conta quando se aperta o enter para fazer a troca dos elementos
int size = 0;       //Utilizada como o tamanho do arquivo para salvar os recordes
int k = 4,l = 4;    //k e l são as variaveis para acompanhar a posição do vetor com o cursor
int x=250,y=200;   //x é frenquencia e y é heartz
int leave = 0;
int jogadas[2][2];
int qtdjogadas = 20;
int pontuacao = 0;
coordenadas coords;


void entertroca()
{
    if(gming == 0)
    {
        switch(contador)
        {
        case 0:
            textcolor(green);
            printf("%d",vet[k][l]);
            jogadas[contador][0] = k;
            jogadas[contador] [1] = l;
            contador = 1;
            vetor[0][0] = k;
            vetor[0][1] = l;
            break;
        case 1:
            //direita esquerda cima baixo :  variaveis de correspondencia na matriz

            d = (vetor[0][1]) + 1;
            e = (vetor[0][1]) - 1;
            c = (vetor[0][0]) - 1;
            b = (vetor[0][0]) + 1;
            i0 = vetor[0][0];
            j0 = vetor[0][1];

            if(l == j0 && k == i0)
            {
                //condição para tentar elemento ja na posição anterior
            }
            else if((d == l || l == e) && k == i0)
            {
                textcolor(red);
                printf("%d",vet[k][l]);
                jogadas[contador][0] = k;
                jogadas[contador] [1] = l;
                contador = 2;
                vetor[1][0] = k;
                vetor[1][1] = l;
            }
            else if ((c == k || k == b) && l == j0)
            {
                textcolor(red);
                printf("%d",vet[k][l]);
                jogadas[contador][0] = k;
                jogadas[contador] [1] = l;
                contador = 2;
                vetor[1][0] = k;
                vetor[1][1] = l;
            }

            break;
        default:
            break;
        }
        if(contador == 2 && gming == 0)
        {
            contador = 0;
            textcolor(green);
            analisar();

            qtdjogadas--;
            troca(vet[ jogadas[0][1] ] [ jogadas[0][0] ], vet[ jogadas[1][1] ] [ jogadas[1][0] ] );
        }
    }
}
void textcolor(int j)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), j);
}
void menu()
{
    gming = 1;
    int v[5] = {red,espaco,espaco,espaco,espaco},u[5]= {red,COR,COR,COR,COR},i=0;
    char cursor;
    int w=0;
    size = lerArquivo(recordes);
    system("cls");
    do
    {
        textcolor(COR);

        printf("        _____ _____ _____ ____  __ __    _____ _____ _____ _____ _____ \n");
        printf("       |     |  _  |   | |    \\|  |  |  |     | __  |  |  |   __|  |  |\n");
        printf("       |   --|     | | | |  |  |_   _|  |   --|    -|  |  |__   |     |\n");
        printf("       |_____|__|__|_|___|____/  |_|    |_____|__|__|_____|_____|__|__|\n");

        printf("\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
               CCE,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,CCD);
        printf("\t\t\t%c",BV);
        textcolor(u[0]);
        printf("         %cJogar          ",v[0]);
        textcolor(COR);
        printf("%c\n",BV);
        printf("\t\t\t%c",BV);
        textcolor(u[1]);
        printf("         %cRecordes       ",v[1]);
        textcolor(COR);
        printf("%c\n",BV);
        printf("\t\t\t%c",BV);
        textcolor(u[2]);
        printf("         %cOpcoes         ",v[2]);
        textcolor(COR);
        printf("%c\n",BV);
        printf("\t\t\t%c",BV);
        textcolor(u[3]);
        printf("         %cAjuda          ",v[3]);
        textcolor(COR);
        printf("%c\n",BV);
        printf("\t\t\t%c",BV);
        textcolor(u[4]);
        printf("         %cSair           ",v[4]);
        textcolor(COR);
        printf("%c\n",BV);
        printf("\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
               CBE,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,BH,CBD);
        cursor = getch();
        switch(cursor)
        {
        case 'S':
        case 's':
        case 80:
            v[i] = espaco;
            v[++i] = seta;
            u[w] = COR;
            u[++w] = red;
            som(&x,&y);
            break;
        case 'W':
        case 'w':
        case 72:
            v[i] = espaco;
            v[--i] = seta;
            u[w] = COR;
            u[--w] = red;
            som(&x,&y);
            break;
        case GetEnter:
            if(i==0)
            {
                jogo();
            }

            if(i==1)
            {
                system("cls");
                exibirVetor(size, recordes);
                salvarArquivo(recordes, size);
                system("pause");
            } // ranking
            if(i==2)
            {
                options();
            }
            if(i==3)
            {
                help();
            }
            if(i==4)
            {
                leave = 1;
                exit(0);
            }
            break;
        default:
            break;
        }

        if(i>4&&w>4)
        {
            i = 0;
            v[i] = seta;
            w = 0;
            u[w] = red;
        }
        if(i<0&&w<0)
        {
            i = 4;
            v[i] = seta;
            w = 4;
            u[w] = red;
        }
        system("cls");
    }
    while(leave != 1);
}
void help()
{
    gming = 1;
    int voltar;
    system("cls");
    while(1)
    {
        textcolor(COR);
        printf("\n 1.Selecione a opcao jogar no menu\n\n");
        printf(" 2.Para movimentar-se utilize as teclas w-a-s-d ou as setas direcionais do teclado;\n\n");
        printf(" 3.Ao terminar o seu jogo, adicione seu nome para salvar a pontuacao;\n\n");
        printf(" 4.Selecione opcoes para poder desativar o som;\n\n");
        printf(" 5.Para fechar o jogo, selecione sair.\n\n");
        printf("\n\n Aperte a tecla ENTER para voltar ao menu principal...");
        voltar=getch();
        if(voltar!=GetEnter)
            break;
        menu();
    }

}
void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD)
    {
        x+35,y+11
    });

}
void tabuleiro()
{
    textcolor(red);
    printf("\n\n\n\n\n\t\t\t\t    CANDY CRUSH\n\n");
    printf("\t\t        %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,
           BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC);
    printf("\t\t        %c ",BV);
}
void atualizar()
{
    system("cls");
    tabuleiro();
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            textcolor(branco);
            printf("%d",vet[i][j]);
            textcolor(red);
            printf(" %c ",BV);
            analisar();
        }
        printf("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b%c\n\t\t\t%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
               BV,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC,BH,BH,BH,BC);
        printf("\t\t          ");
    }
    textcolor(red);
    printf("\n\t\tJogadas: %d\t\t\t\tPontuacao: %d",qtdjogadas,pontuacao);
    //menu();
    //qtdjogadas = 20;
}
void movimentacao()
{
    char tecla;
    coords.x = 7;
    coords.y = 5;
    do
    {
        gotoxy(coords.x,coords.y);
        tecla = getch();
        if(gming != 1)
        {
            switch(tecla)
            {
            case 'a':
            case 'A':
            case left:
                coords.x -= 4;
                l--;
                som(&x,&y);
                break;
            case 'd':
            case 'D':
            case right:
                coords.x += 4;
                l++;
                som(&x,&y);
                break;
            case 'w':
            case 'W':
            case up:
                coords.y -= 2;
                k--;
                som(&x,&y);
                break;
            case 's':
            case 'S':
            case down:
                coords.y += 2;
                k++;
                som(&x,&y);
                break;
            case Esc:
                menu();
                continue;
                break;
            case GetEnter:
                entertroca();
                break;
            }
        }
        if(coords.x>26)
            coords.x = 23;
        if(coords.x<-12)
            coords.x = -9;
        if(coords.y>14)
            coords.y = 13;
        if(coords.y<-4)
            coords.y = -3;
        if(k>8)
            k = 8;
        if(k<0)
            k = 0;
        if(l>8)
            l = 8;
        if(l<0)
            l = 0;
    }
    while(1 && qtdjogadas > 0);
}
void jogo()
{
    gming = 0;
    contador = 0;
    qtdjogadas = 20;
    pontuacao = 0;
    k = 4;
    l = 4;
    int auxl;
    int randon;
    char trocar;
    srand(time(NULL));
    system("cls");
    tabuleiro();
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            randon = rand()%8;
            if(randon < 2)
                randon = 2;
            if(randon >= 8)
                randon = 7;
            vet[i][j] = randon;
        }
    }
    atualizar();
    analisar();
    movimentacao();
    if(qtdjogadas == 0)
    {
        gming = 1;
        cadastro();
    }
}
void options()
{
    gming = 1;

    int v[2] = {seta,espaco},i = 0,u[2] = {red,COR},w = 0;
    char cursor;
    system("cls");

    do
    {
        textcolor(COR);
        printf("Deseja jogar com som?\n");
        textcolor(u[0]);
        printf(" %cSim\n",v[0]);

        textcolor(u[1]);
        printf(" %cNao",v[1]);

        cursor = getch();

        switch(cursor)
        {

        case 'w':
        case 'W':
        case 72:
            v[i] = espaco;
            v[--i] = red;
            u[w] = COR;
            u[--w] = red;
            break;
        case 's':
        case 'S':
        case 80:
            v[i] = espaco;
            v[++i] = seta;
            u[w] = COR;
            u[++w] = red;
            break;
        case GetEnter:
            if(i==0)
            {
                x = 1000;
                y = 110;
                som(&x,&y);
                break;
            }
            if(i==1)
            {
                x = 0;
                y = 0;
                som(&x,&y);
                break;
            }
        default:
            break;
        }
        if(i>1&&w>1)
        {
            i = 0;
            v[i] = 16;
            w = 0;
            u[w] = 12;
        }
        if(i<0&&w<0)
        {
            i = 1;
            v[i] = seta;
            w = 1;
            u[w] = red;
        }
        system("cls");

    }
    while(cursor!=GetEnter);
}
void cadastro()
{
    gming = 1;
    char voltar;
    Score player;
    int position;
    printFJ();
    system("cls");
    player = cadastrar(pontuacao);
    position = posicao(pontuacao,recordes);
    adicionarNovoRecorde(player,recordes,size,position);
    size++;
    voltar = getch();

}
void troca()
{
    contador = 0;
    int vetorAux[1][1];
    vetorAux[0][0] =  vet[ vetor[0][0] ][ vetor[0][1] ];
    vet[ vetor[0][0] ][ vetor[0][1] ] = vet[ vetor[1][0] ][ vetor[1][1] ];
    vet[ vetor[1][0] ][ vetor[1][1] ] = vetorAux[0][0];
    atualizar();
    analisar();
    atualizar();
}
void analisar()
{
    char col,line,somc[3],soml[3]; // indices
    for(line = 0; line<9; line++)
    {
        for(col = 0; col<9; col++)
        {
            somc[0] = col + 1;
            somc[1] = somc[0] + 1;
            somc[2] = somc[1] + 1;
            soml[0] = line + 1;
            soml[1] = soml[0] + 1;
            soml[2] = soml[1] + 1;
            if(vet[line][col] == vet[line][somc[0]])
            {
                if(vet[line][col] == vet[line][somc[1]])
                {
                    if(vet[line][col] == vet[line][somc[2]])
                    {
                        lfou = 0;
                    }
                    else
                        ltre = 0;

                }

            }
            else
            {
                ltre = 1;
                lfou = 1;
            }
            if(vet[line][col] == vet[soml[0]][col])
            {
                if(vet[line][col] == vet[soml[1]][col])
                {
                    if(vet[line][col] == vet[soml[2]][col])
                    {
                        cfou = 0;
                    }
                    else
                        ctre = 0;

                }
            }
            else
            {
                ctre = 1;
                cfou = 1;
            }
            if(ltre == 0 || ctre == 0)
            {
                if(ltre == 0 && ctre == 1)
                {
                    vet[line][col] = rand()%8;
                    vet[line][somc[0]] = rand()%8;
                    vet[line][somc[1]] = rand()%8;
                    pontuacao+=10;
                    //eliminar linha
                }
                if(ltre == 1 && ctre == 0)
                {
                    vet[line][col] = rand()%8;
                    vet[soml[0]][col] = rand()%8;
                    vet[soml[1]][col] = rand()%8;
                    pontuacao+=10;
                    //elimina coluna
                }
                if(ltre == 0 && ctre == 0)
                {
                    vet[line][col] = rand()%8;
                    vet[soml[0]][col] = rand()%8;
                    vet[line][somc[0]] = rand()%8;
                    vet[soml[1]][col] = rand()%8;
                    vet[line][somc[1]] = rand()%8;
                    pontuacao+=50;
                    //limina T
                }
            }
            if(lfou == 0 || cfou == 0)
            {
                if (lfou == 0 && cfou == 1)
                {
                    vet[line][col] = rand()%8;
                    vet[line][somc[0]] = rand()%8;
                    vet[line][somc[1]] = rand()%8;
                    vet[line][somc[2]] = rand()%8;
                    pontuacao+=20;
                    //eliminar linha four elements
                }
                if (lfou == 1 && cfou == 0)
                {
                    vet[line][col] = rand()%8;
                    vet[soml[0]][col] = rand()%8;
                    vet[soml[1]][col] = rand()%8;
                    vet[soml[2]][col] = rand()%8;
                    pontuacao+=20;
                    //elimina coluna
                }
                if(lfou == 0 && cfou == 0)
                {
                    vet[line][col] = rand()%8;
                    vet[soml[0]][col] = rand()%8;
                    vet[line][somc[0]] = rand()%8;
                    vet[soml[1]][col] = rand()%8;
                    vet[line][somc[1]] = rand()%8;
                    vet[soml[2]][col] = rand()%8;
                    vet[line][somc[2]] = rand()%8;
                    pontuacao+=90;
                    //elimina T muito improvavel
                }

            }
        }
    }
}
void som(int *X, int *Y)
{
    Beep(*X,*Y);

}

void printFJ()
{
    char a;
    gming = 1;
    system("cls");
    textcolor(COR);
    printf("\n\n\n\n\n\n\n\n");
    printf(" _______  __                   __              __                   \n");
    printf("|    ___||__|.--------.    .--|  |.-----.     |__|.-----..-----..-----. \n");
    printf("|    ___||  ||        |    |  _  ||  -__|     |  ||  _  ||  _  ||  _  |  \n");
    printf("|___|    |__||__|__|__|    |_____||_____|     |  ||_____||___  ||_____|   \n");
    printf("                                             |___|       |_____|            \n");
    printf("\n\n\n\nDigite uma TECLA qualquer para continuar...");
    a = getch();
}
