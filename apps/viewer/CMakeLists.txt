set(SOURCES
#    application.cpp
#    application.hpp
    main.cpp
)

add_executable(Viewer ${SOURCES})
target_include_directories(Viewer PRIVATE .)
target_link_libraries(Viewer PRIVATE Engine glfw3::glfw3 GpuApi)
set_target_properties(Viewer
    PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
