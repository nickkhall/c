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
    Coords coordsOne;
    Coords coordsTwo;
    int counter {1};

    cout << "beginning x: " << coordsOne.x << endl;
    cout << "beginning y: " << coordsOne.y << endl;
    cout << "-----" << endl;

    increment(&coordsOne.x, counter, &coordsOne.y, counter);

    cout << "ending x: " << coordsOne.x << endl;
    cout << "ending y: " << coordsOne.y << endl;

    cout << "-----" << endl;
    cout << "beginning x: " << coordsTwo.x << endl;
    cout << "beginning y: " << coordsTwo.y << endl;

    return 0;
}
