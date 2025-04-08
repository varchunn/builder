#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string name;
    string body;
    int enginePower;
    int wheelRadius;
    int gearCount;
    string transmission;

public:
    void setName(const string& n) { name = n; }
    void setBody(const string& b) { body = b; }
    void setEnginePower(int hp) { enginePower = hp; }
    void setWheelRadius(int r) { wheelRadius = r; }
    void setGearCount(int g) { gearCount = g; }
    void setTransmission(const string& t) { transmission = t; }

    void show() const {
        cout << "---- " << name << " ----" << endl;
        cout << "Корпус: " << body << endl;
        cout << "Двигатель (л.с): " << enginePower << endl;
        cout << "Колеса (R): " << wheelRadius << endl;
        cout << "Количество передач: " << gearCount << endl;
        cout << "КПП: " << transmission << endl << endl;
    }
};

class CarBuilder {
public:
    virtual ~CarBuilder() {}
    virtual void createCar() = 0;
    virtual void buildName() = 0;
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual void buildGears() = 0;
    virtual void buildTransmission() = 0;
    virtual Car* getCar() = 0;
};

class DaewooLanosBuilder : public CarBuilder {
private:
    Car* car;
public:
    void createCar() override { car = new Car(); }
    void buildName() override { car->setName("Daewoo Lanos"); }
    void buildBody() override { car->setBody("Седан"); }
    void buildEngine() override { car->setEnginePower(98); }
    void buildWheels() override { car->setWheelRadius(13); }
    void buildGears() override { car->setGearCount(5); }
    void buildTransmission() override { car->setTransmission("Manual"); }
    Car* getCar() override { return car; }
};

class FordProbeBuilder : public CarBuilder {
private:
    Car* car;
public:
    void createCar() override { car = new Car(); }
    void buildName() override { car->setName("Ford Probe"); }
    void buildBody() override { car->setBody("Купе"); }
    void buildEngine() override { car->setEnginePower(160); }
    void buildWheels() override { car->setWheelRadius(14); }
    void buildGears() override { car->setGearCount(4); }
    void buildTransmission() override { car->setTransmission("Auto"); }
    Car* getCar() override { return car; }
};

class UAZPatriotBuilder : public CarBuilder {
private:
    Car* car;
public:
    void createCar() override { car = new Car(); }
    void buildName() override { car->setName("UAZ Patriot"); }
    void buildBody() override { car->setBody("Универсал"); }
    void buildEngine() override { car->setEnginePower(120); }
    void buildWheels() override { car->setWheelRadius(16); }
    void buildGears() override { car->setGearCount(4); }
    void buildTransmission() override { car->setTransmission("Manual"); }
    Car* getCar() override { return car; }
};

class HyundaiGetzBuilder : public CarBuilder {
private:
    Car* car;
public:
    void createCar() override { car = new Car(); }
    void buildName() override { car->setName("Hyundai Getz"); }
    void buildBody() override { car->setBody("Хетчбэк"); }
    void buildEngine() override { car->setEnginePower(66); }
    void buildWheels() override { car->setWheelRadius(13); }
    void buildGears() override { car->setGearCount(4); }
    void buildTransmission() override { car->setTransmission("Auto"); }
    Car* getCar() override { return car; }
};

class Shop {
private:
    CarBuilder* builder;
public:
    void setBuilder(CarBuilder* b) { builder = b; }

    Car* buildCar() {
        builder->createCar();
        builder->buildName();
        builder->buildBody();
        builder->buildEngine();
        builder->buildWheels();
        builder->buildGears();
        builder->buildTransmission();
        return builder->getCar();
    }
};

int main() {
    Shop shop;

    DaewooLanosBuilder lanos;
    FordProbeBuilder probe;
    UAZPatriotBuilder uaz;
    HyundaiGetzBuilder getz;

    Car* car1 = nullptr;
    Car* car2 = nullptr;
    Car* car3 = nullptr;
    Car* car4 = nullptr;

    shop.setBuilder(&lanos);
    car1 = shop.buildCar();
    car1->show();

    shop.setBuilder(&probe);
    car2 = shop.buildCar();
    car2->show();

    shop.setBuilder(&uaz);
    car3 = shop.buildCar();
    car3->show();

    shop.setBuilder(&getz);
    car4 = shop.buildCar();
    car4->show();

    delete car1;
    delete car2;
    delete car3;
    delete car4;

    return 0;
}
