#include "tracer.h"

#include <iostream>

unsigned int Tracer::mNestingLevel = 0;
std::string Tracer::mNestingPrefix = "   ";
const char* Tracer::mEntryMarker = "-->";
const char* Tracer::mExitMarker = "<--";

Tracer::Tracer(std::string name) :
    mFixed{false},
    mName{std::move(name)}
{
    print(std::cout << mEntryMarker);
}

Tracer::Tracer(const char* name) :
    Tracer{std::string{name}}
{
}

Tracer::~Tracer()
{
    if (mNestingLevel > 0) {
        if (!mFixed) {
            --mNestingLevel;
            print(std::cout << mExitMarker) ;
        }
    }
}

void Tracer::setNestingPrefix(const std::string& prefix)
{
    mNestingPrefix = prefix;
}

Tracer::Tracer(bool fixed) :
    mFixed{fixed},
    mName{}
{
}

std::ostream& Tracer::print(std::ostream& o, const std::string& trailer) const
{
    for(unsigned int i = 0; i < mNestingLevel; ++i) {
        o << mNestingPrefix;
    }
    return o << mName << trailer << std::endl;
}

Tracer trace()
{
    return Tracer{true};
}

