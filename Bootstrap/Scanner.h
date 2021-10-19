#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum ScannerType {

    scannerTypeFile,
    scannerTypeSource
};

union ScannerValue {

    const FILE * file;

    const char * source;
};

struct Scanner {

    const enum ScannerType scannerType;

    const union ScannerValue value;

    const int length;

    ///

    int rawPosition;
    
    int lineNumber;

    int column;
};

///

extern void deinitScanner(
    const struct Scanner scanner);

///

extern const struct Scanner initScanner(
    const enum ScannerType scannerType,
    const union ScannerValue value,
    const int length);

extern const struct Scanner initScannerFromSource(
    const char * source);

///

extern const bool isScannerAtEof(
    const struct Scanner * scanner);

#endif