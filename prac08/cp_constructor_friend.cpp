#include <iostream>
using namespace std;

class Power {
    int kick, punch;
public:
    Power(int k = 0, int p = 0) : kick{k}, punch{p} {}
    Power(const Power& cp) : kick{cp.kick}, punch{cp.punch} {}
    void show() { cout << kick << ", " << punch << endl; } 
    friend Power operator+(const Power&, const Power&);
};

Power operator+(const Power& op1, const Power& op2) {
    Power new_obj;
    new_obj.kick = op1.kick + op2.kick;
    new_obj.punch = op1.punch + op2.punch;
    return new_obj;
}

int main() {

    int kick, punch;

    cout << "enter the power of kick & punch -> ";
    cin >> kick >> punch;

    Power p1(kick, punch);
    Power p2 = p1;
    Power p3 = p1 + p2;

    p1.show();
    p2.show();
    p3.show();

    return 0;
}