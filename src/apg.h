#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "owntypes.h"

typedef struct _APGPassword APGPassword;
typedef struct _APGPasswordProps APGPasswordProps;
typedef struct _APGObject APGObject;
typedef enum _APGMode APGMode;

struct _APGPassword {
    /* should be in secure memory */
    char *phonetic;
    char *password;
};

struct _APGPasswordProps {
    unsigned short min_pass_len;
    unsigned short max_pass_len;
    boolean enforce_mode;
    /* cl_seed random seed */
};

struct _APGObject {
    APGPassword apgpasswd;
    APGPasswordProps props;
    int mode;
};

APGObject*      apg_init             ();
boolean         apg_destroy          (APGObject *obj);
void            apg_password         (APGObject *obj);

void test_apg();
