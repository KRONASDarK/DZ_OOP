#include <iostream>
#include <fstream>
#include <vector>
#include "Class.h"

int main() {
    std::ifstream input("in.txt");      // Открываем входной файл
    std::ofstream output("out.txt");   // Открываем выходной файл

    // Читаем количество адресов
    size_t numAddresses;
    input >> numAddresses;
    input.ignore(); // Пропускаем символ перевода строки

    std::vector<Address> addresses; // Теперь не инициализируем заранее

    // Читаем адреса и создаем объекты класса Address
    for (size_t i = 0; i < numAddresses; ++i) {
        std::string city, street, houseNumber, apartmentNumber;
        getline(input, city);       // Город
        getline(input, street);     // Улица
        getline(input, houseNumber);// Номер дома
        getline(input, apartmentNumber); // Номер квартиры

        // Добавляем новый объект Address с переданными аргументами
        addresses.push_back(Address(city, street, houseNumber, apartmentNumber));
    }

    // Остальная логика остается прежней...

    // Выведем количество адресов
    output << numAddresses << '\n';

    // Выводим адреса в обратном порядке
    for (int i = static_cast<int>(numAddresses) - 1; i >= 0; --i) {
        output << addresses[i].toString() << '\n'; // Получаем строку адреса
    }

    return 0;
}
