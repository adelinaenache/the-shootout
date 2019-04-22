#include <iostream>
#include "src/board.h"

using namespace std;

int main() {
    // create a board with agents
    Board b(5, 5, 5);
    b.simulate();

    return 0;
}