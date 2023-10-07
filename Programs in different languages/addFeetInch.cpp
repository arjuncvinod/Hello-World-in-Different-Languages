//C++ program that adds feet and inches 
#include <iostream>

using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    Distance() : feet(0), inches(0) {}

    void getDistance() {
        cout << "Enter feet: ";
        cin >> feet;
        cout << "Enter inches: ";
        cin >> inches;
    }

    void showDistance() {
        cout << "Feet: " << feet << " Inches: " << inches << endl;
    }

    Distance addDistance(const Distance& d2) {
        Distance result;
        result.feet = feet + d2.feet;
        result.inches = inches + d2.inches;

        if (result.inches >= 12) {
            result.feet += result.inches / 12;
            result.inches = result.inches % 12;
        }

        return result;
    }
};

int main() {
    Distance d1, d2, sum;
    
    cout << "Enter the first distance:\n";
    d1.getDistance();

    cout << "Enter the second distance:\n";
    d2.getDistance();

    sum = d1.addDistance(d2);

    cout << "Sum of distances:\n";
    d1.showDistance();
    cout << "+\n";
    d2.showDistance();
    cout << "=\n";
    sum.showDistance();

    return 0;
}
