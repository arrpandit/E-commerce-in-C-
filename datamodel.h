#include"bits/stdc++.h"
using namespace std;
class Item;
class cart;
class Product{
    int id;
    string name;
    int price;
    public:
    Product(int u_id,string name,int price)
    {
        id=u_id;
        this->name = name;
        this->price = price;
    }
    string getDisplayName(){
        return name + " : Rs " + to_string(price) + "\n";
    }

    friend class Item;

};
class Item{
    const Product product;
    int quility;
    public:
    Item(Product p ,int q): product(p),quility(q){
    }

    int getItemPrice(){
        return quility* product.price;
    }

    

};
class Cart{

};