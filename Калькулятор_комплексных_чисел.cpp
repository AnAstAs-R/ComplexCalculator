#include <iostream>
#include <cmath>

using namespace std;

class ComplexNumbers {
private:
    double Re;
    double Im;
public:
    ComplexNumbers(double x, double y) : Re(x), Im(y) {}
    ComplexNumbers() : Re(1), Im(1) {}
    ~ComplexNumbers() {}
    void setComplexNumber(double x, double y)
    {
        x = Re;
        y = Im;
    }
    double getRe(double& x)
    {
        return Re;
    }
    double getIm(double& y)
    {
        return Im;
    }

    ComplexNumbers operator+(ComplexNumbers object);
    ComplexNumbers operator-(ComplexNumbers object);
    ComplexNumbers operator*(ComplexNumbers object);
    ComplexNumbers operator/(ComplexNumbers object);
    ComplexNumbers operator++();
    ComplexNumbers operator--();
    ComplexNumbers operator++(int notused);
    ComplexNumbers operator--(int notused);
    ComplexNumbers operator=(ComplexNumbers object);
    ComplexNumbers operator!();

    friend ostream& operator<<(ostream& out, const ComplexNumbers& object);
    friend ComplexNumbers operator+(ComplexNumbers object, double a);
    friend ComplexNumbers operator+(double a, ComplexNumbers object);
    friend ComplexNumbers operator-(ComplexNumbers object, double a);
    friend ComplexNumbers operator-(double a, ComplexNumbers object);
};

ComplexNumbers ComplexNumbers::operator+(ComplexNumbers object)
{
    ComplexNumbers temp;
    temp.Re = object.Re + Re;
    temp.Im = object.Im + Im;
    return temp;
}

ComplexNumbers ComplexNumbers::operator-(ComplexNumbers object)
{
    ComplexNumbers temp;
    temp.Re = Re - object.Re;
    temp.Im = Im - object.Im;
    return temp;
}

ComplexNumbers ComplexNumbers::operator*(ComplexNumbers object)
{
    ComplexNumbers temp;
    temp.Re = Re * object.Re - Im * object.Im;
    temp.Im = Re * object.Im + object.Re * Im;
    return temp;
}

ComplexNumbers ComplexNumbers::operator/(ComplexNumbers object)
{
    ComplexNumbers temp;
    temp.Re = (Re * object.Re + Im * object.Im) / (object.Re * object.Re + object.Im * object.Im);
    temp.Im = (object.Re * Im - Re * object.Im) / (object.Re * object.Re + object.Im * object.Im);
    return temp;
}

ComplexNumbers ComplexNumbers:: operator++()
{
    Re++;
    return *this;
}

ComplexNumbers ComplexNumbers:: operator--()
{
    Im--;
    return *this;
}

ComplexNumbers ComplexNumbers:: operator++(int notused)
{
    Re++;
    return *this;
}

ComplexNumbers ComplexNumbers:: operator--(int notused)
{
    Im--;
    return *this;
}

ComplexNumbers ComplexNumbers::operator=(ComplexNumbers object)
{
    Re = object.Re++;
    Im = object.Im--;
    return *this;
}

ComplexNumbers ComplexNumbers:: operator!()
{
    Re = Re;
    Im = -Im;
    return *this;
}

ComplexNumbers operator+(ComplexNumbers object, double a)
{
    return ComplexNumbers(object.Re + a, object.Im);
}

ComplexNumbers operator+(double a, ComplexNumbers object)
{
    return ComplexNumbers(a + object.Re, object.Im);
}

ComplexNumbers operator-(ComplexNumbers object, double a)
{
    return ComplexNumbers(object.Re - a, object.Im);
}

ComplexNumbers operator-(double a, ComplexNumbers object)
{
    return ComplexNumbers(a - object.Re, -object.Im);
}

ostream& operator<<(ostream& out, const ComplexNumbers& object)
{
    if (object.Im >= 0)
    {
        out << object.Re << '+' << object.Im << 'i'; 
    }
    else
    {
        out << object.Re << object.Im << 'i'; 
    }
    return out; 
}

void displayVybor()
{
    cout << "Выберете действие: " << endl << "1.Сложение " << endl << "2.Вычитание " << endl << "3.Умножение " << endl << "4.Деление " << endl << "5.Вычислить комплексно-сопряженное " << endl << "5.Завершить работу " << endl;
}


int main()
{
    setlocale(LC_ALL, "rus");
    system("chcp 1251");

    ComplexNumbers complex1;
    ComplexNumbers complex2(1, 2);
    ComplexNumbers complex3(3, -2);
    ComplexNumbers complex4;

    cout << '(' << complex1 << ")+(" << complex2 << ")=" << complex1 + complex2 << endl;
    cout << '(' << complex3 << ")-(" << complex1 << ")=" << complex3 - complex1 << endl;
    cout << '(' << complex1 << ")*(" << complex2 << ")=" << complex1 * complex2 << endl;
    cout << '(' << complex1 << ")/(" << complex2 << ")=" << complex1 / complex2 << endl;

    double number = 5.5;

    cout << '(' << complex1 << ")+" << number << '=' << complex1 + number << endl;
    cout << number << '+' << '(' << complex1 << ")=" << number + complex1 << endl;
    cout << '(' << complex1 << ")-" << number << '=' << complex1 - number << endl;
    cout << number << '-' << '(' << complex1 << ")=" << number - complex1 << endl;

    cout << "Перфиксный инкремент ++ (Re+1) комплексного числа " << complex1 << " = ";
    cout << ++complex1 << endl;
    cout << "Постперфиксный инкремент ++ (Re+1) комплексного числа " << complex1 << " = ";
    cout << complex1++ << endl;
    cout << "Перфиксный декремент -- (Im-1) комплексного числа " << complex1 << " = ";
    cout << --complex1 << endl;
    cout << "Постперфиксный декремент -- (Im-1) комплексного числа " << complex1 << " = ";
    cout << complex1-- << endl;

    cout << "Присваиваем значение комплексного числа " << complex3 << " комплексному числу " << complex4 << " (Re+1,Im-1): ";
    complex4 = complex3;
    cout << complex4 << endl;
    cout << "Комплексно-сопряженное число к числу " << complex4 << ": ";
    cout << !complex4 << endl;

    return 0;
}