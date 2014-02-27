#include "entity_manager.h"
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "io.h"

namespace Tanaka
{

EntityManager::EntityManager()
{}

void EntityManager::add( Entity::Ptr e )
{
    _entities.push_back(e);
    //TODO: Have to check what is going to be way to handle unique names
    if (e->name().empty())
        e->name( get_unique_name() );

    auto found = _name_index.find( e->name() );
    if (found != _name_index.end())
    {
       e->name(get_unique_name()); 
    }
    _name_index.insert(std::make_pair( e->name(), e ) );
}

int EntityManager::count() const
{
    return _entities.size();
}

Entity::Ptr EntityManager::find( const std::string& name)
{
    auto it = _name_index.find( name );
    if ( it == _name_index.end() )
        return Entity::Ptr();
    return it->second;
}

std::string EntityManager::get_unique_name()
{
    static int unique_id = 0;
    std::stringstream base_name;
    base_name << "entity_" << unique_id++;
    return base_name.str();

}

void EntityManager::dump()
const
{
    std::cout << "EntityManager with " << _entities.size() << std::endl;
    std::for_each( _entities.begin(), _entities.end(),
            []( Entity::Ptr const& i ){
                std::cout << *i << std::endl;
            } );
}

} //end namespace Tanaka
