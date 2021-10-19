#ifndef PATH_TOKENIZER_H
#define PATH_TOKENIZER_H

#include <stdlib.h>

#include "../../Scanner.h"

#include "../Tokens/PathToken.h"

struct PathTokenizer {

    struct Scanner scanner;

    struct ListOfPathTokens listOfTokens;

    int rawPosition;
};

///

extern struct PathTokenizer initPathTokenzer(
    struct Scanner scanner);

extern struct PathTokenizer initPathTokenizerFromSource(
    const char * source);

///

extern const struct OptionalPathToken nextPathToken(
    struct PathTokenizer * tokenizer);

#endif