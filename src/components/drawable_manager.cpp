#include "drawable_manager.h"

namespace Tanaka
{

    DrawableManager::DrawableManager()
    {
        update_priority(1000);
        name("drawable");
    }

    void DrawableManager::draw()
    {
        for (auto& i: _components)
        {
            i->draw();
        }
    }

}
