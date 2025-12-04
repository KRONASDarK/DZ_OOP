#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>

class Address {
public:
    Address();
    Address(const std::string& city, const std::string& street,
        const std::string& houseNumber, const std::string& apartmentNumber);

    void setCity(const std::string& value);
    void setStreet(const std::string& value);
    void setHouseNumber(const std::string& value);
    void setApartmentNumber(const std::string& value);

    std::string toString() const;

private:
    std::string city_;
    std::string street_;
    std::string houseNumber_;
    std::string apartmentNumber_;
};

#endif // ADDRESS_H