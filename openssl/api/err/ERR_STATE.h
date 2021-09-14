typedef struct err_state_st
{
    unsigned long pid;
    int err_flags[ERR_NUM_ERRORS];
    unsigned long err_buffer[ERR_NUM_ERRORS];
    char *err_data[ERR_NUM_ERRORS];
    int err_data_flags[ERR_NUM_ERRORS];
    const char *err_file[ERR_NUM_ERRORS];
    int err_line[ERR_NUM_ERRORS];
    int top,bottom;
} ERR_STATE;

