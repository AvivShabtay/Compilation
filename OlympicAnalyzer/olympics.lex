%{
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
%x COMMENT

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
, {
	strcpy(yylval.comma, yytext);
    return COMMA;	
}
"-"|"through" {
	strcpy(yylval.through, yytext);
	return THROUGH;
}
[ \t\n]+  /* skip white space */

\""\" { 
	BEGIN (SPORT_TYPE); 
}
<SPORT_TYPE>.+
<SPORT_TYPE>." 

{  /* end of sport name --> resume normal processing */
	BEGIN (0); 
}
. { 
	fprintf(stderr, "unrecognized token %c\n", yytext[0]); 
}

%%

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
			case :
			case :
			case :
			case :
			case :
		}
		
	}
}
