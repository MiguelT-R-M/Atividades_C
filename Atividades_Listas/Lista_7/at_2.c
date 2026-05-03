#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define stringLength(x) (sizeof(x)/sizeof(x[0]))

typedef struct citadel{

    char Name[50];
    int Population;
    char Periculosity[50];
    int Periculo_quant;
    char Function[50];

} cit;

void citOrder(cit **Cidadelas, int Cid_quant);
int getKey(char *BUFFER, int BUFFER_size);
void getValues(char *BUFFER, int BUFFER_size, cit **Cidadelas, int Cid_quant);
void nameCorrect(char *Name, int Name_size, char *Func, int Func_size);
void checkNull(void *Pointer);

int main(void){

    char BUFFER[201];
    cit *Cidadelas = NULL; int Cid_quant = 0;
    int KEY = -1;

    while((fgets(BUFFER, sizeof(BUFFER), stdin)!= NULL)){
        
        BUFFER[strcspn(BUFFER, "\r\n")] = 0;
        if(strcmp(BUFFER, "-")==0){
            break;
        }
        
        int BUFFER_size = strlen(BUFFER);
        int Is_key = 0;

        for(int i = 0; i<BUFFER_size; i++){
            if(BUFFER[i]==33){
                Is_key = 1;
            }
        }

        if(Is_key == 1){
            KEY = getKey(BUFFER, BUFFER_size);

        }else{
            Cid_quant++;
            cit *TEMPOINTER = realloc(Cidadelas, Cid_quant*(sizeof(*Cidadelas)));
            checkNull(TEMPOINTER);
            Cidadelas = TEMPOINTER;
            getValues(BUFFER, BUFFER_size, &Cidadelas, Cid_quant);
        }

        
    }

    citOrder(&Cidadelas, Cid_quant);

    if((KEY == -1)||(Cid_quant==0)){
        printf("Gingrey ainda não foi achada, vamos esperar mais um pouco.\n");
    }else if((Cid_quant>0)&&(KEY<=Cid_quant)){
        printf("Gingrey foi encontrada em %s, uma cidadela com %d mil habitantes cuja função é %s e periculosidade %s.", Cidadelas[KEY-1].Name, Cidadelas[KEY-1].Population, Cidadelas[KEY-1].Function, Cidadelas[KEY-1].Periculosity);
        
        if((Cidadelas[KEY-1].Population>=1000)&&(Cidadelas[KEY-1].Periculo_quant>3)){
            printf(" Talvez seja melhor desistir...");
        }else if(Cidadelas[KEY-1].Population>=1000){
            printf(" Um lugar denso, vai ser difícil achar ela.");
        }else if(Cidadelas[KEY-1].Periculo_quant>3){
            printf(" Vai ser complicado entrar lá.");
        }

        printf("\n");
    }

    if(Cid_quant>0){free(Cidadelas);}
    return 0;
}

void citOrder(cit **Cidadelas, int Cid_quant){
    for(int i = 0; i<Cid_quant; i++){
        for(int j = i+1; j<Cid_quant; j++){
            if((*Cidadelas)[i].Population<(*Cidadelas)[j].Population){
                cit TEMPCIT = (*Cidadelas)[i];
                (*Cidadelas)[i] = (*Cidadelas)[j];
                (*Cidadelas)[j] = TEMPCIT;
            }else if(((*Cidadelas)[i].Population==(*Cidadelas)[j].Population)&&((*Cidadelas)[i].Periculo_quant<(*Cidadelas)[j].Periculo_quant)){
                cit TEMPCIT = (*Cidadelas)[i];
                (*Cidadelas)[i] = (*Cidadelas)[j];
                (*Cidadelas)[j] = TEMPCIT;
            }else if(((*Cidadelas)[i].Population==(*Cidadelas)[j].Population)&&((*Cidadelas)[i].Periculo_quant==(*Cidadelas)[j].Periculo_quant)&&(strcmp((*Cidadelas)[i].Name, (*Cidadelas)[j].Name)>0)){
                cit TEMPCIT = (*Cidadelas)[i];
                (*Cidadelas)[i] = (*Cidadelas)[j];
                (*Cidadelas)[j] = TEMPCIT;
            }
        }
    }
}

int getKey(char *BUFFER, int BUFFER_size){

    int TEMPKEY = 0;
    for(int i = 0; i<BUFFER_size; i++){
        char Current_char = BUFFER[i];

        if((Current_char>='0')&&(Current_char<='9')){
            TEMPKEY*=10;
            TEMPKEY+=(Current_char-'0');
        }
    }

    return TEMPKEY;

}

void getValues(char *BUFFER, int BUFFER_size, cit **Cidadelas, int Cid_quant){

    char TEMPNAME[50] = {'\0'}; int Name_index = 0;
    int TEMPOP = 0;
    char TEMPERIL[50] = {'\0'}; int Peril_index = 0;
    char TEMPFUNC[50] = {'\0'}; int Func_index = 0;
    char Previous_char = '-';

    for(int i = 0; i<BUFFER_size; i++){
        char Current_char = BUFFER[i];

        if((Current_char>='A')&&(Current_char<='Z')){
            TEMPNAME[Name_index] = Current_char;
            Name_index++;
        }
        if((Current_char>='0')&&(Current_char<='9')){
            TEMPOP*=10;
            TEMPOP+=(Current_char-'0');
        }
        if(Current_char=='*'){
            TEMPERIL[Peril_index] = Current_char;
            Peril_index++;
        }
        if((Current_char == ' ')&&(Previous_char == ' ')&&((i+1)<BUFFER_size)){
            TEMPFUNC[Func_index] = BUFFER[i+1];
            Func_index++;
        }

        Previous_char = Current_char;
    }

    nameCorrect(TEMPNAME, strlen(TEMPNAME), TEMPFUNC, strlen(TEMPFUNC));

    strcpy((*Cidadelas)[Cid_quant-1].Name, TEMPNAME);
    (*Cidadelas)[Cid_quant-1].Population = TEMPOP;
    strcpy((*Cidadelas)[Cid_quant-1].Periculosity, TEMPERIL);
    (*Cidadelas)[Cid_quant-1].Periculo_quant = Peril_index;
    strcpy((*Cidadelas)[Cid_quant-1].Function, TEMPFUNC);

}

void nameCorrect(char *Name, int Name_size, char *Func, int Func_size){

    for(int i = 0; i<Name_size; i++){
        if((i==0)&&((Name[i]>='a')&&(Name[i]<='z'))){
            Name[i] = Name[i]-32;
        }
        if((i>0)&&((Name[i]>='A')&&(Name[i]<='Z'))){
            Name[i] = Name[i]+32;
        }
    }
    for(int i = 0; i<Func_size; i++){
        if((i==0)&&((Func[i]>='a')&&(Func[i]<='z'))){
            Func[i] = Func[i]-32;
        }
        if((i>0)&&((Func[i]>='A')&&(Func[i]<='Z'))){
            Func[i] = Func[i]+32;
        }
    }

}

void checkNull(void *Pointer){
    if(Pointer == NULL){
        printf("Erro de memória.");
        exit(1);
    }
}

