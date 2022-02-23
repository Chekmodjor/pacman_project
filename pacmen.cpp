#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void printMaze(char[][12], int, int);  //prototype

//функция получает аргументы масив и точки начала пути
void mazeTraverse(char maze[][12], int coordX, int coordY)
{

    for (int i = 0; i < 100000000; i++); //хоть какая то задержка
    printMaze(maze, coordX, coordY);
    cout << "\n\n";


    if (coordX == 11 || coordY == 11 || coordX == 0)
        return;

    if (maze[coordX + 1][coordY] == '.')
        mazeTraverse(maze, coordX + 1, coordY);
    else if (maze[coordX][coordY + 1] == '.')
        mazeTraverse(maze, coordX, coordY + 1);
    else if (maze[coordX - 1][coordY] == '.')
        mazeTraverse(maze, coordX - 1, coordY);
    else if (maze[coordX][coordY - 1] == '.')
        mazeTraverse(maze, coordX, coordY - 1);


}

//функция выводящая лабиринт на экран
//потом ввести параметр для масштабируемости
void printMaze(char maze[][12], int posX, int posY)
{


    for (int row = 0; row < 12; row++)
    {
        for (int column = 0; column < 12; column++)
        {
            if (row == posX && column == posY)
                cout << "X";
            else
                cout << maze[row][column];
        }

        cout << "\n";
    }
}

//функция генерирующая случайны лабиринт
//начальные точки задаются случайно вызывающей функцией
//изначально будет вызывать чтобы случайно сделать вход
void mazeGenerator(char maze[][12], int coordX, int coordY)
{

    maze[coordX][coordY] = '.';

    if (coordX + 1 < 12 && coordY + 1 < 12 && coordX - 1 >= 0)
    {

        int varOfMove = rand() % 2;

        if (varOfMove == 1 && coordX + 1 != '.')
            mazeGenerator(maze, coordX + 1, coordY);
        else if (varOfMove == 0 && coordY + 1 != '.')
            mazeGenerator(maze, coordX, coordY + 1);
    }
    else
        return;
}

void mazeGenerator2(char maze[][12], int coordX, int coordY)
{
    //логика в том, что из нашей текущей точки
    //рисуются четыре линии случайной длины от 2 до 5 клеток
    //тут же будет проверка границ
    int drawPointForward = 2 + rand() % 4;
    int drawPointBack = 2 + rand() % 4;
    int drawPointUp = 2 + rand() % 4;
    int drawPointDown = 2 + rand() % 4;

    if ((drawPointForward + coordY) < 11)
    {
        for (int i = 0; i < drawPointForward; i++)
            maze[coordX][coordY + i] = '.';

        mazeGenerator2(maze, coordX, coordY + drawPointForward);
    }

    if ((coordY - drawPointBack) >= 0)
    {
        for (int i = 0; i < drawPointBack; i++)
            maze[coordX][coordY - i] = '.';

    }

    if ((coordX - drawPointUp) >= 0)
    {
        for (int i = 0; i < drawPointUp; i++)
            maze[coordX - i][coordY] = '.';

        mazeGenerator2(maze, coordX - drawPointUp, coordY);
    }

    if ((coordX + drawPointDown) < 11)
    {
        for (int i = 0; i < drawPointDown; i++)
            maze[coordX + i][coordY] = '.';


    }


}

int main()
{

    srand(time(0));
    char arrayMaze[12][12];


    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            arrayMaze[i][j] = '#';  //заполняем весь массив "стенками"
        }
    }

    mazeGenerator2(arrayMaze, 1 + rand() % 10, 0);

    int start;
    for (start = 0; start < 12; start++)
    {
        if (arrayMaze[start][0] == '.')
            break;
    }

    printMaze(arrayMaze, start, 0);

    return 0;
}