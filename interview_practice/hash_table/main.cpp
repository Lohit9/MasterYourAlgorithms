#include <iostream>
#include <string>
#include "hash.h"
#include <cstdlib>
using namespace std;

int main(int argc, char **argv){

   hashclass Hashy;

  //Hashy.printTable();

  Hashy.AddItem("Paul", "Locha");
 Hashy.AddItem("Kim", "Iced Mocha");
 Hashy.AddItem("Emma", "Strawberry Smoothie");
 Hashy.AddItem("Annie", "Hot Chocolate");
 Hashy.AddItem("Sarah", "Passion Tea");
 Hashy.AddItem("Pepper", "Caramel Mocha");
 Hashy.AddItem("Mike", "Chai Tea");
 Hashy.AddItem("Steve", "Apple Cider");
 Hashy.AddItem("Bill", "Root Beer");
 Hashy.AddItem("Marie", "Skinny Latte");
 Hashy.AddItem("Susan", "Water");
 Hashy.AddItem("Joe","Green Tea");


Hashy.printTable();
Hashy.printItemsInIndex(9);
   return 0;

}
