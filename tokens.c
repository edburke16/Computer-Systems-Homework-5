#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

    char buffer[1024];
    char tokens[100][256]; 

    printf("tokens$ ");
    while (fgets(buffer, sizeof(buffer), stdin) != NULL){
        memset(tokens, 0, 25600);
        int t = 0, k = 0; 
        for(unsigned long j = 0; j < sizeof(buffer); j++){
            if(buffer[j] == '\0'){
                break;
            }
            switch(buffer[j]) {
                case '\n':
                    break;

                case ' ' :
                    k = 0;
                    while(buffer[++j] == ' ');
                    j--;
                    ++t;
                    break;

                case '\t' :
                    k = 0;
                    while(buffer[++j] == '\t');
                    j--;
                    ++t;
                    break;

                case ';' :
                    ++t;
                    k = 0;
                    tokens[t][k] = buffer[j];
                    ++t;
                    break;

                case '&' :
                    ++t;
                    k = 0;
                    tokens[t][k] = buffer[j];
                    if(buffer[j + 1] == '&') {
                        tokens[t][k+1] = buffer[j];
			j++;
                    }
                    ++t;
                    break;

                case '>' :
                    ++t;
                    k = 0;
                    tokens[t][k] = buffer[j];
                    ++t;
                    break; 

                case '<' :
                    ++t;
                    k = 0;
                    tokens[t][k] = buffer[j];
                    ++t;
                    break; 

                case '|' :
                    ++t;
                    k = 0;
                    tokens[t][k] = buffer[j];
                    if(buffer[j + 1] == '|') {
                        tokens[t][k+1] = buffer[j];
			j++;
                    }
                    ++t;
                    break; 
                    
                default :
                    tokens[t][k] = buffer[j];
                    ++k;
            }
        }

        for(int i=0; i<t + 1; i++ ) {
            printf("%s\n", tokens[t-i]);
        }    
        
        printf("tokens$ ");
    }
  return 0;
}
