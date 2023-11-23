#include "Window.hpp"
#include <SDL3/SDL.h>
#include <stdexcept>


Window::Window(const std::string& title, int width, int height, unsigned flags):m_window(nullptr,SDL_DestroyWindow) {
    SDL_InitSubSystem(SDL_INIT_VIDEO);
    const auto window = SDL_CreateWindow(title.c_str(),width,height,flags);
    if (window) {
        m_window.reset(window);
    }else {
        throw std::runtime_error(SDL_GetError());
    }
    
}

Window::~Window() {
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

std::optional<SDL_Event> Window::pollEvent() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        return event;
    }
    return {};
}
