#include "Scanner.h"

void deinitScanner(
    const struct Scanner scanner) {

    switch (scanner.scannerType) {

    case scannerTypeFile:

        fclose((FILE *) scanner.value.file);

        break;

    ///

    case scannerTypeSource:

        break;
    }    
}

///

const struct Scanner initScanner(
    const enum ScannerType scannerType,
    const union ScannerValue value,
    const int length) {

    const struct Scanner scanner;

    ///

    * (enum ScannerType *) &scanner.scannerType = scannerType;

    ///

    * (union ScannerValue *) &scanner.value = value;

    ///

    * (int *) &scanner.length = length;

    ///

    * (int *) &scanner.rawPosition = 0;

    * (int *) &scanner.lineNumber = 1;

    * (int *) &scanner.column = 1;
    
    ///

    return scanner;
}

const struct Scanner initScannerFromSource(
    const char * source) {

    const union ScannerValue value = { .source = source };

    ///

    const int length = strlen(source);

    ///

    return initScanner(scannerTypeSource, value, length);
}

///

const bool isScannerAtEof(
    const struct Scanner * scanner) {

    return scanner->rawPosition >= scanner->length;
}