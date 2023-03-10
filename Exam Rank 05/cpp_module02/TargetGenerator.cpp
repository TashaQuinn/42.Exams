#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {

    std::map<std::string, ATarget *>::iterator it_begin = arr.begin();
    std::map<std::string, ATarget *>::iterator it_end = arr.end();

    while (it_begin != it_end) {
        delete it_begin->second;
        ++it_begin;
    }

    arr.clear();

}

void TargetGenerator::learnTargetType(ATarget *atarget_ptr) {

    if (atarget_ptr)
        arr.insert(std::pair<std::string, ATarget *>(atarget_ptr->getType(), atarget_ptr->clone()));

}

void TargetGenerator::forgetTargetType(std::string const &target) {

    std::map<std::string, ATarget *>::iterator it = arr.find(target);

    if (it != arr.end())
        delete it->second;

    arr.erase(target);

}

ATarget* TargetGenerator::createTarget(std::string const &target) {

    std::map<std::string, ATarget *>::iterator it = arr.find(target);

    if (it != arr.end())
        return arr[target];

    return NULL;

}