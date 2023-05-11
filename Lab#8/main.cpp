#include <iostream>

using namespace std;
class Fueltank{
    private:
    int m_FueltankCapacity;
    int m_Gas_grade;
    public:
    Fueltank(int FueltankCapacity=3000, int Gas=98){
        m_FueltankCapacity=FueltankCapacity;
        m_Gas_grade=Gas;
    }
    int fuel_up(int v,int gas){
        if(v>3000){
            cout<<"Error: FueltankCapacity: "<<m_FueltankCapacity<<endl;
        }else if(gas!=m_Gas_grade){
            cout<<"Error: Correct Gas_grade: "<<m_Gas_grade<<endl;
        }
        return 0;
    }
    int set_gas_grade(int Gas_grade){
        m_Gas_grade=Gas_grade;
        return Gas_grade;
    }
    int get_gas_grade(){
        return m_Gas_grade;
    }
};

class Car{
    private:
    int m_price;
    Fueltank m_fueltank;
    
    public:
    string m_brand;
    string m_model;
    int m_year;
    int m_seat;
    Car(string x,string y,int z,int s){
        m_brand=x;
        m_model=y;
        m_year=z;
        m_seat=s;
        m_price=10000;
    }
    int get_MaxSeat(){
        return m_seat;
    }
    int get_price(){
        return m_price*m_seat;
    }
    int fuel_up(int v,int gas){
        return m_fueltank.fuel_up(v,gas);
    }
    int set_gas_grade(int Gas_grade){
        return m_fueltank.set_gas_grade(Gas_grade);
    }
    int get_gas_grade(){
        return m_fueltank.get_gas_grade();
    }
};

class BMW_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    BMW_Car(string y,int z,int s):Car("BMW",y,z,s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode = "Rear_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class Audi_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    Audi_Car(string y,int z,int s):Car("Audi",y,z,s){
        cout<<"Constructing Audi_Car\n";
        m_DriveMode = "Front_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

class Benz_Car : public Car{
    private:
    string m_DriveMode;
    
    public:
    Benz_Car(string y,int z,int s):Car("Benz",y,z,s){
        cout<<"Constructing BMW_Car\n";
        m_DriveMode = "Front_wheel";
    }
    string get_DriveMode(){
        return m_DriveMode;
    }
};

int main(){
    BMW_Car car_1("X5",2023,6);
    cout<<car_1.m_brand<<":Gas grade = "<<car_1.get_gas_grade()<<endl;
    car_1.set_gas_grade(95);
    cout<<car_1.m_brand<<":Gas grade = "<<car_1.get_gas_grade()<<endl;
    car_1.fuel_up(300,95);
}
