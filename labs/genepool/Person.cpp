#include "Person.h"

// Person Member Functions
Person::Person(std::string name_, Gender gender_, Person* mother_, Person* father_){
    memName = name_;
    memGender = gender_;
    memMother = mother_;
    memFather = father_;
}

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
    std::set<Person*> bro;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && memMother != nullptr){
        std::set<Person*> temp = memMother->kids;
        std::set<Person*> mSibs;
        // temp.erase(nullptr);
        if (smod == SMod::FULL){
            for (Person* person: temp){
                if (person->memGender == Gender::MALE && person->memName != memName && (person->memMother != nullptr && person->memFather != nullptr)){
                    mSibs.insert(person);
                }
            }
        }
        else {
            for (Person* person: temp){
                if (person->memGender == Gender::MALE && person->memName != memName){
                    mSibs.insert(person);
                }
            }
        }
        if (smod == SMod::FULL){
            for (Person* person: mSibs){
                if (person->memMother == memMother && person->memFather == memFather){
                    bro.insert(person);
                }
            }
        }
        if (smod == SMod::HALF){
            for (Person* person: mSibs){
                if ((person->memMother == memMother && person->memFather != memFather) || (person->memMother != memMother && person->memFather == memFather)){
                    bro.insert(person);
                }
            }
        }
        if (smod == SMod::ANY){
            for (Person* person: mSibs){
                bro.insert(person);
            }
        }
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && memFather != nullptr){
        std::set<Person*> temp = memFather->kids;
        std::set<Person*> pSibs;
        // temp.erase(nullptr);
        if (smod == SMod::FULL){
            for (Person* person: temp){
                if (person->memGender == Gender::MALE && person->memName != memName && (person->memMother != nullptr && person->memFather != nullptr)){
                    pSibs.insert(person);
                }
            }
        }
        else {
            for (Person* person: temp){
                if (person->memGender == Gender::MALE && person->memName != memName){
                    pSibs.insert(person);
                }
            }
        }
        if (smod == SMod::FULL){
            for (Person* person: pSibs){
                if (person->memMother == memMother && person->memFather == memFather){
                    bro.insert(person);
                }
            }
        }
        if (smod == SMod::HALF){
            for (Person* person: pSibs){
                if ((person->memMother == memMother && person->memFather != memFather) || (person->memMother != memMother && person->memFather == memFather)){
                    bro.insert(person);
                }
            }
        }
        if (smod == SMod::ANY){
            for (Person* person: pSibs){
                bro.insert(person);
            }
        }
    }

    return bro;
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
    std::set<Person*> grandf;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY){
        if (memMother !=  nullptr && memMother->memFather != nullptr){
            grandf.insert(memMother->father());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY){
        if (memFather != nullptr && memFather->memFather != nullptr){
            grandf.insert(memFather->father());
        }
    }

    return grandf;
}

std::set<Person*> Person::grandmothers(PMod pmod){
    std::set<Person*> grandm;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY){
        if (memMother !=  nullptr && memMother->memMother != nullptr){
            grandm.insert(memMother->mother());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY){
        if (memFather != nullptr && memFather->memMother != nullptr){
            grandm.insert(memFather->mother());
        }
    }
    
    return grandm;
}

std::set<Person*> Person::grandparents(PMod pmod){
    std::set<Person*> grandp;
    std::set<Person*> grandm = grandmothers(pmod);
    std::set<Person*> grandf = grandfathers(pmod);

    grandp.insert(grandm.begin(), grandm.end());
    grandp.insert(grandf.begin(), grandf.end());

    return grandp;
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
    std::set<Person*> parent;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY){
        if (mother() != nullptr){
            parent.insert(mother());
        }
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY){
        if (father() != nullptr){
            parent.insert(father());
        }
    }

    return parent;
}

