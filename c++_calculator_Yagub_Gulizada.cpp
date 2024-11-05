#include <iostream>
using namespace std;

void convertCoordinates(double xM, double yM, double &xG, double &yG) {

    xG = ((xM + 20) / 40) * 200;
     yG = 100 - ((yM + 20) / 40) * 100;
}

int main() {

    double xM, yM, xG, yG;


    cout << "Enter the Mx coordinate in the first system: ";
    cin >> xM;
    cout << "Enter the My coordinate in the first system: ";
    cin >> yM;


    convertCoordinates(xM, yM, xG, yG);


    cout << "Converted coordinates: (" << xG << ", " << yG << ")\n";
    return 0;
}
