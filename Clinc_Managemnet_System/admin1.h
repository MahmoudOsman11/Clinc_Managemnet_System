

#define max_Patients 100
#define max_slots 6
#define first_time 2
#define last_time 4.5
typedef struct {

    char name[50];
    char age;
    char gender;
    unsigned int ID;


}patient;

typedef struct {
    patient IDs[max_Patients];
    float Avilable_Slots[max_slots];
    int patient_counter;

}Clinic;


void admin(Clinic *clinic,unsigned int *Attempts);
void add_patient(Clinic *clinic);
void Edit_patient_record(Clinic *clinic);
void Reserve_slot(Clinic *clinic);
void Cancel_reservation(Clinic *clinic);
