#include "leptonica/allheaders.h"

int main(int argc, char *argv){

		printf("image: %s",argv);
    struct Pix * r_pix = pixRead(argv);

		int I = 100;
    for (int i = 0; i < I; i++){

        // Pix seems to delete the data associated with the original pix when it is set to a different pix
        // so this avoids segfault
        struct Pix * r_pix_cp = pixCopy(NULL, r_pix);
        l_uint32 * pix_data = pixExtractData(r_pix_cp);

        // analog for python3 conversion from PIL
        struct Pix * pix = pixCreate(r_pix->w, r_pix->h, r_pix->d);
        pixSetData(pix, pix_data);
        pixEndianByteSwap(pix);
        pixDestroy(&pix);

        // free the rest of the cp struct
        pixDestroy(&r_pix_cp);
				printf("%d of %d cycles completed.", i, I);
    };

    // free the original pix
    pixDestroy(&r_pix);
}
