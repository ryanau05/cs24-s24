#include "GenePool.h"

// GenePool Member Functions
GenePool::GenePool(std::istream& stream){
    std::string line;

    while (std::getline(stream, line)){
        if (!isalpha(line[0])){
            continue;
        }
        std::string name;
        std::string gender;
        Gender gender_;
        std::string mother;
        std::string father;

        std::istringstream iss(line);
        std::getline(iss, name, '\t');
        std::getline(iss, gender, '\t');
        std::getline(iss, mother, '\t');
        std::getline(iss, father, '\t');

        if (gender == "male"){
            gender_ = Gender::MALE;
        }
        else if (gender == "female"){
            gender_ = Gender::FEMALE;
        }
        else {
            gender_ = Gender::ANY;
        }

        Person* mom = nullptr;
        if (mother != "???"){
            mom = find(mother);
            if (!mom) {
                mom = new Person(mother, Gender::FEMALE, nullptr, nullptr);
                genepool[mother] = mom;
                database.insert(mom);
            }
        }

        Person* dad = nullptr;
        if (father != "???"){
            dad = find(father);
            if (!dad) {
                dad = new Person(father, Gender::MALE, nullptr, nullptr);
                genepool[father] = dad;
                database.insert(dad);
            }
        }

        Person* person = find(name);
        if (!person) {
            if (mother == "???" && father == "???"){
                person = new Person(name, gender_, nullptr, nullptr);
            }
            else if (mother != "???" && father == "???"){
                person = new Person(name, gender_, mom, nullptr);
            }
            else if (mother == "???" && father != "???"){
                person = new Person(name, gender_, nullptr, dad);
            }
            else {
                person = new Person(name, gender_, mom, dad);
            }
            genepool[name] = person;
            database.insert(person);
        }

        if (mother != "???"){
            (mom->kids).insert(person);
        }
        if (father != "???"){
            (dad->kids).insert(person);
        }
    }
}

GenePool::~GenePool(){
}

std::set<Person*> GenePool::everyone() const{
    return database;
}

Person* GenePool::find(const std::string& name) const{
    auto found = genepool.find(name);
    if (found != genepool.end()){
        return found->second;
    }
    else {
        return nullptr;
    }
}