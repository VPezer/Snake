#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <exception>

using namespace std;

class HitTheWallEx : public std::exception {
public:
    const char* what() const noexcept override {
        return "Sudar sa zidom!";
    }
};

class SelfCollisionEx : public std::exception {
public:
    const char* what() const noexcept override {
        return "Sudar sa sobom!";
    }
};

class Pixel {
protected:
    char chr;
public:
    Pixel(char c = ' ') : chr(c) {}
    virtual char printChar() const { return chr; }
    virtual ~Pixel() {}
};

class WallPx : public Pixel {
public:
    WallPx() : Pixel('#') {}
};

class SnakePx : public Pixel {
public:
    SnakePx() : Pixel('o') {}
};

class HeadPx : public Pixel {
public:
    HeadPx() : Pixel('O') {}
};

class FoodPx : public Pixel {
public:
    FoodPx() : Pixel('*') {}
};

class SnakeGame {
private:
    const int sirina = 20;
    const int visina = 20;
    bool gameOver;
    pair<int, int> glava;
    vector<pair<int, int>> tijelo;
    int dulj;
    pair<int, int> hrana;   
    int rez;
    enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN } dir;

public:
    SnakeGame() : gameOver(false), dulj(0), rez(0), dir(STOP) {}

    void Setup() {
        gameOver = false;
        dir = STOP;
        glava = { sirina / 2, visina / 2 };
        hrana = { rand() % sirina, rand() % visina };
        rez = 0;
        tijelo.clear();
        dulj = 0;
    }

    void Draw() {
        system("cls");

        WallPx zid;
        for (int i = 0; i < sirina + 2; i++) cout << zid.printChar();
        cout << endl;

        for (int i = 0; i < visina; i++) {
            for (int j = 0; j < sirina; j++) {
                if (j == 0) cout << zid.printChar();

                if (i == glava.second && j == glava.first) {
                    HeadPx snakeHead;
                    cout << snakeHead.printChar();
                }
                else if (i == hrana.second && j == hrana.first) {
                    FoodPx foodPixel;
                    cout << foodPixel.printChar();
                }
                else {
                    bool isTail = false;
                    for (const auto& segment : tijelo) {
                        if (segment.first == j && segment.second == i) {
                            SnakePx snakeBody;
                            cout << snakeBody.printChar();
                            isTail = true;
                            break;
                        }
                    }
                    if (!isTail) {
                        cout << " ";
                    }
                }

                if (j == sirina - 1) cout << zid.printChar();
            }
            cout << endl;
        }

        for (int i = 0; i < sirina + 2; i++) cout << zid.printChar();
        cout << endl;

        cout << "Rezultat: " << rez << endl;
    }

    void Input() {
        if (_kbhit()) {
            switch (_getch()) {
            case 'a': dir = LEFT; break;
            case 'd': dir = RIGHT; break;
            case 'w': dir = UP; break;
            case 's': dir = DOWN; break;
            case 'x': gameOver = true; break;
            }
        }
    }

    void Logic() {
        if (!tijelo.empty()) {
            tijelo.insert(tijelo.begin(), glava);
            if (tijelo.size() > dulj) {
                tijelo.pop_back();
            }
        }

        switch (dir) {
        case LEFT: glava.first--; break;
        case RIGHT: glava.first++; break;
        case UP: glava.second--; break;
        case DOWN: glava.second++; break;
        default: break;
        }

        if (glava.first < 0 || glava.first >= sirina || glava.second < 0 || glava.second >= visina) {
            throw HitTheWallEx();
        }

        for (const auto& segment : tijelo) {
            if (segment == glava) {
                throw SelfCollisionEx();
            }
        }

        if (glava == hrana) {
            rez += 10;
            dulj++;

            if (tijelo.empty()) {
                tijelo.push_back(glava);
            }
            else {
                tijelo.push_back(tijelo.back());
            }
            hrana = { rand() % sirina, rand() % visina };
        }
    }

    void Run() {
        Setup();
        while (!gameOver) {
            try {
                Draw();
                Input();
                Logic();
                Sleep(200); 
            }
            catch (const HitTheWallEx& e) {
                gameOver = true;
                cout << e.what() << endl;
            }
            catch (const SelfCollisionEx& e) {
                gameOver = true;
                cout << e.what() << endl;
            }
        }
        cout << "Kraj igre!" << endl;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));
    SnakeGame game;
    game.Run();
    system("pause");
    return 0;
}