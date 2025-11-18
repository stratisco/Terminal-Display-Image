#include "main.h"


int main(int argc, char* argv[]) {

    
    if (argc < 2) {
        printf("Usage:\n   %s FILE\n", argv[0]);
        return 1;
    }


    // load image
    int width, height, channels;    
    unsigned char *img_data = stbi_load(argv[1], &width, &height, &channels, 0);        

    if (img_data == NULL) {
        printf("Error loading image: %s\n", stbi_failure_reason());
        return 1;
    }

    
    // get scale
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    int scale = width / w.ws_col + 1;
    
    printf("Image printing: Width = %d, Height = %d, Channels = %d, Scale = %d\n", width, height, channels, scale);

    display(img_data, width, height, scale, channels);
    
    
    stbi_image_free(img_data);

    return 0;



}
