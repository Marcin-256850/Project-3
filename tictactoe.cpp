#include "definicje.h"

using namespace std;
using namespace std;

void wyswietlanie(char *plansza, int size) {
    int k;
    int pierwiastek = sqrt(size);

    for (int j = 0; j < pierwiastek; j++) {
        for (int i = 0; i < pierwiastek; i++) {
            if ((i+1) == pierwiastek) break;

        }


        k = pierwiastek*j;
        for (int i = 0; i < pierwiastek; i++) {
            if ((i+1) == pierwiastek) {
                cout << " " << plansza[k] << endl;
                break;
            }
            cout << " " << plansza[k] << " |";
            k++;
        }

        if ((j+1) == pierwiastek) {
            for (int i = 0; i < pierwiastek; i++) {
                if ((i+1) == pierwiastek) {

                    break;
                }

            }
        }
        else {
            for (int i = 0; i < pierwiastek; i++) {
                if ((i+1) == pierwiastek) {
                    cout << "___" << endl;
                    break;
                }
                cout << "___|";
            }
        }
    }
}

void pierwszewyswietlenie(int size) {
    int plansza[size], k;
    int pierwiastek = sqrt(size);
    for (int i = 0; i < size; i++) {
        plansza[i] = i+1;
    }
    for (int j = 0; j < pierwiastek; j++) {
        for (int i = 0; i < pierwiastek; i++) {
            if ((i+1) == pierwiastek) break;

        }


        k = pierwiastek*j;
        for (int i = 0; i < pierwiastek; i++) {
            if ((i+1) == pierwiastek) {
                if (k >= 99) { cout << " " << plansza[k]; }
                else { cout << " " << plansza[k] << endl; }

                break;
            }
            if (k >= 9) {
                if (k >= 99) { cout << " " << plansza[k] << " |"; }
                else { cout << " " << plansza[k] << " |"; }
            }
            else { cout << " " << plansza[k] << " |"; }
            k++;
        }

        if ((j+1) == pierwiastek) {
            for (int i = 0; i < pierwiastek; i++) {
                if ((i+1) == pierwiastek) {

                    break;
                }

            }
        }
        else {
            for (int i = 0; i < pierwiastek; i++) {
                if ((i+1) == pierwiastek) {
                    cout << "___" << endl;
                    break;
                }
                cout << "___|";
            }
        }
    }
}

tictactoe::tictactoe(int size) {
    bool znak = true;
    wielkosc(size);

    char *plansza = new char[size];
    for (int i = 0; i < size; i++) { plansza[i] = ' ';}
    pierwszewyswietlenie(size);

    
        while (znak) {
            tictactoe::ruch(plansza,gracz);
            if (zwyciestwo(plansza,gracz)) { 
                cout << "Wygral gracz\n"; 
                break;
            }
            if(tictactoe::remis(plansza)) {
                cout << "Remis" << endl; 
                break;
            }
            tictactoe::ai(plansza,komputer);
            if (zwyciestwo(plansza,komputer)) { 
                cout << "Wygral komputer\n"; 
                break;
            }
            if(tictactoe::remis(plansza)) { 
                cout << "Remis" << endl; 
                break;
            }
        }
    }



int tictactoe::start() {
    int rozmiar;
    cout << "Podaj rozmiar:";
    cin >> rozmiar;
    rozmiar=rozmiar*rozmiar;
    return rozmiar;
}

void tictactoe::ruch(char *plansza, char x) {
    int v, k = 0;
    string nazwa_tictactoecza;
    bool znak = true;
    
        if (x == 'X') {
        nazwa_tictactoecza = "gracz - X";
        cout << "Ruch " << nazwa_tictactoecza << "\n";
        while(znak) {
            cout << "Podaj kwadrat: ";
            cin >> v;
            if (v > 0 && v <= size) {
                if (plansza[v - 1] == 'X' || plansza[v - 1] == 'O') {
                    cout << "Kwadrat jest zajety \n";
                }
                else {
                    plansza[v - 1] = x;
                    cout << endl;
                    wyswietlanie(plansza, size);
                    znak = false;
                }
            }
            else {
                cout << "Kwadrat poza planszą \n";
                k++;
                if (k == 3) break;
            }
        }
    }

}

