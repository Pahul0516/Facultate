#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include "tests.h"
#include "UI.h"

int main() {
    allTests();
    run();
    _CrtDumpMemoryLeaks();
    return 0;
}
