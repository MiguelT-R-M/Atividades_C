#include <stdio.h>
#include <stdlib.h>

int main(void){

    char str[] = "00:00";
    int days = 0;

    str[1]+=96;

    while(str[4]>'9' || str[4]<'0'){
        str[4] = str[4]-10;
        str[3] = str[3]+1;
    }
    while(str[3]>'5' || str[3]<'0'){
        str[3] = str[3]-6;
        str[1] = str[1]+1;
    }
    while(str[0]>='2' || str[0]<'0' || str[1]>='9' || str[1]<'0'){
        if(str[0]=='2' && str[1]=='4'){
            str[0] = '0';
            str[1] = '0';
            days++;
        }
        while((str[0]>='2' && str[1]>=4) || (str[0]>='2' && str[1]<'0')){
            str[1] = str[1]-5;
            str[0] = str[0]-2;
            days++;
        }
        while(str[1]>'9' || str[1]<'0'){
            str[1] = str[1]-10;
            str[0] = str[0]+1;
        }
        while(str[0]>'2' || str[0]<'0'){
            str[0] = str[0]-3;
            str[1] = str[1]+6;
            days++;
        }
    }

    return 0;
}