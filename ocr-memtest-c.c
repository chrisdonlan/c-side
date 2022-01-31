#include <string.h>

#include "leptonica/allheaders.h"

int main(int argc, char **argv){

    if (argc < 2){
      printf("Usage: <this> <image-file>\n");
      return 1;
    }

    char * image = argv[1];

    if (strlen(image) == 0){
      printf("foo Usage: <this> <image-file>\n");
      return 1;
    } else {
      printf("image: %s\n",image);
    }

    printf("Reading image %s\n", image);
    struct Pix * r_pix = pixRead(image);

    int I = 100;
    for (int i = 0; i < I; i++){

        // Pix seems to delete the data associated with the original pix when it is set to a different pix
        // so this avoids segfault
        struct Pix * r_pix_cp = pixCopy(NULL, r_pix);
        l_uint32 * pix_data = pixExtractData(r_pix_cp);

        // analog for python3 conversion from PIL
        struct Pix * pix = pixCreate(r_pix->w, r_pix->h, r_pix->d);
        pixSetData(pix, pix_data);
        struct Pix * pix2 = pixEndianByteSwapNew(pix);
        pixDestroy(&pix2);
        pixDestroy(&pix);

        // free the rest of the cp struct
        pixDestroy(&r_pix_cp);
        printf("CYCLE: {%d|%d} complete\n", i + 1, I);
    };

    // free the original pix
    pixDestroy(&r_pix);
}
