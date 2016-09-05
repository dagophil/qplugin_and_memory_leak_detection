#include "../common/debugNew.h"

#include <iostream>
#include <string>

#ifdef _WIN32
  #include <direct.h>
  #define GetCurrentDir _getcwd
#else
  #include <unistd.h>
  #define GetCurrentDir getcwd
#endif

#include "pluginLoader.h"

std::string working_directory()
{
  std::string wdir;
  char current_path[FILENAME_MAX];
  if (GetCurrentDir(current_path, sizeof(current_path)))
  {
    wdir = current_path;
  }
  return wdir;
}

void main_impl()
{
  std::cout << "dir: " << working_directory() << std::endl;

  PluginLoader loader;

  {
    auto plugin = loader.load("../lib/someSpecialPluginCreator");
    if (plugin != nullptr)
      plugin->say();
  }

  std::cout << "done" << std::endl;
}

int main()
{
#ifdef SHOW_MEMORY_LEAKS
  _CrtSetDbgFlag ( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

  try
  {
    main_impl();
  }
  catch (std::runtime_error& ex)
  {
    std::cerr << "std::runtime_error: " << ex.what() << std::endl;
  }

  return 0;
}
