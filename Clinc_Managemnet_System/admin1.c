
#include "admin1.h"
int password=1234;

void admin(Clinic *clinic,unsigned int *Attempts){

int pass=0;
char choice=0;
printf("enter the Password ");
scanf("%d",&pass);
for(int i=0;i<7;i++){
    printf("*");
}
printf("\n");
if(pass==password){
    printf(" 1. Add new patient record: \n 2. Edit patient record \n 3. Reserve a slot with the doctor \n 4. Cancel reservation.\n");
    scanf("%d",&choice);
    switch (choice){

        case 1:
            add_patient(clinic);


            break;

        case 2:
            Edit_patient_record(clinic);

            break;
        case 3:
            Reserve_slot(clinic);

            break;

        case 4:
            Cancel_reservation(clinic);

            break;

        default :

            printf("not correct choice \n");
            break;
    }

}
else {
    *Attempts=*Attempts+1;
    printf("Wrong Password try again.. \n");
}

}



void add_patient(Clinic *clinic){
    char flag=0;

    if(clinic->patient_counter>=max_Patients){
        printf("Patient list is full.\n");
    }
    else{
        patient new_patient;

        printf("Enter patient name: ");
        scanf("%s",new_patient.name);
        printf("Enter patient age: ");
        scanf("%d", &new_patient.age);
        printf("Enter patient gender: ");
        scanf("%s", &new_patient.gender);
        printf("Enter patient ID: ");
        scanf("%d", &new_patient.ID);
        for(int i=0 ; i<max_Patients;i++){
        if(clinic->IDs[i].ID==new_patient.ID){

            printf("the patient is exist ");
            flag=1;
            break;
        }
        }
        if(flag==0){
            clinic->IDs[clinic->patient_counter]=new_patient;
            printf("patient added successfully \n");
            (clinic->patient_counter)++;

        }



    }


}

void Edit_patient_record(Clinic *clinic){
    unsigned int user_ID;

    printf("enter ID\n");
    scanf("%d",&user_ID);

    for(int i=0;i<max_Patients ;i++){
        if(user_ID==clinic->IDs[i].ID)
        {
        printf("ID exists \n *********\n",clinic->IDs[i].ID);
        printf("Enter new patient name: ");
        scanf("%s",clinic->IDs[i].name);
        printf("Enter new patient age: ");
        scanf("%d", &clinic->IDs[i].age);
        printf("Enter new patient ID: ");
        scanf("%d", &clinic->IDs[i].ID);
        break;
    }
    else{

        printf("incorrect ID \n");
        break;
    }

}
}

void Reserve_slot(Clinic *clinic){
    unsigned int user_ID;
    float slot;
    char flag=0;
    printf("the avilable Slots is \n");
    for(int i=0 ; i<max_slots;i++){
        if(clinic->Avilable_Slots[i]<13){
            printf("%0.2f \n",clinic->Avilable_Slots[i]);
        }
    }
    printf("enter the patient ID \n");
    scanf("%d",&user_ID);
    for(int i=0;i<max_Patients ;i++){
        if(user_ID==clinic->IDs[i].ID)
        {
            printf("ID exists \n *********\n",clinic->IDs[i].ID);
            printf("enter the slot: ");
            scanf("%f",&slot);
            for(int i=0 ; i<max_slots;i++){
            if(clinic->Avilable_Slots[i]==slot){
            clinic->Avilable_Slots[i]=user_ID;
            printf("Slot %f successfully Booked \n",slot);
            flag=1;
            }
    }
        }
    }
    if(flag==0){
        printf("Wrong ID .. Try again \n");
    }



}
void Cancel_reservation(Clinic *clinic){
    unsigned int User_ID;
    char flag=0;
    printf("Enter The ID : ");
    scanf("%d",&User_ID);
    for(int i=0;i<max_Patients;i++){
        if(User_ID==clinic->IDs[i].ID){
            for(int k=0;k<max_slots;k++){
                if(clinic->IDs[i].ID==clinic->Avilable_Slots[k]){
                    clinic->Avilable_Slots[k]=first_time+k*0.5;
                    flag=1;
                }
            }
        }
    }
    if(flag==0){
        printf("Wrong ID .. Try Again \n");
    }


}
