#include "someSpecialPlugin.h"
#include "someSpecialPluginCreator.h"

Plugin* SomeSpecialPluginCreator::create_plugin() const
{
  return new SomeSpecialPlugin();
}