void tictactoe::wielkosc(int size) {
    this->size = size;
}


bool tictactoe::zwyciestwo(char *plansza, char x) {
    int licz = 0;
    for (int j = 0; j < size; j += sqrt(size)) {
        for (int i = j; i < sqrt(size) + j; i++) {
            if (plansza[i] == x) {
                licz++;
                if (licz == sqrt(size)) { return true; }
            }
        }
        licz = 0;
    }
    licz = 0;
    for (int j = 0; j < sqrt(size); j++) {
        for (int i = j; i < size; i += sqrt(size)) {
            if (plansza[i] == x) {
                licz++;
                if (licz == sqrt(size)) { return true; }
            }
        }
        licz = 0;
    }
    licz = 0;

    for (int i = 0; i < size; i += sqrt(size)+1) {
        if (plansza[i] == x) {
            licz++;
            if (licz == sqrt(size)) { return true; }
        }
    }
    licz = 0;

    for (int i = sqrt(size)-1; i < (size-sqrt(size)+1); i += sqrt(size)-1) {
        if (plansza[i] == x) {
            licz++;
            if (licz == sqrt(size)) { return true; }
        }
    }
    return false;
}

bool tictactoe::remis(char *plansza) {
    int licz = 0;
    for(int i = 0; i < size; i++) {
        if (plansza[i] == 'X') { licz++; }
        else if (plansza[i] == 'O') { licz++; }
    }
    if (licz == size) { return true; }
    else { return false; }
}


int tictactoe::minimmaksym(char *plansza,int depth) {
    {

        int r;
        int score = 1000;

        for (int i = 0; i < size; i++)
        {
            if (plansza[i] == ' ')
            {
                plansza[i] = komputer;

                int t = maksymalny(plansza,depth,-INFINITY,+INFINITY);
                if (t < score)
                {

                    score = t;
                    r = i;

                }
                plansza[i] = ' ';
            }
        }
        return r;
    }
}

int tictactoe::maksymalny(char *plansza,int depth,int a,int b) {
    int bests=-INFINITY;
    if (zwyciestwo(plansza, gracz)) {
        return 10;
    }
    else if (zwyciestwo(plansza,komputer)) {
        return -10;
    }
    else if (remis(plansza)) {
        return 0;
    }
    if(depth>9)
    {
        return 0;
    }
    int score = -1000;

    for (int i = 0; i < size; i++)
    {
        if (plansza[i] == ' ')
        {

            plansza[i] = gracz;
            score = max(score, minimalny(plansza,depth,a,b));
            depth=depth+1;
            if(bests<score)
            {
                bests=score;
            }
            plansza[i] = ' ';
            if(a<bests)
            {
                a=bests;
            }
            if(a>=b)
            {
                return bests;
            }

        }

    }
    return score;
}

int tictactoe::minimalny(char *plansza,int depth,int a,int b) {
    int bests=+INFINITY;
    if (zwyciestwo(plansza, gracz)) {
        return 10;
    }
    else if (zwyciestwo(plansza,komputer)) {
        return -10;
    }
    else if (remis(plansza)) {
        return 0;
    }
    if(depth>9)
    {
        return 0;
    }

    int score = 1000;

    for (int i = 0; i < size; i++)
    {
        if (plansza[i] == ' ')
        {
            plansza[i] = komputer;
            score = min(score, maksymalny(plansza,depth,a,b));
            depth=depth+1;
            plansza[i] = ' ';
            if(bests>score)
            {
                bests=score;
            }
            plansza[i] = ' ';
            if(b>bests)
            {
                b=bests;
            }
            if(a>=b)
            {
                return bests;
            }

        }
    }
    return score;
}

void tictactoe::ai(char *plansza, char x) {
    plansza[minimmaksym(plansza,0)] = x;
    cout << endl;
    wyswietlanie(plansza, size);
}
int main()
{
    (tictactoe(tictactoe::start()));
}