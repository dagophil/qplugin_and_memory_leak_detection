#include <iostream>

#include "someSpecialPlugin.h"

SomeSpecialPlugin::~SomeSpecialPlugin()
{
  std::cout << "~SomeSpecialPlugin()" << std::endl;
}

void SomeSpecialPlugin::say() const
{
  auto x = new int();
  std::cout << "SomeSpecialPlugin::say()" << std::endl;
  Plugin::say();
}
