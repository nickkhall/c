#include <iostream>
using namespace std;

struct Coords
{
    int x {0};
    int y {0};
};

void increment(int *x, int x_amount, int *y, int y_amount)
{
    *x = (*x) + x_amount;
    *y = (*y) + (y_amount + 1);
}

int main()
{
    Coords coords;
    int counter {1};

    cout << "beginning x: " << coords.x << endl;
    cout << "beginning y: " << coords.y << endl;
    cout << "-----" << endl;

    increment(&coords.x, counter, &coords.y, counter);

    cout << "ending x: " << coords.x << endl;
    cout << "ending y: " << coords.y << endl;

    return 0;
}
