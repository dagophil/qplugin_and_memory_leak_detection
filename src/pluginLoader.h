#ifndef PLUGIN_LOADER_H
#define PLUGIN_LOADER_H

#include "../common/debugNew.h"

#include <map>
#include <memory>
#include <string>

#include <QPluginLoader>

#include "../common/plugin.h"

class PluginLoader
{
public:

  std::unique_ptr<Plugin> load(const std::string& plugin_path);

private:

  QPluginLoader& get_plugin_loader(const std::string& plugin_path);

  std::map<std::string, std::unique_ptr<QPluginLoader>> pluginLoaders;

};

#endif
