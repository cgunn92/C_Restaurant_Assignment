#ifndef RESTAURANT_H
#define RESTAURANT_H

struct Restaurant {
   char restaurantName[101];        
   char foodType[101];
   double rating;
};
//data members

void SetValues(Restaurant &aRest, char newName[101], char newFood[101], double newRating);
void PrintValues(Restaurant aRest);

#endif