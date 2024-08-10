
#include"admin1.h"

void User(Clinic *clinic){
    unsigned int user_ID;
    float slot_by_hours_not_id;
    char flag=0;
    printf("****** Hello User ******\n\n" );
    printf("enter Your ID : ");
    scanf("%d",&user_ID);
    for(int i=0;i<max_Patients;i++){
        if(user_ID==clinic->IDs[i].ID){
            printf("Hello %s\n",clinic->IDs[i].name);
            printf("age:%d\n",clinic->IDs[i].age);
            printf("gender:%c\n", clinic->IDs[i].gender);
            printf("your Slots is \n");
            for(int k=0;k<max_slots;k++){
                if(clinic->IDs[i].ID == clinic->Avilable_Slots[k]){
                    slot_by_hours_not_id=first_time+0.5*k;
                    printf("%0.2f PM\n",slot_by_hours_not_id);
                }
            }

            flag=1;
        }
    }

    if(flag==0){
        printf("wrong ID .. \n");
    }

}
