#include <stdio.h>

struct properties {
    unsigned int :6;
    unsigned int alpha:1;
    unsigned int fill_color:3;
    unsigned int border:1;
    unsigned int border_color:3;
    unsigned int border_style:2;
};


char* colors[8] = {"Black","Red","Green","Yellow","Blue","Magenta","Cyan","White"};
char* border[2] = {"doesnt have border", "has border"};
char* style[3] = {"solid", "dotted", "dashed"};



void display(struct properties *p) {
    printf("Alpha is %s\n", (p->alpha > 0) ? "opaque" : "transparent");
}

int main() {
    struct properties my_box = {1,0b010,1,0b000,1};
    display(&my_box);
    my_box.alpha = 0;
    my_box.fill_color = 5;
    my_box.border_style = 0;
    display(&my_box);
    return 0;
}