#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    
    int *users=(int*)malloc(sizeof(int)*1000000);
    int *uniqueUsers=(int*)malloc(sizeof(int)*1000000);
    int *uniqueUserId=(int*)malloc(sizeof(int)*1000000);
    for (int i = 0; i < 100000; i++) {
        uniqueUserId[i] = 0;
    }
    int size = 0;
    for (int i = 0; i < 1000000; i++) {
        uniqueUsers[i] = -1;
    }
    char c;
    int scan;
    int id;
    int range1 = 0;
    int range2 = 0;
    printf("Requests:\n");
    while((scan = (scanf(" %c", &c) != EOF))){
        if(c == '+'){
            if(scanf(" %d", &id) != 1 || id < 0 || id > 99999 || size > 999999){
                printf("Invalid input.\n");
                return 0;
            }
            uniqueUserId[id]++;
            

            /*
            
            
            for (int i = 0; i < size;i++) {

                if(id == users[i]){
                    visitsPerUser++;
                    repeat++;
                }
            }*/
            users[size] = id;
            size++;
            if(uniqueUserId[id] == 1){
                printf("> first visit\n");
            }
            else{
                printf("> visit #%d\n", uniqueUserId[id]);
            }
        }
        else if(c == '?'){
            if(scanf("%d %d", &range1,&range2) !=2){
                printf("Invalid input.\n");
                return 0;
            }
            if(range1 < 0){
                printf("Invalid input.\n");
                return 0;
            }
            if(range1 > range2){
                printf("Invalid input.\n");
                return 0;
            }
            if(range2 >= size){
                printf("Invalid input.\n");
                return 0;
            }
            int unique=range2-range1+1;
            
            for (int i = range1; i < range2+1; i++) {
                id = users[i];
                uniqueUsers[i] = id;
                int tmp = 0;
                for (int j = range1; j<range2+1; j++) {
                    
                    if(users[i] == uniqueUsers[j]){
                        tmp++;
                        
                    }
                    
                }
                if(tmp > 1){
                    uniqueUsers[i] = -1;
                    unique--;
                }
                
            }
            
            printf("> %d / %d\n", unique, range2-range1+1);
            
        }
        else{
            printf("Invalid input.\n");
            return 0;
        }
    }
    
    free(users);
    free(uniqueUsers);
    free(uniqueUserId);
    return 1;
}
