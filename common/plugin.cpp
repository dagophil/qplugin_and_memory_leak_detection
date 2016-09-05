#include <iostream>

#include "plugin.h"

void Plugin::say() const
{
  std::cout << "Plugin::say()" << std::endl;
}
