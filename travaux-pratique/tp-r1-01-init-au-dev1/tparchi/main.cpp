#include <iostream>
using namespace std;

int main()
{
    //input rgb values
    int r, g, b;
    double gray;
    cout << "Enter RGB values: ";
    cin >> hex >> r >> g >> b;
    gray = (int)(0.2125*r + 0.7154*g + 0.0721*b);
    cout << "Gray value: " << gray << endl;

    return 0;
}