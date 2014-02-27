#ifndef TANAKA_STUFF_IO_H_
#define TANAKA_STUFF_IO_H_
#include <iosfwd>
#include "entity_manager.h"
#include "entity.h"
#include "components/base_component.h"

namespace Tanaka
{

std::ostream& operator<<(std::ostream& out, EntityManager const& m);

std::ostream& operator<<(std::ostream& out, Entity const& m);

std::ostream& operator<<(std::ostream& out, BaseComponent const& c);

}

#endif
