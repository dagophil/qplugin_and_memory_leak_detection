#include "pluginLoader.h"
#include "../common/pluginCreator.h"

std::unique_ptr<Plugin> PluginLoader::load(const std::string& plugin_path)
{
  auto& loader = this->get_plugin_loader(plugin_path);
  auto plugin_creator_obj = loader.instance();
  auto plugin_creator = qobject_cast<PluginCreator*>(plugin_creator_obj);
  if (plugin_creator == nullptr)
    throw std::runtime_error("Could not convert plugin to Plugin*.");
  auto plugin = plugin_creator->create_plugin();
  return std::unique_ptr<Plugin>(plugin);
}

QPluginLoader& PluginLoader::get_plugin_loader(const std::string& plugin_path)
{
  auto it = this->pluginLoaders.find(plugin_path);
  if (it == this->pluginLoaders.end())
  {
    auto loader = std::make_unique<QPluginLoader>(plugin_path.c_str());
    auto loaded = loader->load();
    if (!loaded)
      throw std::runtime_error("Could not load plugin: " + plugin_path);
    auto p = this->pluginLoaders.emplace(plugin_path, std::move(loader));
    it = p.first;
  }
  return *it->second;
}
