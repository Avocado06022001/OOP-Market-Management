#include<iostream>
using namespace std;
#include<vector>
class marketSquare{
private:
    int number;
    double area;
    double income;
    string name;
public:
    marketSquare(int number, double area, double income, string name){
        this->number=number;
        this->area=area;
        this->income=income;
        this->name=name;
    }
    void setNumber(int number){this->number=number;}
    void setArea(double area){this->area=area;}
    void setIncome(double income){this->income=income;}
    void setName(string name){this->name=name;}
    int getNumber(){return number;}
    double getArea(){return area;}
    double getIncome(){return income;}
    string getName(){return name;}
    virtual double computeMoney()=0;
    void display(){
        cout<<"Number: "<<number<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Area: "<<area<<endl;
        cout<<"Income: "<<income<<endl;
    }
};

class food: public marketSquare{
private:
    double cool;
public:
    food(int number, double area, double income, double cool, string name):marketSquare(number, area, income, name){
        this->cool=cool;
    }
    void setCood(double cool){this->cool=cool;}
    double getCool(){return cool;}

    double computeMoney(){
        return 40000000*marketSquare::getArea()+marketSquare::getIncome()*0.05+cool;
    }

    void displayInfo(){
        marketSquare::display();
        cout<<"Cool: "<<cool<<endl;
        cout<<"Money: "<<food::computeMoney()<<endl;
    }
};

class clothes:public marketSquare{
public:
    clothes(int number, double area, double income, string name):marketSquare(number, area, income, name){}
    double computeMoney(){
        return 40000000*marketSquare::getArea()+marketSquare::getIncome()*0.1;
    }
    void displayInfo(){
        marketSquare::display();
        cout<<"Money: "<<clothes::computeMoney()<<endl;
    }
};

class accessories:public marketSquare{
public:
    accessories(int number, double area, double income, string name):marketSquare(number, area, income, name){}
    double computeMoney(){
        if (marketSquare::getIncome()<100000){
            return 40000000*marketSquare::getArea()+marketSquare::getIncome()*0.2;
        }
        else{
            return 40000000*marketSquare::getArea()+marketSquare::getIncome()*0.3;
        }
    }
    void displayInfo(){
        marketSquare::display();
        cout<<"Money: "<<accessories::computeMoney()<<endl;
    }
};

class Market{
private:
    vector<marketSquare*>list;
public:
    void addEntity(marketSquare* s){
        list.push_back(s);
    }
    double computeProfit(){
        double sum=0;
        for (int i=0; i<list.size(); i++){
            sum+=list[i]->computeMoney();
        }
        return sum;
    }
    void highest_Profit(){
        int index;
        double max=list[0]->computeMoney();
        for (int i=0; i<list.size(); i++){
            if (list[i]->computeMoney()>max){
                max=list[i]->computeMoney();
                index=i;
            }
        }
        cout<<"The highest profit is from: "<<list[index]->getName();
    }
};

int main(){
    Market m;
    food s1(1,30,2000000,300000, "Avocado");
    clothes s2(2,40,50000000,"Beauty");
    accessories s3(3,100,60000000,"PNJ");
    marketSquare* m1=&s1;
    marketSquare* m2=&s2;
    marketSquare* m3=&s3;
    m.addEntity(m1);
    m.addEntity(m2);
    m.addEntity(m3);
    s1.displayInfo();
    s2.displayInfo();
    s3.displayInfo();
    cout<<m.computeProfit();
    m.highest_Profit();
}

