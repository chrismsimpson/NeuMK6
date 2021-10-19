#ifndef PATH_PARSER_H
#define PATH_PARSER_H

#include <stdlib.h>

#include "../Tokenizer/PathTokenizer.h"

struct PathParser {

    const struct PathTokenizer tokenizer;
};

///

extern struct PathParser initPathParser(
    struct PathTokenizer tokenizer);

extern struct PathParser initPathParserFromSource(
    const char * source);

///

extern const struct Path parsePath(
    const struct Path);

#endif