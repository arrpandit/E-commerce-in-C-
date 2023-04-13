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
    string productlist;
    cout << "Available Product " << endl;
    for (auto product : allProducts)
    {
        productlist.append(product.getDisplayName());
    } 

    cout<<productlist<<endl;
    cout<<"-------------"<<endl;
    string choice;
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

int main()
{
    char action;
    while (true)
    {
        cout << "select an action - (a)add item , (v)view item (c) checkout" << endl;
        cin >> action;
        if (action == 'a')
        {
            Product *product  = chooseProduct();
            if(product!=NULL){
                cout<<"Added to the cart "<<product->getDisplayName()<<endl;

            }
        }
        else if (action == 'v')
        {
        }
        else
        {
        }
        /* code */
    }

    // Product p(1,"apple",20);
    // cout<<p.getDisplayName()<<endl;

    // Item fruit(p,3);
    // cout<<fruit.getIteminfo();

    return 0;
}