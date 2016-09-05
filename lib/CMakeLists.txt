add_library(someSpecialPluginCreator SHARED
  someSpecialPlugin.cpp
  someSpecialPluginCreator.cpp
  ../common/plugin.cpp
)
target_link_libraries(someSpecialPluginCreator
  Qt5::Core
)
