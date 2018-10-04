


#include <emscripten/bind.h>

using namespace emscripten;

class Game {
    
public:
    Game(int x) :x(x){}

void incrementX() {
    ++x;
}

int getX() const { return x;}
void setX(int x_) { x = x_;}

private: 
    int x;
};

EMSCRIPTEN_BINDINGS(b_ex) {
    class_<Game>("Game")
        .constructor<int>()
        .function("incrementX", &Game::incrementX)
        .property("x", &Game::getX, &Game::setX);
}
