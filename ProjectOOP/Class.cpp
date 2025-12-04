#include "Class.h"

// Дефолтный конструктор
Address::Address() : city_(""), street_(""), houseNumber_(""), apartmentNumber_("") {}

// Пользовательский конструктор
Address::Address(const std::string& city, const std::string& street,
    const std::string& houseNumber, const std::string& apartmentNumber)
    : city_(city), street_(street), houseNumber_(houseNumber), apartmentNumber_(apartmentNumber) {
}

void Address::setCity(const std::string& value) {
    city_ = value;
}

void Address::setStreet(const std::string& value) {
    street_ = value;
}

void Address::setHouseNumber(const std::string& value) {
    houseNumber_ = value;
}

void Address::setApartmentNumber(const std::string& value) {
    apartmentNumber_ = value;
}

std::string Address::toString() const {
    return city_ + ", " + street_ + ", " + houseNumber_ + ", " + apartmentNumber_;
}