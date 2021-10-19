#ifndef PATH_TOKEN_H
#define PATH_TOKEN_H

#include <stdbool.h>
#include <string.h>

#include "PathComponent.h"
#include "PathPunc.h"

struct ListOfPathTokens {

    const struct PathToken * tokens;

    const int length;
};

enum PathTokenType {

    pathTokenTypeComponent,
    pathTokenTypePunc
};

union PathTokenValue {

    const struct PathComponent component;

    const struct PathPunc punc;
};

struct PathToken {

    const enum PathTokenType tokenType;

    const union PathTokenValue value;
};

struct OptionalPathToken {

    const bool hasValue;

    const struct PathToken value;
};

///

extern void appendPathToken(
    struct ListOfPathTokens * listOfTokens,
    const struct PathToken token);
 
///

extern struct ListOfPathTokens initEmptyListOfPathTokens();

///

extern const struct ListOfPathTokens initListOfPathTokens(
    const struct PathToken * tokens,
    const int length);

///

extern const struct PathToken initPathToken(
    const enum PathTokenType tokenType,
    const union PathTokenValue value);

extern const struct PathToken initPathTokenFromComponent(
    const struct PathComponent component);

extern const struct PathToken initPathTokenFromPunc(
    const struct PathPunc punc);

extern const struct OptionalPathToken initNilPathToken();

extern const struct OptionalPathToken initOptionalPathToken(
    const struct PathToken token);

#endif