%{
int wordCount = 0;
%}
chars [A-Za-z\_\'\.\"]
numbers ([0-9])+
delim [" "\n\t]
whitespace {delim}+
words {chars}+
%%
{words} {wordCount++;}
%%
int  main() {
    yylex();
    printf("no of words: %d\n", wordCount);
    return 0;
}
int yywrap() {
    return 1;
}
