#include <iostream>

float Addition(float a, float b)
{
    return a + b;
}

float Subtraction(float a, float b)
{
    return a - b;
}

float Multiplication(float a, float b)
{
    return a * b;
}

float Division(float a, float b)
{
    return a / b;
}

int main() {
    typedef float (*lpfnOperation)(float, float);

    lpfnOperation vpf[4] = { &Addition, &Subtraction, &Multiplication, &Division };
    float a, b, c;
    int opt;

    std::cout << "enter the operands" << std::endl;
    std::cin >> a >> b;
    std::cout << "enter the operation 0-Addition, 1-Subtraction, 2-Multiplication, 3-Division" << std::endl;
    std::cin >> opt;
   
    c = (*vpf[opt])(a, b);
    std::cout << "Resultado: " << c << std::endl;

    return 0;
}
