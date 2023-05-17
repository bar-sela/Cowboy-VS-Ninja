#include "doctest.h"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Team.hpp"
#include "sources/Team2.hpp"
#include "iostream"
#include <string>
#include <sstream>

int foundFirstIndexOfCowboy(Character* arr[10]){
    int ans = 0 ;
    for(int i = 0 ; i < 10 ; i++){
        if(typeid(arr[i]).name() == typeid(Cowboy).name()) {
            ans = i;
            break;
        }

    }
    return ans ;
}
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
    Ninja *arr[3];
    YoungNinja y{"Leo Messi", p};
    OldNinja y2{"Leo Messi", p};
    YoungNinja y3{"Leo Messi", p};
    CHECK(y.getLives() == 100);
    CHECK(y2.getLives() == 120);
    CHECK(y3.getLives() == 150);
    arr[0] = &y;
    arr[1] = &y2;
    arr[2] = &y3;
    int disPerMove[3] = {14, 8, 12};
    for (int i = 0; i < 3; i++) {
        CHECK(arr[i]->getName() == "Leo Messi");
        CHECK(arr[i]->getLocation().equals(arr[i]->getLocation()));
        MOVEandSLASH_cheak(arr[0], disPerMove[i]);
    }
};
TEST_CASE("Team 1 : ") {
    /// prepering the varables which requires for the tests
    Cowboy leader{"john Terry ", Point(1, 1)};
    Team t(&leader);
    Character *cur = NULL;
    for (int i = 0; i < 10; i++) {
        if (i % 4 == 0)
            cur = new YoungNinja("N" + to_string(i), Point(i + 1, i + 1));
        else if (i % 4 == 1)
            cur = new TrainedNinja("N" + to_string(i), Point(i + 1, i + 1));
        else if (i % 4 == 2)
            cur = new OldNinja("N" + to_string(i), Point(i + 1, i + 1));
        else
            cur = new Cowboy("C" + to_string(i), Point(i + 1, i + 1));
        t.add(cur);
    };



    /// only 10 allows
    CHECK_THROWS(t.add(cur));
    /// CHEACK Order IN TEAM 1
    int firstCowboyIndex = t.foundFirstIndexOfCowboy();
    CHECK(firstCowboyIndex ==7); /// there are only 3 cowboys and 7 Ninjas, so by order the first cowboy is in 7th index


    /// prepering second team of type team2
    YoungNinja leader2{"Wayne Roony", Point(1.1, 0.9)};
    Team2 team2(&leader2);
    string s[3 ] ={"a","b","c"};
    //// itilize second Team of type Team2
    Cowboy cowboy = Cowboy("d",Point(10,10) ) ;
    t.add(&cowboy);
    for(int i = 0 ; i < 2 ; i ++) {
        Cowboy cowboy = Cowboy("d",Point(10,10) ) ;
        t.add(&cowboy);
    }

    /// The order of addition without distinction of cowboys or ninjas
    CHECK(team2.foundFirstIndexOfCowboy() == 0 ) ;


    t.attack(&team2);
    //// the leader of the first team is the closest from team2 to the leader of the second team and therefor attack him
    //// but only one ninja and 3 coboys hit Wayne ronny WHICH is a YoungNinja
    CHECK(t.stillAlive() == 10);
    CHECK(leader.getLives() ==  100 - (3*10 + 40));

    /// cheak that bullet are -10 from cowboys :
    for(unsigned  long i = 1 ; i < 10 ; i++ ) {
        Character *cur = t.getChARCTERinIndex(i);

        if (typeid(cur).name() == typeid(cowboy).name()) {
            Cowboy *c = dynamic_cast<Cowboy *>(cur);
            CHECK(c->hasbooltes() == 5) ;
        }
        ////cheak that the location of each Ninja (exept one - who slashed) got closer according to its speed
        bool b = false ; bool b2 = false ;
        if (typeid(cur).name() != typeid(Cowboy).name()) {
            double lastDisForEachNinjaFromVictem = 45.17059236 ;
            if(cur->getLocation().distance(leader.getLocation()) == lastDisForEachNinjaFromVictem - 14)
                 b = true;
            CHECK(b == true);
        }




    }


}










