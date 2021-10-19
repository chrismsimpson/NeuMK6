#include "PathParser.h"

struct PathParser initPathParser(
    struct PathTokenizer tokenizer) {

    struct PathParser parser;

    ///

    memcpy((void *) &parser.tokenizer, &tokenizer, sizeof(tokenizer));

    ///

    return parser;
}

struct PathParser initPathParserFromSource(
    const char * source) {

    const struct PathTokenizer tokenizer = initPathTokenizerFromSource(source);

    ///

    return initPathParser(tokenizer);
}
