#include "doctest.h"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.h"
#include "sources/TrainedNinja.h"
#include "sources/OldNinja.h"
#include "iostream"
#include <string>
#include <sstream>

bool readFromStdoutAndCompare(Character* C , string s ){
    /// https://www.enseignement.polytechnique.fr/informatique/INF478/docs/Cpp/en/cpp/io/basic_ios/rdbuf.html
    std::ostringstream local;
    auto cout_buff = std::cout.rdbuf(); // save pointer to std::cout buffer
    std::cout.rdbuf(local.rdbuf()); // substitute internal std::cout buffer with
    C->print();
    std::cout.rdbuf(cout_buff);
    return local.str() ==s;
}

void MOVEandSLASH_cheak(Ninja* y , int distancePassedByMove) {
    ///*** move & slash
    /// CASE 1 : NOT INSIDE 14 meters range
    Point p2{15, 15};
    Cowboy cowboy{"Cristiano Ronaldo", p2};
    y->move(&cowboy);
    CHECK(cowboy.getLocation().distance(y->getLocation()) == sqrt(500) - distancePassedByMove);
    CHECK(cowboy.getLives() == 110);
    /// CASE 2 : INSIDE 14 meters range
    YoungNinja e{"Eden Hazard", y->getLocation()};
    e.move(y);
    CHECK(y->getLocation().equals(e.getLocation()));
    e.slash(y);
    CHECK(y->getLives()== y->GetLivesStart() - 40 );
}

TEST_CASE("Point"){
   Point a ;
   Point b(10.3,9.5); Point b2(10.3,9.5);
   ///equals
   CHECK(b.equals(b2)); CHECK_FALSE(b.equals(a));
   Point c(10,9.3); Point d(9,8);
   Point & p  =(Point::moveTowards(a,b,30));
   /// moveTowards
   CHECK(p.equals(c));
   CHECK_THROWS((Point::moveTowards(a,b,5)));  /// all points - the distance between them to a is greater then 5
   CHECK_THROWS(Point::moveTowards(a, b, -1.5 ));
}
//// Befure Battele !
TEST_CASE("cowboy") {
    Point p{225, 225};
    Cowboy cowboy{"Cristiano Ronaldo", p};
    CHECK(cowboy.getName() == "Cristiano Ronaldo");
    CHECK(cowboy.hasbooltes() == 6);
    CHECK(cowboy.getLocation().equals(p));
    CHECK(cowboy.getLives() == 110);
    CHECK(readFromStdoutAndCompare(&cowboy, "Cristiano Ronaldo,110,(225,225)"));
    Cowboy cowboy2{"LeoMessi", p};
    for (int i = 0; i < 6; i++) {
        CHECK(cowboy.hasbooltes() == true);
        cowboy.shoot(&cowboy2);
        CHECK(cowboy2.getLives() == 110 - i * 10);
        CHECK(cowboy.GetNumOfBullets() == 6 - i);
    }
    cowboy.reload();
    CHECK(cowboy.hasbooltes() == false);
    CHECK(cowboy.GetNumOfBullets() == 6 );
}
TEST_CASE("All types Of Ninja cheaks") {
    Point p{1, 1};
    Ninja* arr[3] ;
    YoungNinja y{"Leo Messi", p};    oldNinja y2{"Leo Messi", p};    YoungNinja y3{"Leo Messi", p};
    CHECK(y.getLives() == 100);     CHECK(y2.getLives() == 120);    CHECK(y3.getLives() == 150);
    arr[0] = &y ;arr[1] = &y2 ;arr[2] = &y3 ;
    int disPerMove[3] = {14,8,12} ;
    for(int i = 0 ; i < 3 ; i ++){
        CHECK(arr[i]->getName() == "Leo Messi");
        CHECK(arr[i]->getLocation().equals(arr[i]->getLocation()));
        MOVEandSLASH_cheak(arr[0], disPerMove[i]);
}






}