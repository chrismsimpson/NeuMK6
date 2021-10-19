#include <stdio.h>

#include "Path/Parser/PathParser.h"
#include "Path/Tokenizer/PathTokenizer.h"
#include "Path/Path.h"

#include "Scanner.h"

int main() {

    const struct PathParser p = initPathParserFromSource("foo");

    ///

    printf("parser length: %i\n", p.tokenizer.scanner.length);

    ///

    printf("hello foo!\n");

    ///

    return 0;
}