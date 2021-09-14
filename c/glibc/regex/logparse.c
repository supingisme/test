LONG logparse(CHAR *buf, VOS_SYSLOG_ITEM *log_item)
{
	//匹配侧字符串: [DEBUG][OM-DU] 2020.4.2 9:7:42: Recving message
    INT status;
    INT cflags = REG_EXTENDED;
    regmatch_t pmatch[6];
    const size_t nmatch = 6;
    regex_t reg;
    CHAR *pattern = NULL;
    if(log_item == NULL || buf == NULL)
    {
        return VOS_ERROR;
    }

    const CHAR *debug_pattern = "\\$\\[(\\w*)\\]\\[(\\w*)\\]\\[(.*)\\] ([0-9]*\\.[0-9]*\\.[0-9]* [0-9]*:[0-9]*:[0-9]*): (.*)";
    const CHAR *normal_pattern = "\\*\\[(\\w*)\\]\\[(\\w*)\\] ([0-9]*\\.[0-9]*\\.[0-9]* [0-9]*:[0-9]*:[0-9]*): (.*)";


    if(buf[0] == '$')
    {
        pattern = (CHAR *)debug_pattern;
    }else if(buf[0] == '*'){
        pattern = (CHAR *)normal_pattern;
    }else{
        // printf("invalid head:%c\r\n", buf[0]);
        return VOS_ERROR;
    }

    VOS_MemZero(pmatch, sizeof(pmatch));

    regcomp(&reg,pattern,cflags);
    status = regexec(&reg,buf,nmatch,pmatch,0);
    if(status == REG_NOMATCH)
    {
        regfree(&reg);
        return VOS_ERROR;
    }
    else if(status == 0)
    {
        INT len = 0;

        // len = pmatch[0].rm_eo - pmatch[0].rm_so;
        len = pmatch[1].rm_eo - pmatch[1].rm_so;
        VOS_StrnCpy(log_item->title, buf+pmatch[1].rm_so, len);  
        switch(log_item->title[0])
        {
            case 'C':
                log_item->color = FG_YELLOW;
                break;
            case 'E':
                log_item->color = FG_RED;
                break;
            case 'W':
                log_item->color = FG_PURPLE;
                break;
            case 'I':
                log_item->color = FG_BLUE;
                break;
            case 'D':
                log_item->color = FG_CYAN;
                break;
        }

        len = pmatch[2].rm_eo - pmatch[2].rm_so;
        VOS_StrnCpy(log_item->module_name, buf+pmatch[2].rm_so, len);  

        if(buf[0] == '$')
        {
            len = pmatch[3].rm_eo - pmatch[3].rm_so;
            VOS_StrnCpy(log_item->info_ptr, buf+pmatch[3].rm_so, len);  

            len = pmatch[4].rm_eo - pmatch[4].rm_so;
            VOS_StrnCpy(log_item->timestamp, buf+pmatch[4].rm_so,len);  

            len = pmatch[5].rm_eo - pmatch[5].rm_so;
            VOS_StrnCpy(log_item->Log_content, buf+pmatch[5].rm_so,len);  

        }else{
            len = pmatch[3].rm_eo - pmatch[3].rm_so;
            VOS_StrnCpy(log_item->timestamp, buf+pmatch[3].rm_so,len);  

            len = pmatch[4].rm_eo - pmatch[4].rm_so;
            VOS_StrnCpy(log_item->Log_content, buf+pmatch[4].rm_so,len);  
        }
        if(log_item->Log_content[len - 1] == '\n')
        {
            log_item->Log_content[len - 1] = '\0';
        }
        if(log_item->Log_content[len - 1] != '\0')
	    {
		    log_item->Log_content[len] = '\0';
	    }
    }
    
    regfree(&reg);
    
    return VOS_OK;
}
