#include<iostream>
#include<cstring>
#include <iomanip>
#include "restaurant.h"
using namespace std;

void SetValues(Restaurant& aRest, char newName[], char newFood[], double newRating){
   strcpy(aRest.restaurantName, newName);
   strcpy(aRest.foodType, newFood);
   aRest.rating = newRating;
}

void PrintValues(Restaurant aRest){
   cout << fixed << showpoint << setprecision(1);
   cout << "Restaurant Name: " << aRest.restaurantName << endl;
   cout << "Food Type: " << aRest.foodType << endl;
   cout << "Restaurant Rating: " << aRest.rating << endl;
}