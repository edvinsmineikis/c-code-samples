#include <stdio.h>

struct properties {
    unsigned int :6;
    unsigned int alpha:1;
    unsigned int fill_color:3;
    unsigned int border:1;
    unsigned int border_color:3;
    unsigned int border_style:2;
};

char* alpha[2] = {"Opaque", "Transparent"};
char* colors[8] = {"Black","Red","Green","Yellow","Blue","Magenta","Cyan","White"};
char* border[2] = {"doesnt have border", "has border"};
char* style[3] = {"solid", "dotted", "dashed"};

void printdata(int alphain, int fillin, int borderin, int border_colorin, int stylein) {
    printf("Box is %s\n", alpha[alphain]);
    printf("Box is of %s color\n", colors[fillin]);
    printf("Box %s\n", border[borderin]);
    printf("Box has border of %s color\n", colors[border_colorin]);
    printf("Border line style is %s\n\n", style[stylein]);
}

int main() {
    

    
    struct properties my_box = {1,0b010,1,0b000,1};
    printdata(my_box.alpha, my_box.fill_color, my_box.border, my_box.border_color, my_box.border_style);
    my_box.fill_color = 5;
    my_box.border_style = 0;
    printdata(my_box.alpha, my_box.fill_color, my_box.border, my_box.border_color, my_box.border_style);
    return 0;
}