#ifndef PLUGIN_H
#define PLUGIN_H

#include "../common/debugNew.h"

class Plugin
{
public:

  virtual ~Plugin() = default;
  virtual void say() const;

};

#endif
