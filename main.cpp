/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp" //no need for other includes
#include "sources/SmartTeam.hpp"

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    OldNinja *kioshi = new OldNinja("kioshi", Point(3,1));
    OldNinja *kioshi2 = new OldNinja("kioshi", Point(4,1));
    SmartTeam smartTeam(tom);
    smartTeam.add(sushi);
    smartTeam.add(kioshi);
    smartTeam.add(kioshi2);
    Cowboy *to = new Cowboy("Tom", a);
    OldNinja *sush = new OldNinja("sushi", b);
    OldNinja *kiosh = new OldNinja("kioshi", Point(3,1));
    OldNinja *kiosh2 = new OldNinja("kioshi", Point(4,1));
    Team team(to);
    team.add(sush);
    team.add(kiosh);
    team.add(kiosh2);
    while (smartTeam.stillAlive() && team.stillAlive()){
        team.attack(&smartTeam);
        smartTeam.attack(&team);
    }




}