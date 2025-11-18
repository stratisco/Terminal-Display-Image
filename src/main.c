#include "main.h"


int main(int argc, char* argv[]) {

    
    if (argc < 2) {
        printf("Usage:\n   %s FILE\n", argv[0]);
        return 1;
    }



    int width, height, channels;
    
    unsigned char *img_data = stbi_load(argv[1], &width, &height, &channels, 0);        

    if (img_data == NULL) {
        printf("Error loading image: %s\n", stbi_failure_reason());
        return 1;
    }

    printf("Image loaded: Width = %d, Height = %d, Channels = %d\n", width, height, channels);

    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    
    int scale = width / w.ws_col + 1;
    
    printf("%d / %d + 1 = %d\n", width, w.ws_col, scale);

    display(img_data, width, height, scale, channels);
    

    // for (int y = 0; y < height; y = y + scale*2) {
    //     for (int x = 0; x < width; x = x + scale) {
            
    //         unsigned char* pixel_index = (img_data + ((y * width + x) * channels));
    //         color((int) *(pixel_index + 0), (int) *(pixel_index + 1), (int) *(pixel_index + 2), FOREGROUND);

    //         pixel_index = (img_data + (((y+1) * width + x) * channels));
    //         color((int) *(pixel_index + 0), (int) *(pixel_index + 1), (int) *(pixel_index + 2), BACKGROUND);  

    //         // printf("▄");
    //         printf("▀");
    //     }
    //     color_reset();
    //     printf("\n");
    // }   
    
    stbi_image_free(img_data);

    return 0;



}
