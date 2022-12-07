/* this is modified from our textbook on page 170 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void *runner(void *param);      /* threads call this function */
float averageFile(int section);

int main(int argc, char *argv[]){

    pthread_t thread1;  /*thread identifier*/
    pthread_t thread2;  /*thread identifier*/
    pthread_t thread3;  /*thread identifier*/
    pthread_t thread4;  /*thread identifier*/
    pthread_attr_t attr;   /*set of thread attributes */

 /*   for (int i=0; i <= 3; i++){
        *argv[i] = ("%s", i);
        cout << argv[i];
    }*/

    char* first = (char*)"0";
    char* second = (char*)"1";
    char* third = (char*)"2";
    char* fourth = (char*)"3";
    float* ret1;
    float* ret2;
    float* ret3;
    float* ret4;
    float ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh_Brain_Hurts_and_no_sleep;


    pthread_attr_init(&attr);  /* set the default attributes of the thread */
    pthread_create(&thread1, &attr, &runner, first);  /* create the thread */
    pthread_create(&thread2, &attr, &runner, second); 
    pthread_create(&thread3, &attr, &runner, third); 
    pthread_create(&thread4, &attr, &runner, fourth); 

    pthread_join(thread1, (void**) &ret1); /* wait for thread to exit */
    pthread_join(thread2, (void**) &ret2); /* wait for thread to exit */
    pthread_join(thread3, (void**) &ret3); /* wait for thread to exit */
    pthread_join(thread4, (void**) &ret4); /* wait for thread to exit */

    printf("thread: %ld\n", thread1);
    printf("thread: %ld\n", thread2);
    printf("thread: %ld\n", thread3);
    printf("thread: %ld\n", thread4);

    ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh_Brain_Hurts_and_no_sleep = (*ret1 + *ret2 + *ret3 + *ret4)/4;

    cout << "\n\nThe total average character length of the wordlist is: " << ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh_Brain_Hurts_and_no_sleep << endl;

    return 0;
}
/* this is the function the threads execute */
void* runner(void *param){
    char *section;
    section = (char *) param;
    float total;
    float* returnTotal = (float*)malloc(sizeof(float));
    //float* threadReturn = (void*) malloc(sizeof(float));
    

    if (section == "0") {
        printf("Thread ID [0-4]: %s\n", section), "\n";
        total = averageFile(1);
        cout << "Average charaters in thread 1: " << total << endl;
    }
    if (section == "1") {
        printf("Thread ID [0-4]: %s\n", section, "\n");
        total = averageFile(2);
        cout << "Average charaters in thread 2: " << total << endl;
    }
    if (section == "2") {
        printf("Thread ID [0-4]: %s\n", section), "\n";
        total = averageFile(3);
        cout << "Average charaters in thread 3: " << total << endl;
    }
    if (section == "3") {
        printf("Thread ID [0-4]: %s\n", section, "\n");
        total = averageFile(4);
        cout << "Average charaters in thread 4: " << total << endl;
    }
    *returnTotal = total;
    return (void*) returnTotal;

    pthread_exit(0);
}

float averageFile(int n) {
        ifstream wordlist;
        string individual;
        wordlist.open("common.txt");
        string fillerSet1 = ".@_~012345";
        string fillerSet2 = "6789aAbBcCdDeEfF";
        string fillerSet3 = "gGhHiIjJkKlLmMnNoOpP";
        string fillerSet4 = "qQrRsStTuUvVwWxXyYzZ";
        //cout << filler.substr(0,10) << " " << filler.length() << "\n" << endl;
        float returnVal;
        int totalWords = 0;
        while (wordlist >> individual) {
            if (n==1){
                for (int i=0; i <= fillerSet1.length(); i++) {
                    if (individual[0]==fillerSet1[i]) {

                        returnVal += individual.length();
                        totalWords += 1;

                    }
                }
                /*if ( fillerSet1.find(to_string(individual[0])) < fillerSet1.length() ) {
                    cout << "Found individual in filler1\n" << individual[0] << " " << individual << " " << fillerSet1.find(to_string(individual[0])) << endl;
                }*/
            }
            else if (n==2){
                for (int i=0; i <= fillerSet2.length(); i++) {
                    if (individual[0]==fillerSet2[i]) {

                        returnVal += individual.length();
                        totalWords += 1;
                    }
                }
            }
            else if (n==3){
                for (int i=0; i <= fillerSet3.length(); i++) {
                    if (individual[0]==fillerSet3[i]) {

                        returnVal += individual.length();
                        totalWords += 1;
                    }
                }
            }
            else if (n==4){
                for (int i=0; i <= fillerSet4.length(); i++) {
                    if (individual[0]==fillerSet4[i]) {

                        returnVal += individual.length();
                        totalWords += 1;
                    }
                }
            }
        }
    return returnVal = (returnVal/totalWords);
}