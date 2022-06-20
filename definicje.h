#ifndef tictactoe_h
#define tictactoe_h
#include <iostream>
#include <cmath>
void wyswietlanie(char *tab, int size);
void pierwszewyswietlenie(int size);

class tictactoe {
public:
    char gracz ='X', komputer = 'O';
    int size;
    bool zwyciestwo(char *tab, char x);
    bool remis(char *tab);
    void wielkosc(int size);
    static int start();
    tictactoe(int size);
    void ruch(char *tab, char x);
    void ai(char *tab, char x);
    int minimmaksym(char *tab,int depth);
    int minimalny(char *tab,int depth,int a,int b);
    int maksymalny(char *tab,int depth,int a,int b);
};
#endif