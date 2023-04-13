#include"bits/stdc++.h"
#include<string>
using namespace std;
class Item;
class cart;
class Product{
    int id;
    string name;
    int price;
    public:
    Product(int u_id,string name,int price) //constructor using Assignment list
    {
        id=u_id;
        this->name = name;
        this->price = price;
    }
    string getDisplayName(){
        return name + " : Rs " + to_string(price) + "\n";
    }

    string getShortName()
    {
        return name.substr(0,1);
    }

    friend class Item;

};
class Item{
    const Product product;
    int quility;
    public:
    Item(Product p ,int q): product(p),quility(q) //construction using initialize list
    {
    }

    int getItemPrice(){
        return quility* product.price;
    }

    string getIteminfo(){
        return to_string(quility) + " * " + product.name + " Rs : " + to_string(quility * product.price);
    }

    

};
class Cart{

};
