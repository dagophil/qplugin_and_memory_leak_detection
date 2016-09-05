#ifndef SOME_SPECIAL_PLUGIN_CREATOR_H
#define SOME_SPECIAL_PLUGIN_CREATOR_H

#include "../common/debugNew.h"

#include "../common/pluginCreator.h"

class SomeSpecialPluginCreator : public QObject, public PluginCreator
{
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "org.PluginCreator")
  Q_INTERFACES(PluginCreator)

public:

  virtual Plugin* create_plugin() const override;

};

#endif
