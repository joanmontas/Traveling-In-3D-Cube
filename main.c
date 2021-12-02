/***************************************************************/
/* Programmer: Joan Montas                                     */
/*                                                             */
/* Program 65: 3D cube traveling                               */
/*          Simple program I made for fun as a challenge       */
/*          When I was bored                                   */
/*                                                             */
/* Approximate completion time:   35 minutes                   */
/***************************************************************/
// I decided to use recursion for fun
#include <stdio.h>

void positionChanger(int position[], int coordinate, int value, int sign);

void test(void);

void newValueRemainder(int *newValue, int *remainder);

int cubeFace = 5;

int main(int argc,char *argv[]){

    int position[3] = {10,20,10};

    for(int i = 0; i < sizeof(position)/sizeof(int); i++){
        printf("%d ",position[i]);
    }
    
    positionChanger(position,2,12,-1);
    positionChanger(position,0,34,1);
    positionChanger(position,1,1,1);

    printf("\n%d,cubeFace\n",cubeFace);

    for(int i = 0; i < sizeof(position)/sizeof(int); i++){
        printf("%d ",position[i]);
    };

    return 0;
}

void positionChanger(int position[], int coordinate, int value, int sign){
    //printf(" \"Face= %d\"" ,cubeFace);
    //if we are not adding any value stop
    if(value == 0){
        return;
    };
    //calculate new coordinate value and proper remainder
    int newValue = position[coordinate] + (sign * value);

    int remainder = 0; //default remainder is 0

    //calulate remainder and newvalue for the coordinate
    newValueRemainder(&newValue, &remainder);

    //Assigns the coordinate's new value
    position[coordinate] = newValue;

    ////printf(" (%d,%d) ",newValue,remainder); 

    if(remainder > 0){
        switch(cubeFace){
            case 0:
                    if(sign == 1 && coordinate == 0){cubeFace = 2;}
                    else if(sign == -1 && coordinate == 0){cubeFace = 4;}
                    else if(sign == 1 && coordinate == 1){cubeFace = 5; }
                    else{cubeFace = 3;};
                    return positionChanger(position, 2, remainder, -1);
                    break;
            case 1:
                    if(sign == 1 && coordinate == 0){cubeFace = 2;}
                    else if(sign == -1 && coordinate == 0){cubeFace = 4;}
                    else if(sign == 1 && coordinate == 1){cubeFace = 5;}
                    else{cubeFace = 3;};
                    return positionChanger(position, 2, remainder, 1);
                    break;
            case 2:
                    if(sign == 1 && coordinate == 1){cubeFace = 5;}
                    else if(sign == -1 && coordinate == 1){cubeFace = 3;}
                    else if(sign == 1 && coordinate == 2){cubeFace = 0;}
                    else{cubeFace = 1;}
                    return positionChanger(position, 0, remainder, -1);
                    break;
            case 3:
                    if(sign == 1 && coordinate == 0){cubeFace = 2;}
                    else if(sign == -1 && coordinate == 0){cubeFace = 4;}
                    else if(sign == 1 && coordinate == 1){cubeFace = 0;}
                    else{cubeFace = 1;};
                    return positionChanger(position, 1, remainder, 1);
                    break;

            case 4:
                    if(sign == 1 && coordinate == 1){cubeFace = 5;}
                    else if(sign == -1 && coordinate == 1){cubeFace = 3;}
                    else if(sign == 1 && coordinate == 2){cubeFace = 0;}
                    else{cubeFace = 1;};
                    return positionChanger(position, 0, remainder, 1);
                    break;
            case 5:
                    if(sign == 1 && coordinate == 0){cubeFace = 2;}
                    else if(sign == -1 && coordinate == 0){cubeFace = 4;}
                    else if(sign == 1 && coordinate == 2){cubeFace = 0;}
                    else{cubeFace = 1;};
                    eturn positionChanger(position, 1, remainder, -1);
                    break;
            default:
                return;
                break;
        };
    
    };
    return;
};






void test(void){
    printf("%d",cubeFace);
};



void newValueRemainder(int *newValue, int *remainder){

    //calculate new coordinate value and proper remainder

    if(*newValue > 20){
        *remainder = *newValue-20;
        *newValue = 20;
    };
    if(*newValue < 0){
        *remainder = *newValue * (-1);
        *newValue = 0;
    };

};
r
