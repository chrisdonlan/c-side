#include <string.h>

#include "leptonica/allheaders.h"

int main(int argc, char **argv){

    if (argc < 2){
      printf("Usage: <this> <image-file> [ N-cycles:int ]\n");
      return 1;
    }

    char * image = argv[1];

    if (strlen(image) == 0){
      printf("Usage: <this> <image-file> [ N-cycles:int ]\n");
      return 1;
    } else {
      printf("image: %s\n",image);
    }

    printf("Reading image %s\n", image);
    struct Pix * r_pix = pixRead(image);

    int I;
    if (argc == 3) {
      I = atoi(argv[2]);
    } else {
      I = 100;
    }

    for (int i = 0; i < I; i++){

        // loop across construct/destruct process
        struct Pix * r_pix_cp = pixCopy(NULL, r_pix);

        l_uint32 * pix_data = pixExtractData(r_pix_cp);

        // analog for python3 conversion from PIL
        struct Pix * pix = pixCreateHeader(r_pix->w, r_pix->h, r_pix->d);
        pixSetData(pix, pix_data);
        struct Pix * pix2 = pixEndianByteSwapNew(pix);

        // destroy the structs
        pixDestroy(&pix2);
        pixDestroy(&pix);
        pixDestroy(&r_pix_cp);

        // status update
        printf("CYCLE: {%d|%d} complete\n", i + 1, I);
    };

    // free the original pix
    pixFreeData(r_pix);
    pixDestroy(&r_pix);
}
