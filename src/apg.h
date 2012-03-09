
typedef struct _APGPassword APGPassword;
typedef struct _APGPasswords APGPasswords;
typedef struct _APGPasswordProps APGPasswordProps;
typedef enum _APGMode APGMode;

struct _APGPasswords {
    /* array of generated passwords */
    //GList * passwords;
    int nothing;
};

struct _APGPassword {
    /* should be in secure memory */
    char * phonetic;
    char * password;
};

enum APGMode {
    USE_SYMBOLS = 0x1,
    USE_NUMBERIC = 0x2,
    USED_MIXED_CASE = 0x4
};

struct _APGPasswordProps {
    unsigned short min_pass_len;
    unsigned short max_pass_len;
    /* cl_seed random seed */
};

APGPassword  * apg_password(APGPasswordProps *props, APGMode *mode);
APGPasswords * agg_password_list(APGPasswordProps *props, APGMode *mode);

void test_apg();
