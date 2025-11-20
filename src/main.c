#include "main.h"


char* short_usage_msg = "Usage: dimg [FILE] [DISPLAY OPTIONS]\nTry dimg --help for more info\n";
char* long_usage_msg = "Usage: dimg [FILE] [DISPLAY OPTIONS]\n"
"\nDisplay options:\n"
"  -w, --max-width #    Maximum width of the outputed image in character spaces. This supports % values\n"
"  -h, --max-height #   Maximum height of the outputed image in character spaces. This supports % values\n"
"      --upper-slab     Print pixels using upper half slab '▀'\n"
"      --lower-slab     Print pixels using lower half slab '▄'\n"
"      --two-space      Print pixels using two spaces '  ' (this is more compatible but reduces image resolution 2x) \n"
"\nMisc options:\n"
"      --help           Prints this message\n"
"\nExamples:\n"
"  dimg images/cat.png -w 50%\n"
"  dimg dog.png --two-space\n"
"\nFor more information visit the github:\n"
"  <https://github.com/stratisco/Terminal-Display-Image>\n"
;



int main(int argc, char* argv[]) {

    
    if (argc < 2) {
        printf("%s", short_usage_msg);
        return 1;
    }

    if (strcmp(argv[1], "--help") == 0) {
        printf("%s", long_usage_msg);
        return 0;
    }


    // load image
    int img_width, img_height, channels;
    unsigned char *img_data = stbi_load(argv[1], &img_width, &img_height, &channels, 0);        

    if (img_data == NULL) {
        printf("Error opening image file %s\n", argv[1]);
        return 1;
    }

    
    // get scale
    struct winsize terminal;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal);
    
    int output_width = terminal.ws_col * DEFAULT_WIDTH;
    int output_height = terminal.ws_row;
    bool height_set = false;

    

    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-w") == 0 || strcmp(argv[i], "--max-width") == 0) {
            if (i + 1 >= argc) {
                printf("Error - argument width needs a value set\n");
                printf("%s", short_usage_msg);
                return 0;
            }
            
            if (argv[i+1][strlen(argv[i+1])-1] == '%') {
                float percent;
                sscanf(argv[i+1], "%f", &percent);

                output_width = percent * terminal.ws_col / 100;
            } else {
                sscanf(argv[i+1], "%d", &output_width);
            }

            i += 1;
        } else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--max-height") == 0) {
            if (i + 1 >= argc) {
                printf("Error - argument height needs a value set\n");
                printf("%s", short_usage_msg);
                return 0;
            }

            if (argv[i+1][strlen(argv[i+1])-1] == '%') {
                float percent;
                sscanf(argv[i+1], "%f", &percent);

                output_height = percent * terminal.ws_row / 100;
            } else {
                sscanf(argv[i+1], "%d", &output_height);
            }
            height_set = true;

            i += 1;
        } else if (strcmp(argv[i], "--upper-slab") == 0) {
            displayMethod = UPPER_HALF_SLAB;
        
        } else if (strcmp(argv[i], "--lower-slab") == 0) {
            displayMethod = LOWER_HALF_SLAB;
        
        } else if (strcmp(argv[i], "--two-space") == 0) {
            displayMethod = TWO_SPACE_PIXEL;

        } else if (strcmp(argv[i], "--help") == 0) {
            printf("%s", long_usage_msg);
            return 0;
        } else {
            printf("Unknown argument '%s'\n", argv[i]);
            printf("%s", short_usage_msg);
            return 1;
        }
    }


    int w_scale = img_width / output_width + 1;
    int h_scale = img_height / output_height + 1;
    if (displayMethod == UPPER_HALF_SLAB || displayMethod == LOWER_HALF_SLAB) {
        h_scale /= 2;
    }
    if (displayMethod == TWO_SPACE_PIXEL) {
        w_scale *= 2;
    }


    int scale = w_scale;
    if (h_scale > w_scale && height_set) {
        scale = h_scale;
    }

    
    // printf("Image printing: Width = %d, Height = %d, Channels = %d, Scale = %d\n", img_width, img_height, channels, scale);
    
    display(img_data, img_width, img_height, scale, channels);
    
    stbi_image_free(img_data);

    return 0;



}
