%{
	
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TITLE "TITLE"
#define SPORT "SPORT"
#define NAME "NAME"
#define YEARS "YEARS"
#define YEAR_NUM "YEAR_NUM"
#define COMMA "COMMA"
#define THROUGH "THROUGH"
#define SINCE "SINCE"
#define ALL "ALL"


union{ // we added one more at the size because of the "\n".
	char TITLE[14];
	char SPORT[8];
	char YEARS[8];
	char NAME[80];
	char YEAR_NUM[5];
	char COMMA[2];
	char THROUGH[8];
	char SINCE[6];
	char ALL[4];
	
} yylval;
%}
%option noyywrap
%x SPORT_TYPE

%%
"Olympic Games" { 
    strcpy(yylval.title, "Olympic Games");
    return TITLE;
}
"<sport>" { 
    return SPORT;
}
"<years>" { 
    return YEARS;
}
"," {
	strcpy(yylval.COMMA, yytext);
    return COMMA;	
}
"-"|"through" {
	strcpy(yylval.THROUGH, yytext);
	return THROUGH;
}
[ \t\n] +  /* skip white space */

"since" {
	strcpy(yylval.SINCE, "since");
    return SINCE;
}
\" {
	BEGIN (SPORT_TYPE); 
}
<SPORT_TYPE>.+

[1-9][0-9]* { 
    strcpy(yylval.YEAR_NUM, yytext);
    return YEAR_NUM;
}
. { 
	fprintf(stderr, "unrecognized token %c\n", yytext[0]); 
}

%%
void nakedString(char* string, int length) {
	for (int i = 0; i < length-1; i++) {
		string[i] = string[i+1];
	}
	string[length-2] = '\0';
}

void main(int argc , char** argv){
	if(argc != 2){
		printf("Not All The Arguments Passed\n");
		exit(1);
	}
	int token;
	print("%-30s %-30s %-30s\n", "TOKEN", "LEXEME", "SEMANTIC VALUE");//print the titles
	print("-----------------------------------------------------------------------\n");
	yyin = fopen(argv[1],"r");
	while(token = yylex()) != 0){
		switch(token){
			case TITLE:
				printf("%-30s\n", yylval.TITLE);
				break;
			case SPORT:
			case YEARS:
				printf("\n");
				break;
			case NAME:
				nakedString(yylval.NAME, strlen(yylval.NAME));
				printf("%-30s\n", yylval.NAME);
				break;
			case YEAR_NUM:
				printf("%-30s\n", yylval.YEAR_NUM);
				break;
			case COMMA:
				printf("%-30s\n", yylval.COMMA);
				break;
			case THROUGH:
				printf("%-30s\n", yylval.THROUGH);
				break;
			case SINCE:
				printf("%-30s\n", yylval.SINCE);
				break;
			case ALL:
				printf("%-30s\n", yylval.ALL);
				break;
		}
		}
		
	}
}
