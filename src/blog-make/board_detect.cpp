#include <stdio.h> 
#include "board_detect.h" 

#ifdef IS_AM572x
#define AM572x_Flag 1
#else
#define AM572x_Flag 0
#endif


int main(){
    if(AM572x_Flag == 1){
        printf("\nAll codes are compiled to run on BBAI\n");
    }
    else{
        printf("\nCode compiled to run on old hardware\n");
    }
}
