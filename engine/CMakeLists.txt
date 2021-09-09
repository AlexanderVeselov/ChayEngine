set(CORE_SOURCES
    core/app_settings.hpp
    core/application.cpp
    core/application.hpp
    core/engine.cpp
    core/engine.hpp
    core/entity.cpp
    core/entity.hpp
#    core/scene.cpp
#    core/scene.hpp
    core/renderer.hpp
    core/window.cpp
    core/window.hpp
)

source_group("core" FILES ${CORE_SOURCES})

set(ENTITIES_SOURCES
    entities/camera.cpp
    entities/camera.hpp
)

source_group("entities" FILES ${ENTITIES_SOURCES})

set(LOADERS_SOURCES
    loaders/obj_loader.cpp
    loaders/obj_loader.hpp
)

source_group("loaders" FILES ${LOADERS_SOURCES})

set(RENDERERS_SOURCES
    renderers/forward_renderer.cpp
    renderers/forward_renderer.hpp
)

source_group("renderers" FILES ${RENDERERS_SOURCES})

set(SHADERS_SOURCES
    shaders/common.h
    shaders/shader.frag
    shaders/shader.vert
)

source_group("shaders" FILES ${SHADERS_SOURCES})

add_library(Engine STATIC
    ${CORE_SOURCES}
    ${ENTITIES_SOURCES}
    ${LOADERS_SOURCES}
    ${RENDERERS_SOURCES}
    ${SHADERS_SOURCES}
)

target_include_directories(Engine PUBLIC .)
target_include_directories(Engine PRIVATE ${ChayEngine_SOURCE_DIR}/dependencies/tinyobjloader)
target_link_libraries(Engine PRIVATE GpuApi glfw3::glfw3)
target_compile_features(Engine PUBLIC cxx_std_17)
