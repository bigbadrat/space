#include "io.h"
#include <iostream>


namespace Tanaka
{

std::ostream& operator<<(std::ostream& out, EntityManager const& m)
{
    out << m.count() << " entities in manager" << std::endl;
    return out;
}

std::ostream& operator<<(std::ostream& out, Entity const& e)
{
    out << "{ name:" << e.name() << "\n";
    for(auto& it: e.components())
        out << '\t' << *it << std::endl;
    out << "}" ;
    return out;
}

std::ostream& operator<<(std::ostream& out, BaseComponent const& c)
{
    out << "{ " << c.name() << c.internal_to_string() << " } " ;
    return out;
}
}
