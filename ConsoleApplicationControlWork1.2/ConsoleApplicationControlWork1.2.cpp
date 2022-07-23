#include <iostream>
#include <string>

using namespace std;

unsigned int NCD(unsigned int a, unsigned int b) {

    if (a == b)
        return a;
    if (a > b)
        return NCD(a - b, b);
    return NCD(a, b - a);
}
unsigned int NCK(unsigned int a, unsigned int b)
{

    return (a * b) / NCD(a, b);

}

class Fraction {
private:
    int num0 = 0;
    int num1, num2;
public:
    Fraction() {
        cout << "write your fraction (3 4 is like a 3 / 4):\n";
        cin >> num1;
        cin >> num2;
        cout << endl;
        cout << "Your fraction is " << num1 << " / " << num2 << endl;
    }
    Fraction(int num1, int num2) {

        this->num1 = num1;
        this->num2 = num2;


        cout << "Your fraction is " << num1 << " / " << num2 << endl;
    }

    void change() {
        if (this->num1 > this->num2) {
            while (this->num1 >= this->num2) {
                this->num1 -= this->num2;
                this->num0++;
            }
        }
        else
        {
            int buf = NCD(this->num1, this->num2);
            this->num1 /= buf;
            this->num2 /= buf;
        }
    }

    static void compare(Fraction obj1, Fraction obj2) {
        obj1.change();
        obj2.change();
        if (double(obj1.num1) / double(obj1.num2) == double(obj2.num1) / double(obj2.num2) && obj1.num0 == obj2.num0) {
            cout << obj1.num0
                << " " << obj1.num1
                << "/" << obj1.num2
                << " == " << obj2.num0
                << " " << obj2.num1
                << "/" << obj2.num2 << endl;
        }
        if (obj1.num0 > obj2.num0 || double(obj1.num1) / double(obj1.num2) > double(obj2.num1) / double(obj2.num2)) {
            cout << obj1.num0
                << " "
                << obj1.num1
                << "/" << obj1.num2
                << " > " << obj2.num0
                << " " << obj2.num1
                << "/" << obj2.num2 << endl;
        }
        if (obj1.num0 < obj2.num0 || double(obj1.num1) / double(obj1.num2) < double(obj2.num1) / double(obj2.num2)) {
            cout << obj1.num0
                << " " << obj1.num1
                << "/" << obj1.num2
                << " < " << obj2.num0
                << " " << obj2.num1
                << "/" << obj2.num2 << endl;
        }
    }
};



int main()
{
    Fraction a(8, 6);
    Fraction b(3, 6);
    Fraction::compare(a, b);
}