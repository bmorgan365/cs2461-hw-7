#include <stdio.h>
#include <stdlib.h>
#include "hashmap.h"

int main(void){
        struct hashmap* hashMap = (struct hashmap*) malloc(sizeof(struct hashmap));
        char cont = 'n';
        int docID;
        int index;
        char filename [7];
        char curWord [15];
        char curChar;
        FILE *doc;
        do{
            printf("Enter the filename to process: ");
            scanf("%s", filename);
            doc = fopen(filename, "r");                 //if file doesn't exist, still open
            docID = filename[1];
            index = 0;                                  //used for index of string entry
            curChar = fgetc(doc);                        //first character of document
            
            while(curChar != EOF){                      //while current character is not EOF
                if(curChar != ' ' || curChar != '\n'){             //while
                    curWord[index] = curChar;
                    index++;
                }
                else{
                    curWord[index] = '\0';
                    printf("Word is %s | Doc ID is %d\n", curWord, docID);
                    //perform ish with has table
                    index = 0;
                }
                curChar = fgetc(doc);
            }
            fclose(doc);                                //close file once done manipulation
            printf("Press 'y' to continue. . . ");       //continue with different file
            scanf("%c%c", &cont);
            printf("%c", cont);

        }while(cont == 'y' || cont == 'Y');
        hm_destroy(hashMap);
        return 0;
}
