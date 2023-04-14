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
    Product(){

    }
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
    friend class Cart;

};
class Item{
    Product product;
    int quility;
    public:
    Item(){}
    Item(Product p ,int q): product(p),quility(q) //construction using initialize list
    {
    }

    int getItemPrice(){
        return quility* product.price;
    }

    string getIteminfo(){
        return to_string(quility) + " * " + product.name + " Rs : " + to_string(quility * product.price);
    }

    friend class Cart;

    

};
class Cart{
    unordered_map<int,Item>items;

    public:
    void addProduct(Product product){
        if(items.count(product.id)==0){
            Item newItem(product,1);
            items[product.id]=newItem;
        }else{
            items[product.id].quility+=1;
        }
    }

    int getTotal(){
        int total =0;
        for(auto itempair : items){
            auto item=itempair.second;
            total+=item.getItemPrice();
        }

        return total;

    }

    string viewcart(){
        string itemized_List;
        int cart_total=0;
        if(items.empty()){
            return "Cart is Empty";
        }else{
            cart_total=getTotal();
        }
        for(auto itempair : items){
            auto item=itempair.second;
            itemized_List.append(item.getIteminfo());
        }

        return itemized_List + "\n Total Amount : Rs. " + to_string(cart_total) + '\n';
    }

    bool isEmpty(){
        return items.empty();
    }


};
