//
// Created by arahasya on 6/21/20.
//

#include "Transforming.h"

// array of all transforming functions in order of MatrixDriver enum
Transformers::Transformer Transformers::transformer[6] = {
        Transformers::NoTransforming,
	Transformers::MIRRORH,
	Transformers::MIRRORV,
	Transformers::ROTATE90,
	Transformers::ROTATE180,
	Transformers::ROTATE270
};

// no transforming does nothing
void Transformers::NoTransforming(unsigned int &x, unsigned int &y, unsigned &matrixWidth, unsigned &matrixHeight) {

}

// horizontal mirror transformer
void Transformers::MIRRORH(unsigned &x, unsigned &y, unsigned &matrixWidth, unsigned &matrixHeight) {
	x = matrixWidth - 1 - x;
}

// vertical mirror transformer
void Transformers::MIRRORV(unsigned &x, unsigned &y, unsigned &matrixWidth, unsigned &matrixHeight) {
        y = matrixHeight - 1 - y;
}

// rotational transformer
void Transformers::ROTATE90(unsigned &x, unsigned &y, unsigned &matrixWidth, unsigned &matrixHeight) {
	auto x1 = x;
	x = matrixWidth - y - 1;
	y = x1;
}
void Transformers::ROTATE180(unsigned &x, unsigned &y, unsigned &matrixWidth, unsigned &matrixHeight) {
        x = matrixWidth - x - 1;
        y = matrixHeight - y - 1;
}
void Transformers::ROTATE270(unsigned &x, unsigned &y, unsigned &matrixWidth, unsigned &matrixHeight) {
	auto y1 = y;
        y = matrixHeight - x - 1;
        x  = y1;
}
