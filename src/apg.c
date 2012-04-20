#include "apg.h"
#include "pronpass.h"
#include "rnd.h"
#include "restrict.h"

APGObject*
apg_init()
{
    APGObject obj;
    return &obj;
}

boolean
apg_destroy(APGObject *obj)
{
    //pass for now
}

void
apg_password(APGObject *obj)
{
    APGPassword *apgpasswd = &obj->apgpasswd;
    APGPasswordProps *props = &obj->props;
    APGMode *mode = &obj->mode;

    do {
        gen_pron_pass(apgpasswd->password, apgpasswd->phonetic, 5, 10, S_NB|S_SS|S_CL);
    } while(filter_check_pass(apgpasswd->password, S_NB|S_SS|S_CL));
}

void
test_apg() {
    APGPassword _apgpasswd;
    APGPassword *apgpasswd = &_apgpasswd;
    time_t t;
    int filter_check_result = 0;
    int count = 0;

    t = time(NULL);
    x917_setseed((UINT32)time(NULL), FALSE);
    apgpasswd->password = calloc(1, (size_t)(10+1));
    apgpasswd->phonetic = calloc(1, (size_t)(10*18));

    do {
        count++;
        gen_pron_pass(apgpasswd->password, apgpasswd->phonetic, 5, 10, S_NB|S_SS|S_CL);
        printf("%s\n", apgpasswd->password);
        filter_check_result = filter_check_pass(apgpasswd->password, S_NB|S_SS|S_CL);
    } while(filter_check_result);
    printf("took %i tries", count);
    
}

