#include <stdio.h>
#include <stdlib.h>

struct code{
    int *rotory[6];
    int licznik[2];
};

int getch(FILE *fp){
    int r = getc(fp);
    if(r == 32 || r == 10)
        r = getch(fp);
    return r;
}

int per(char litera, int *R){
        int x = litera + R[litera-'A'];
        if(x<='Z' && x>='A')
            return x;
        else if(x<'A' && x<'Z')
            return x+26;
        else
            return x-26;
}

int *rot(int *R){
    int i;
    int tmp[26];
    for(i=0;i<26;i++){
        tmp[i]=R[i];
    }
    for(i=1;i<26;i++){
        R[i] = tmp[i-1];
    }
    R[0]=tmp[25];
    return R;
}

int main()
{
    int L[26] =   {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int R11[26] = {4,9,10,2,7,1,-3,9,13,16,3,8,2,9,10,-8,7,3,0,-4,-20,-13,-21,-6,-22,-16};
    int R12[26] = {20,21,22,3,-4,-2,-1,8,13,16,-9,-7,-10,-3,-2,4,-9,6,0,-8,-3,-13,-9,-7,-10,-16};
    int R21[26] = {0,8,1,7,14,3,11,13,15,-8,1,-4,10,6,-2,-13,0,-11,7,-6,-5,3,-17,-2,-10,-21};
    int R22[26] = {0,8,13,-1,21,17,11,4,-3,-8,-7,-1,2,6,10,5,0,-11,-14,-6,-13,2,-10,-15,-3,-7};
    int R31[26] = {1,2,3,4,5,6,-4,8,9,10,13,10,13,0,10,-11,-8,5,-12,-19,-10,-9,-2,-5,-8,-11};
    int R32[26] = {19,-1,4,-2,11,-3,12,-4,8,-5,10,-6,9,0,11,-8,8,-9,5,-10,2,-10,-5,-13,-10,-13};
    int R41[26] = {4,17,12,18,11,20,3,-7,16,7,10,-3,5,-6,9,-4,-3,-12,1,-13,-10,-18,-20,-11,-2,-24};
    int R42[26] = {7,24,20,18,-4,12,13,6,3,-3,10,4,11,3,-12,-11,-7,-5,-17,-1,-10,-18,2,-9,-16,-20};
    int R51[26] = {21,24,-1,14,2,3,13,17,12,6,8,-8,1,-6,-3,8,-16,5,-6,-10,-4,-7,-17,-19,-22,-15};
    int R52[26] = {16,1,22,8,19,17,-2,6,-3,10,15,3,6,-1,7,-6,4,-14,-8,-13,-12,-21,-5,-8,-17,-24};
    int REF[26] = {24,16,18,4,12,13,5,-4,7,14,3,-5,2,-3,-2,-7,-12,-16,-13,6,-18,1,-1,-14,-24,-6};
    struct code set;
    FILE *fpr = fopen("tekst.txt", "r");
    int i;
    int l = fgetc(fpr);
    int m;
    while(l!=10){
        if(l!=32){
        m = fgetc(fpr);
            if(l>m){
                L[l-'A'] = m-l;
                L[m-'A'] = l-m;
            }
            else if(l<m){
                L[l-'A'] = m-l;
                L[m-'A'] = l-m;
            }
        }
        l = fgetc(fpr);
    }
    int r = 0;
    for(i=0;i<3;i++){ //ustawianie rotorow z pliku
        r = getch(fpr)-'0';
        if(r == 1){
            if(i==0){
                set.rotory[i] = R11;
                set.rotory[i+5] = R12;
            }
            else if(i==1){
                set.rotory[i] = R11;
                set.rotory[i+3] = R12;
            }
            else{
                set.rotory[i] = R11;
                set.rotory[i+1] = R12;
            }
        }
        if(r == 2){
            if(i==0){
                set.rotory[i] = R21;
                set.rotory[i+5] = R22;
            }
            else if(i==1){
                set.rotory[i] = R21;
                set.rotory[i+3] = R22;
            }
            else{
                set.rotory[i] = R21;
                set.rotory[i+1] = R22;
            }
        }
        if(r == 3){
            if(i==0){
                set.rotory[i] = R31;
                set.rotory[i+5] = R32;
            }
            else if(i==1){
                set.rotory[i] = R31;
                set.rotory[i+3] = R32;
            }
            else{
                set.rotory[i] = R31;
                set.rotory[i+1] = R32;
            }
        }
        if(r == 4){
            if(i==0){
                set.rotory[i] = R41;
                set.rotory[i+5] = R42;
            }
            else if(i==1){
                set.rotory[i] = R41;
                set.rotory[i+3] = R42;
            }
            else{
                set.rotory[i] = R41;
                set.rotory[i+1] = R42;
            }
        }
        if(r == 5){
            if(i==0){
                set.rotory[i] = R51;
                set.rotory[i+5] = R52;
            }
            else if(i==1){
                set.rotory[i] = R51;
                set.rotory[i+3] = R52;
            }
            else{
                set.rotory[i] = R51;
                set.rotory[i+1] = R52;
            }
        }
    }
    fscanf(fpr,"%d", &set.licznik[0]);
    fscanf(fpr,"%d", &set.licznik[1]);
    int buff = getch(fpr);  //tu zaczyna sie szyfrownie wlasciwe
    FILE *fpw = fopen("szyforgram.txt", "w");
    while(buff!=EOF){
        buff = per(buff,L);
        buff = per(buff,set.rotory[0]);
        buff = per(buff,set.rotory[1]);
        buff = per(buff,set.rotory[2]);
        buff = per(buff,REF);
        buff = per(buff,set.rotory[3]);
        buff = per(buff,set.rotory[4]);
        buff = per(buff,set.rotory[5]);
        buff = per(buff,L);
        fprintf(fpw, "%c", buff);
        rot(set.rotory[0]);
        rot(set.rotory[5]);
        set.licznik[0]++;
        if(set.licznik[0]==27){
            rot(set.rotory[1]);
            rot(set.rotory[4]);
            set.licznik[1]++;
            if(set.licznik[1]==27){
                rot(set.rotory[2]);
                rot(set.rotory[3]);
                set.licznik[1]=1;
            }
            set.licznik[0]=1;
        }
        buff = getch(fpr);
    }
    fclose(fpr);
    fclose(fpw);
    return 0;
}
