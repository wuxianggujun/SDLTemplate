#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <Window.hpp>

#define IMG_INIT_FLAG(FLAG) do {                   \
if ((IMG_Init(FLAG) & FLAG) != FLAG) {      \
SDL_Log("IMG_Init("#FLAG") failed");    \
return -1; \
}                                           \
} while (0);

void handleInput(bool&shouldQuit) {
    std::optional<SDL_Event> event;
    while ((event = Window::pollEvent())) {
        switch (event->type) {
            case SDL_EVENT_QUIT:
                shouldQuit = true;
                break;
            default:
                break;
        }
    }
}


int main(int argc, char* argv[]) {
    IMG_INIT_FLAG(IMG_INIT_JPG);

    try {
        Window window("SDL Test Window",1280,720);
        bool shouldQuit = false;
        while (!shouldQuit) {
            handleInput(shouldQuit);
        }
    }
    catch (const std::exception&exception) {
        const auto errorMessage = exception.what();
        SDL_LogCritical(SDL_LOG_CATEGORY_ERROR, "%s", errorMessage);
        SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error Message", errorMessage, nullptr);
        SDL_Quit();
        return 1;
    }

    SDL_Quit();
    return 0;
}
