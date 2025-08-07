//
// Created by dell on 2025/7/29.
//

#ifndef REFLECTION_PERSON_H
#define REFLECTION_PERSON_H
#include<string>
#include <iostream>

class Person{
public:

    Person(int age, const std::string &name) : age(age), name(name)
    {}

    void test(){
        std::cout<<"Age is "<<GetAge()<<std::endl;
    }

    int GetAge(){return age;}
    int age;


    std::string name;
};

#endif //REFLECTION_PERSON_H
