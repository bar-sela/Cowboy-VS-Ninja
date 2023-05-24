#include "Point.hpp"


int main(){
Point p1{1, 1};
Point p2{2, 3};
Point n1{-1, 1};
Point n2{1, -9};
Point n3{-1, -1};




double distance = p1.distance(p2);
double half_p = distance / 2;
double third_p = distance / 3;

cout << "third_p :" + to_string(third_p*2) << endl ;
Point p3{Point::moveTowards(p1, p2, half_p)};
cout << (p3.distance(p2)) << endl ;

Point p4{Point::moveTowards(p1, p2, third_p)};
cout << (p4.distance(p2))<<endl ;

// There is no such a thing as negative distance
//CHECK_THROWS_AS(Point::moveTowards(p1, p2, -1),std::invalid_argument);
}

