/*
 * ++C - C++ introduction
 * Copyright (C) 2013, 2014  Wilhelm Meier <wilhelm.meier@fh-kl.de>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef TRACER_H
#define TRACER_H

#include <string>

#ifdef _MSC_VER
# define __PRETTY_FUNCTION__ __FUNCTION__
#endif

#if !(defined(NDEBUG) || defined(NO_TRACE))
# define TRACE Tracer __t(std::string(__PRETTY_FUNCTION__))
# define TRACE1(s) Tracer __t1(s);
# define TRACE2(s) Tracer __t2(std::string(__PRETTY_FUNCTION__) + " : " + s);
#else
# define TRACE
# define TRACE1
# define TRACE2
#endif

#include <iostream>

class Tracer;

Tracer trace(); // fuer friend-Deklaration

class Tracer final
{
    friend Tracer trace();
public:
    explicit Tracer(const char* name);
    explicit Tracer(std::string name);

    ~Tracer();

    void setNestingPrefix(const std::string& prefix);

#ifndef NDEBUG
    template<typename T>
    const Tracer& operator<<(const T& value) const
    {
        for(unsigned int i = 0; i < mNestingLevel; ++i) {
            std::cout << mNestingPrefix;
        }
        std::cout << value << std::endl;
        return *this;
    }
#else
    template<typename T>
    const Tracer& operator<<(const T&) const
    {
        return *this;
    }
#endif

private:
    explicit Tracer(bool fixed = false);
    std::ostream& print(std::ostream& o, const std::string& trailer = "") const;

    bool mFixed;
    std::string mName;

    static std::string mNestingPrefix;
    static unsigned int mNestingLevel;
    static const char* mEntryMarker;
    static const char* mExitMarker;
};

#endif // TRACER_H
