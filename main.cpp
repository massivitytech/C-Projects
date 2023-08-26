#include "cgpa.cpp"
#include <SDL_ttf.h>
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const string FONT_PATH = "C:/Users/zulul/OneDrive/Desktop/C++ Programs/CGPA/C-Projects/ostrich-sans";

int main(int argc, char* argv[]){

    Courses one("Mathematics");
    one.InsertModules();
    one.PrintModules();
    one.InsertNumber('A');
    GCPA Main(one.major,one);
    cout<<one.Nummodules()<<endl;//next now change the gpa for many modules
    cout<<Main.GPA()<<endl;

   SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_Window* window = SDL_CreateWindow("User Input Example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    TTF_Font* font = TTF_OpenFont(FONT_PATH.c_str(), 28);
    SDL_Color textColor = { 255, 255, 255, 255 };

    std::string symbolInput = "";
    std::string majorInput = "";

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_TEXTINPUT) {
                if (symbolInput.size() < 10) {
                    symbolInput += event.text.text;
                }
            }
            else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_BACKSPACE && !symbolInput.empty()) {
                symbolInput.pop_back();
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        SDL_Surface* symbolSurface = TTF_RenderText_Solid(font, ("Symbol: " + symbolInput).c_str(), textColor);
        SDL_Texture* symbolTexture = SDL_CreateTextureFromSurface(renderer, symbolSurface);
        int symW, symH;
        SDL_QueryTexture(symbolTexture, NULL, NULL, &symW, &symH);
        SDL_Rect symRect = { 50, 50, symW, symH };
        SDL_RenderCopy(renderer, symbolTexture, NULL, &symRect);
        SDL_FreeSurface(symbolSurface);
        SDL_DestroyTexture(symbolTexture);

        SDL_RenderPresent(renderer);
    }

    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    TTF_Quit();
    SDL_Quit();

    return 0;
}