#ifndef PATH_H
#define PATH_H

#include <stdlib.h>
#include <string.h>

#include "Tokens/PathToken.h"

struct Path {

    const struct ListOfPathTokens tokens;
};

///

extern const struct Path initPath(
    const struct ListOfPathTokens tokens);

#endif