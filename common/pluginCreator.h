#ifndef PLUGIN_CREATOR_H
#define PLUGIN_CREATOR_H

#include <QObject>

class Plugin;

class PluginCreator
{
public:

  virtual ~PluginCreator() = default;
  virtual Plugin* create_plugin() const = 0;

};

Q_DECLARE_INTERFACE(PluginCreator, "org.PluginCreator")

#endif
