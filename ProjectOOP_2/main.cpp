#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> // Подключаем алгоритм sort
#include "Class.h"

bool compareByCity(const Address& a, const Address& b) {
    std::string city_a = a.toString().substr(0, a.toString().find(',')); // Берём первое слово (до запятой)
    std::string city_b = b.toString().substr(0, b.toString().find(',')); // То же самое для другого адреса
    return city_a < city_b;
}

int main() {
    std::ifstream input("in.txt");      // Открываем входной файл
    std::ofstream output("out.txt");   // Открываем выходной файл

    // Читаем количество адресов
    size_t numAddresses;
    input >> numAddresses;
    input.ignore(); // Пропускаем символ перевода строки

    std::vector<Address> addresses; // Здесь храним наши адреса

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

    // Сортируем адреса по городу
    std::sort(addresses.begin(), addresses.end(), compareByCity);

    // Остальное оставляем без изменений
    output << numAddresses << '\n';

    // Выводим адреса в прямом порядке
    for (const auto& addr : addresses) {
        output << addr.toString() << '\n';
    }

    return 0;
}