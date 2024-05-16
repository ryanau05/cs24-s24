#include "Person.h"
#include <iostream>

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
    std::set<Person*> ancestors_;
    if (pmod == PMod::MATERNAL || pmod == PMod::ANY){
        ancestorsHelper(memMother, ancestors_);
    }
    if (pmod == PMod::PATERNAL || pmod == PMod::ANY){
        ancestorsHelper(memFather, ancestors_);
    }
    return ancestors_;
}

void Person::ancestorsHelper(Person* person, std::set<Person*>& ancestors_){
    if (person != nullptr) {
        ancestors_.insert(person);
        ancestorsHelper(person->memMother, ancestors_);
        ancestorsHelper(person->memFather, ancestors_);
    }
}

std::set<Person*> Person::aunts(PMod pmod, SMod smod){
    std::set<Person*> aunts_;
    std::set<Person*> mAunts;
    std::set<Person*> pAunts;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && memMother != nullptr){
        mAunts = memMother->sisters(PMod::ANY, smod);
        aunts_.insert(mAunts.begin(), mAunts.end());
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && memFather != nullptr){
        pAunts = memFather->sisters(PMod::ANY, smod);
        aunts_.insert(pAunts.begin(), pAunts.end());
    }

    return aunts_;
}

std::set<Person*> Person::brothers(PMod pmod, SMod smod){
    std::set<Person*> bro;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && memMother != nullptr){
        std::set<Person*> temp = memMother->kids;
        std::set<Person*> mSibs;
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
    std::set<Person*> daughters_;
    for (Person* person: kids){
        if (person->memGender == Gender::FEMALE){
            daughters_.insert(person);
        }
    }

    return daughters_;
}

std::set<Person*> Person::descendants(){
    std::set<Person*> descendants;
    descendantsHelper(kids, descendants);
    return descendants;
}

void Person::descendantsHelper(const std::set<Person*>& kids, std::set<Person*>& descendants){
    for (Person* kid : kids) {
        descendants.insert(kid);
        descendantsHelper(kid->kids, descendants);
    }
}

std::set<Person*> Person::grandchildren(){
    std::set<Person*> grandkids;
    std::set<Person*> grandd = granddaughters();
    std::set<Person*> grands = grandsons();
    grandkids.insert(grandd.begin(), grandd.end());
    grandkids.insert(grands.begin(), grands.end());

    return grandkids;
}

std::set<Person*> Person::granddaughters(){
    std::set<Person*> grandd;
    for (Person* person: kids){
        for (Person* subP: person->kids){
            if (subP->memGender == Gender::FEMALE){
                grandd.insert(subP);
            }
        }
    }

    return grandd;
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
    std::set<Person*> grands;
    for (Person* person: kids){
        for (Person* subP: person->kids){
            if (subP->memGender == Gender::MALE){
                grands.insert(subP);
            }
        }
    }

    return grands;
}

std::set<Person*> Person::nephews(PMod pmod, SMod smod){
    std::set<Person*> nephews_;
    std::set<Person*> sibs = siblings(pmod, smod);

    for (Person* person: sibs){
        std::set<Person*> tempNephews = person->children();
        for (Person* tempKid: tempNephews){
            if (tempKid->memGender == Gender::MALE){
                nephews_.insert(tempKid);
            }
        }
    }

    return nephews_;
}

std::set<Person*> Person::nieces(PMod pmod, SMod smod){
    std::set<Person*> nieces_;
    std::set<Person*> sibs = siblings(pmod, smod);

    for (Person* person: sibs){
        std::set<Person*> tempNieces = person->children();
        for (Person* tempKid: tempNieces){
            if (tempKid->memGender == Gender::FEMALE){
                nieces_.insert(tempKid);
            }
        }
    }

    return nieces_;
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
    std::set<Person*> sons_;
    for (Person* person: kids){
        if (person->memGender == Gender::MALE){
            sons_.insert(person);
        }
    }

    return sons_;
}

std::set<Person*> Person::uncles(PMod pmod, SMod smod){
    std::set<Person*> uncles_;
    std::set<Person*> mUncles;
    std::set<Person*> pUncles;
    if ((pmod == PMod::MATERNAL || pmod == PMod::ANY) && memMother != nullptr){
        mUncles = memMother->brothers(PMod::ANY, smod);
        uncles_.insert(mUncles.begin(), mUncles.end());
    }
    if ((pmod == PMod::PATERNAL || pmod == PMod::ANY) && memFather != nullptr){
        pUncles = memFather->brothers(PMod::ANY, smod);
        uncles_.insert(pUncles.begin(), pUncles.end());
    }

    return uncles_;
}