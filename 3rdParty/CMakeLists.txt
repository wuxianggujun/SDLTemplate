set(SDL_TEST OFF)
set(SDL_SHARED TRUE CACHE BOOL "Build a SDL shared library (if available)")
set(SDL_STATIC TRUE CACHE BOOL "Build a SDL static library (if available)")

add_subdirectory(SDL)
add_subdirectory(SDL_image)

add_library(3rdParty INTERFACE)
target_link_libraries(3rdParty INTERFACE SDL3_image::SDL3_image-shared SDL3::SDL3)