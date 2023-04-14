#include "bits/stdc++.h"
#include "datamodel.h"

vector<Product> allProducts = {
    Product(1, "apple", 26),
    Product(2, "mango", 30),
    Product(3, "guava", 40),
    Product(4, "lichi", 40),
    Product(5, "cocunet", 50),
    Product(6, "watermellon", 60)};

using namespace std;

Product* chooseProduct()
{
	
	//Display list of products
    string productlist;
    cout << "Available Product " << endl;
    for (auto product : allProducts)
    {
        productlist.append(product.getDisplayName());
    } 

    cout<<productlist<<endl;
    cout<<"-------------"<<endl;
    string choice;  //which fruit want to cadd
    cin>>choice;

    for(int i=0;i<allProducts.size();i++)
    {
        if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not found "<<endl;
    return NULL;
}

bool checkout(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }

    int total = cart.getTotal();
    cout<<"Pay in case"<<endl;
    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"change "<<paid-total <<endl;
        cout<<"thank you for shopping!"<<endl;
        return true;
    }else{
        cout<<"Not enough case"<<endl;
        return false;
    }
}

int main()
{
    char action;
    Cart cart;
    while (true)
    {
        cout << "select an action - (a)add item , (v)view item (c) checkout" << endl;
        cin >> action;
        if (action == 'a')
        {
            Product *product  = chooseProduct();
            if(product!=NULL){
                cout<<"Added to the cart "<<product->getDisplayName()<<endl;
                cart.addProduct(*product);

            }
        }
        else if (action == 'v')
        {
            cout<<"----------------"<<endl;
            cout<<cart.viewcart()<<endl;
            cout<<"-----------------"<<endl;
        }
        else
        {
            cart.viewcart();
            if(checkout(cart)){
                break;
            }

        }
        
    }

    return 0;
}
