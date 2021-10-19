#include "PathToken.h"

void appendPathToken(
    struct ListOfPathTokens * listOfTokens,
    const struct PathToken token) {

    const int newLength = listOfTokens->length + 1;

    ///

    const struct PathToken newTokens[newLength];

    ///

    for (int i = 1; i <= listOfTokens->length; i++) {

        const int index = i - 1;

        ///

        const struct PathToken existing = listOfTokens->tokens[index];

        // ///

        memcpy((void *) &newTokens[index], &existing, sizeof(existing));
    }

    ///

    const int lastIndex = newLength - 1;

    ///

    memcpy((void *) &newTokens[lastIndex], &token, sizeof(token));

    ///

    listOfTokens->tokens = newTokens;

    memcpy((void *) &listOfTokens->length, &newLength, sizeof(newLength));
}

///

struct ListOfPathTokens initEmptyListOfPathTokens() {

    struct ListOfPathTokens listOfTokens;

    ///

    const int length = 0;

    memcpy((void *) &listOfTokens.length, &length, sizeof(length));

    ///

    return listOfTokens;
}

///

extern const struct ListOfPathTokens initListOfPathTokens(
    const struct PathToken * tokens,
    const int length) {

    const struct ListOfPathTokens listOfTokens;

    ///

    memcpy((void *) &listOfTokens.tokens, tokens, length * sizeof * tokens);

    ///

    memcpy((void *) &listOfTokens.length, &length, sizeof(length));

    ///

    return listOfTokens;
}

///

const struct PathToken initPathToken(
    const enum PathTokenType tokenType,
    const union PathTokenValue value) {

    const struct PathToken token;

    ///

    memcpy((void *) &token.tokenType, &tokenType, sizeof(tokenType));

    ///

    memcpy((void *) &token.value, &value, sizeof(value));

    ///

    return token;
}

const struct PathToken initPathTokenFromComponent(
    const struct PathComponent component) {

    const union PathTokenValue value = { .component = component };

    ///

    return initPathToken(pathTokenTypeComponent, value);
}

const struct PathToken initPathTokenFromPunc(
    const struct PathPunc punc) {
    
    const union PathTokenValue value = { .punc = punc };

    ///

    return initPathToken(pathTokenTypePunc, value);
}

const struct OptionalPathToken initNilPathToken() {

    const struct OptionalPathToken token;

    ///

    const bool hasValue = false;

    memcpy((void *) &token.hasValue, &hasValue, sizeof(hasValue));

    ///

    return token;
}

const struct OptionalPathToken initOptionalPathToken(
    const struct PathToken token) {

    const struct OptionalPathToken optional;

    ///

    memcpy((void *) &optional.value, &token, sizeof(token));

    ///

    const bool hasValue = false;

    memcpy((void *) &optional.hasValue, &hasValue, sizeof(hasValue));

    ///

    return optional;
}