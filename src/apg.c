#include <stdio.h>
#include <time.h>

#include "apg.h"
#include "pronpass.h"
#include "rnd.h"
#include "restrict.h"

#define S_NB    0x01 /* Numeric */
#define S_SS    0x02 /* Special */
#define S_CL    0x04 /* Capital */
#define S_SL    0x08 /* Small   */

APGPassword * 
apg_password(APGPasswordProps *props, APGMode *mode)
{
}

void
test_apg() {
    APGPassword* apgpasswd;
    //char * pstr;
    //char * pho;  
    //time_t t;
    int filter_check_result = 0;

    //t = time(NULL);
    //x917_setseed((UINT32)time(NULL), FALSE);
    apgpasswd->password = (char *)calloc(1, (size_t)(10+1));
    apgpasswd->phonetic = (char *)calloc(1, (size_t)(10*18));
    //apgpasswd->password = calloc(max_len, sizeof(char *));
    //apgpasswd->phonetic = calloc(max_len, sizeof( (char *) * 18));

    do {
    

        printf("password creation\n");
        //gen_pron_pass(apgpasswd->password, apgpasswd->phonetic, 5, 10, S_NB|S_SS|S_CL);
        //printf("passwd is %s phonetic  %s\n\n", apgpasswd->password, apgpasswd->phonetic);
        //filter_check_result = filter_check_pass(apgpasswd->password, S_NB|S_SS|S_CL);
        //printf("filter %i\n", filter_check_result);

        //free((void*)apgpasswd->password);
        //free((void*)apgpasswd->phonetic);
        filter_check_result++;

    } while(filter_check_result < 4);
    
}

