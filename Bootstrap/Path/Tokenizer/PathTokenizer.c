#include "PathTokenizer.h"

struct PathTokenizer initPathTokenzer(
    struct Scanner scanner) {

    struct PathTokenizer tokenizer;

    ///

    struct ListOfPathTokens listOfTokens = initEmptyListOfPathTokens();

    memcpy((void *) &tokenizer.listOfTokens, &listOfTokens, sizeof(listOfTokens));

    ///

    memcpy((void *) &tokenizer.scanner, &scanner, sizeof(scanner));

    ///

    * (int *) &tokenizer.rawPosition = 0;

    ///

    return tokenizer;
}

struct PathTokenizer initPathTokenizerFromSource(
    const char * source) {

    const struct Scanner scanner = initScannerFromSource(source);

    ///

    return initPathTokenzer(scanner);
}

const struct OptionalPathToken nextPathToken(
    struct PathTokenizer * tokenizer) {

    if (tokenizer->rawPosition + 1 <= tokenizer->listOfTokens.length) {

        const struct PathToken token = tokenizer->listOfTokens.tokens[tokenizer->rawPosition];

        tokenizer->rawPosition++;
        
        return initOptionalPathToken(token);
    }

    return initNilPathToken();
}