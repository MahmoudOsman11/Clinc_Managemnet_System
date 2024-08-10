#include <stdio.h>
#include <stdlib.h>
#include "admin1.h"

#include "user1.h"


unsigned int Attempts=0;

void init(Clinic *clinic){
    clinic->patient_counter=0;
    clinic->Avilable_Slots[0]=first_time;
    for(int i=1 ; i<max_slots;i++){
        clinic->Avilable_Slots[i]=clinic->Avilable_Slots[i-1]+0.5;
        if(clinic->Avilable_Slots[i]==last_time)
            break;
    }

}
char aoru=0;
int main()
{
    Clinic clinic;
    init(&clinic);
    while(1){
    printf("1-> admin \n2-> User\n3-> EXIT \n");
    scanf("%d",&aoru);
    if(aoru==1){
        admin(&clinic,&Attempts);
        if(Attempts>=3){
            break;
        }
    }
    else if(aoru==2){

            User(&clinic);
    }
    else if(aoru==3){

            break;
    }
    }




    return 0;
}




