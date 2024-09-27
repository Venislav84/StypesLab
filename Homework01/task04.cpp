#include <iostream>
#include <algorithm>

int main(){

    double num1, num2, num3;
    std::cin >> num1;
    std::cin >> num2;
    std::cin >> num3;

    double maxNuber = std::max({num1, num2, num3});

    std::cout << "Max number is: " << maxNuber << std::endl;
    return 0;
}



// Пояснение
// С команада в терминала g++ task04.cpp -o findMax, компилираме програмата
// след това я извикваме и записваме числата в нея от numbers.txt с помощта на редирекшън оператор "<" ./findMax < numbers.txt
// не е дадено по условие но в случай, че искаме можем да запишем резултата в отделен файл, 
// пак с редирекшън оператор ./findMax < numbers.txt > outputResult.txt