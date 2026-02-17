// BinToDec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <regex>
#include <math.h>

int main(int argc, char* args[])
{
    const unsigned int nMaxBinDigits = static_cast<unsigned int>(floor(log2(UINT32_MAX)));
    const std::regex oRegEx("^[0-1]+$");
    unsigned int nBinPower = 1;
    unsigned int nBinNum = 0;
    std::string strLine;
    system("cls");
    std::cout << "Input a binary number\r\n";
    std::getline(std::cin, strLine);
    int nStrLen = strLine.length();
    bool bIsRightString = (nStrLen <= nMaxBinDigits ) && (std::regex_match(strLine, oRegEx));
    if (!bIsRightString)
    {
        std::cout << "Wrong binary number format!!!\r\n";
        std::cin.get();
        return 0;
    }
    for (int i = 0; i < nStrLen; i++)
    {
        unsigned int nBinDigit = strLine[nStrLen - 1 - i] - '0';
        nBinNum += (nBinDigit * nBinPower);
        nBinPower *= 2;
    }
    std::cout << "The decenary equavalent of the binary number "
        << strLine << " is: " << nBinNum << "\r\n";
    std::cin.get();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
