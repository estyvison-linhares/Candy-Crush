#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#define Name_Size 40
#define BV 186  //Barra Vertical do menu
#define BH 205 //Barra Horizontal do menu
#define BC 206 // Barra cruz do menu
#define CCD 187
#define CBD 188
#define CBE 200
#define CCE 201
#define GetEnter 13
#define Esc 27
#define left 75
#define right 77
#define up 72
#define down 80
#define espaco 32
#define seta 16
#define red 12
#define green 10
#define branco 15


void textcolor(int j);
void menu();
void help();
void gotoxy(int x,int y);
void tabuleiro();
void analisar();
void atualizar();
void jogo();
void sair();
void som(int *x,int *y);
void cadastro();
void options();
void printFJ();

typedef struct coordenadas
{
    int x;
    int y;
} coordenadas;
typedef struct{
    char nome[25];
    int pontos;
}Record;

#endif // MENU_H_INCLUDED
