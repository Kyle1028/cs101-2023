#include <iostream>

using namespace std;
class Car {
private:
  string m_brand;
  int m_year;

public:
  Car(string brand, int year) {
    m_brand = brand;
    m_year = year;
  }

  string getBrand() {
    return m_brand;
  }

  int getYear() {
    return m_year;
  }
};

class BMWCar : public Car {
private:
  string m_driveMode;

public:
  BMWCar(string brand, int year, string driveMode) : Car(brand, year) {
    m_driveMode = driveMode;
  }

  string getDriveMode() {
    return m_driveMode;
  }
};

class AudiCar : public Car {
private:
  string m_driveMode;

public:
  AudiCar(string brand, int year, string driveMode) : Car(brand, year) {
    m_driveMode = driveMode;
  }

  string getDriveMode() {
    return m_driveMode;
  }
};

class BenzCar : public Car {
private:
  string m_driveMode;

public:
  BenzCar(string brand, int year, string driveMode) : Car(brand, year) {
    m_driveMode = driveMode;
  }

  string getDriveMode() {
    return m_driveMode;
  }
};

int main() {
  BMWCar car("BMW", 2023, "Rear-wheel");
  AudiCar audi("Audi", 2023, "Front-wheel");
  BenzCar benz("Benz", 2023, "Front-wheel");

  cout << "Constructing BMW_Car" << endl;
  cout << car.getBrand() << " : Drive Mode = " << car.getDriveMode() << endl;


  cout << "Constructing Audi_Car" << endl;
  cout << audi.getBrand() << " : Drive Mode = " << audi.getDriveMode() << endl;


  cout << "Constructing Benz_Car" << endl;
  cout << benz.getBrand() << " : Drive Mode = " << benz.getDriveMode() << endl;

  return 0;
}
