#ifndef SOME_SPECIAL_PLUGIN_H
#define SOME_SPECIAL_PLUGIN_H

#include "../common/debugNew.h"

#include "../common/plugin.h"

class SomeSpecialPlugin : public Plugin
{
public:

  ~SomeSpecialPlugin();
  virtual void say() const override;

};

#endif
