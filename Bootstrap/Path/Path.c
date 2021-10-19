#include "Path.h"

const struct Path initPath(
    const struct ListOfPathTokens tokens) {

    const struct Path path;

    ///

    memcpy((void *) &path.tokens, &tokens, sizeof(tokens));

    ///

    return path;
}