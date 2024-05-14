#include "Person.h"

// Person Member Functions
Person::Person(std::string name_, Gender gender_, Person* mother_, Person* father_){
    memName = name_;
    memGender = gender_;
    memMother = mother_;
    memFather = father_;
}

#include "Person.h"

// Person Member Functions
const std::string& Person::name() const{
    return memName;
}
Gender Person::gender() const{
    return Gender::ANY;
}
Person* Person::mother(){
    return memMother;
}
Person* Person::father(){
    return memFather;
}

std::set<Person*> Person::ancestors(PMod pmod){
    return kids;
}

std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    return kids;
}

std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    return kids;
}

std::set<Person*> Person::children(){
    return kids;
}

std::set<Person*> Person::cousins(PMod pmod, SMod smod){
    return kids;
}

std::set<Person*> Person::daughters(){
    return kids;
}

std::set<Person*> Person::descendants(){
    return kids;
}

std::set<Person*> Person::grandchildren(){
    return kids;
}

std::set<Person*> Person::granddaughters(){
    return kids;
}

std::set<Person*> Person::grandfathers(PMod pmod){
    return kids;
}

std::set<Person*> Person::grandmothers(PMod pmod){
    return kids;
}

std::set<Person*> Person::grandparents(PMod pmod){
    return kids;
}

std::set<Person*> Person::grandsons(){
    return kids;
}

std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    return kids;
}

std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    return kids;
}

std::set<Person*> Person::parents(PMod pmod){
    return kids;
}

std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    return kids;
}

std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    return kids;
}

std::set<Person*> Person::sons(){
    return kids;
}

std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    return kids;
}