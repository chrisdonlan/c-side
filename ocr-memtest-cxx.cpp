#include <string>
#include <iostream>

#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"


int main(int argc, char * argv)
{
    // args
    auto file = std::string(argv);
		std::cout << "Image: " << file;
		if (file.length() == 0) {
			std::cout << "Usage: <this-exe> <image-file>";
			return 1;
		}

    int N = 100;

    char *outText;

    for (int i = 0; i < N; i++){
        tesseract::TessBaseAPI *api = new tesseract::TessBaseAPI();
        // Initialize tesseract-ocr with English, without specifying tessdata path
        if (api->Init(NULL, "eng")) {
            fprintf(stderr, "Could not initialize tesseract.\n");
            exit(1);
        }

        // Open input image with leptonica library
        Pix *image = pixRead(file.c_str());
        api->SetImage(image);
        // Get OCR result
        outText = api->GetUTF8Text();
        printf("Nth {N=%d} OCR output:\n%s", i, std::string(outText).substr(0,10).c_str());
        delete [] outText;
        pixDestroy(&image);

        // Destroy used object and release memory
        api->End();
        delete api;
    }

    return 0;
}

