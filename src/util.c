#include <util.h>

int get_int(FILE *input_buffer)
{
    char tmp_buffer[20];
    fgets(tmp_buffer, 20, input_buffer);
    return atoi(tmp_buffer);
}

char *parse_name(char *name)
{
    char *pt = strrchr(name,'.');
    char *dash = strrchr(name, '/');
    
    if(!dash) dash = name-1;
    if(!pt || pt < dash)
        pt = name + strlen(name);

    char *parsed = malloc(pt - dash);
    for(int i=0;;i++){
        if(++dash == pt){
            parsed[i] = '\0';
            break;
        }
        parsed[i] = *dash;
    }
    return parsed;
}

FILE* take_output(FILE* input)
{
    char* input_file_name = parse_name(input);
    char* output_file_name = malloc(strlen(input_file_name) + 5);
    sprintf(output_file_name, "%s.out", input_file_name);
    
    FILE* output = fopen(output_file_name,"w");
    free(input_file_name);
    free(output_file_name);

    return output;
}

void write_answers(int* ans,int gems,FILE* out)
{
    for(int i=0;i<gems;i++){
        if(ans[i]>10000) fprintf(out,"N\n");
        else fprintf(out,"S %d\n",ans[i]);
    }
}