std::set<Person*> Person::siblings(PMod pmod, SMod smod){
    std::set<Person*> sibs;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && memMother != nullptr){
        std::set<Person*> temp = memMother->kids;
        std::set<Person*> mSibs;
        // temp.erase(nullptr);
        if (smod == SMod::FULL){
            for (Person* person: temp){
                if (person->memName != memName && (person->memMother != nullptr && person->memFather != nullptr)){
                    mSibs.insert(person);
                }
            }
        }
        else {
            for (Person* person: temp){
                if (person->memName != memName){
                    mSibs.insert(person);
                }
            }
        }
        if (smod == SMod::FULL){
            for (Person* person: mSibs){
                if (person->memMother == memMother && person->memFather == memFather){
                    sibs.insert(person);
                }
            }
        }
        if (smod == SMod::HALF){
            for (Person* person: mSibs){
                if ((person->memMother == memMother && person->memFather != memFather) || (person->memMother != memMother && person->memFather == memFather)){
                    sibs.insert(person);
                }
            }
        }
        if (smod == SMod::ANY){
            for (Person* person: mSibs){
                sibs.insert(person);
            }
        }
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && memFather != nullptr){
        std::set<Person*> temp = memFather->kids;
        std::set<Person*> pSibs;
        // temp.erase(nullptr);
        if (smod == SMod::FULL){
            for (Person* person: temp){
                if (person->memName != memName && (person->memMother != nullptr && person->memFather != nullptr)){
                    pSibs.insert(person);
                }
            }
        }
        else {
            for (Person* person: temp){
                if (person->memName != memName){
                    pSibs.insert(person);
                }
            }
        }
        if (smod == SMod::FULL){
            for (Person* person: pSibs){
                if (person->memMother == memMother && person->memFather == memFather){
                    sibs.insert(person);
                }
            }
        }
        if (smod == SMod::HALF){
            for (Person* person: pSibs){
                if ((person->memMother == memMother && person->memFather != memFather) || (person->memMother != memMother && person->memFather == memFather)){
                    sibs.insert(person);
                }
            }
        }
        if (smod == SMod::ANY){
            for (Person* person: pSibs){
                sibs.insert(person);
            }
        }
    }

    return sibs;
}

std::set<Person*> Person::sisters(PMod pmod, SMod smod){
    std::set<Person*> sis;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && memMother != nullptr){
        std::set<Person*> temp = memMother->kids;
        std::set<Person*> mSibs;
        // temp.erase(nullptr);
        if (smod == SMod::FULL){
            for (Person* person: temp){
                if (person->memGender == Gender::FEMALE && person->memName != memName && (person->memMother != nullptr && person->memFather != nullptr)){
                    mSibs.insert(person);
                }
            }
        }
        else {
            for (Person* person: temp){
                if (person->memGender == Gender::FEMALE && person->memName != memName){
                    mSibs.insert(person);
                }
            }
        }
        if (smod == SMod::FULL){
            for (Person* person: mSibs){
                if (person->memMother == memMother && person->memFather == memFather){
                    sis.insert(person);
                }
            }
        }
        if (smod == SMod::HALF){
            for (Person* person: mSibs){
                if ((person->memMother == memMother && person->memFather != memFather) || (person->memMother != memMother && person->memFather == memFather)){
                    sis.insert(person);
                }
            }
        }
        if (smod == SMod::ANY){
            for (Person* person: mSibs){
                sis.insert(person);
            }
        }
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && memFather != nullptr){
        std::set<Person*> temp = memFather->kids;
        std::set<Person*> pSibs;
        // temp.erase(nullptr);
        if (smod == SMod::FULL){
            for (Person* person: temp){
                if (person->memGender == Gender::FEMALE && person->memName != memName && (person->memMother != nullptr && person->memFather != nullptr)){
                    pSibs.insert(person);
                }
            }
        }
        else {
            for (Person* person: temp){
                if (person->memGender == Gender::FEMALE && person->memName != memName){
                    pSibs.insert(person);
                }
            }
        }
        if (smod == SMod::FULL){
            for (Person* person: pSibs){
                if (person->memMother == memMother && person->memFather == memFather){
                    sis.insert(person);
                }
            }
        }
        if (smod == SMod::HALF){
            for (Person* person: pSibs){
                if ((person->memMother == memMother && person->memFather != memFather) || (person->memMother != memMother && person->memFather == memFather)){
                    sis.insert(person);
                }
            }
        }
        if (smod == SMod::ANY){
            for (Person* person: pSibs){
                sis.insert(person);
            }
        }
    }

    return sis;
}

std::set<Person*> Person::sons(){
    return kids;
}

std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    return kids;
}