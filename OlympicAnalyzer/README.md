Using Flex
-
* Using Flex (Fast Lexical Analyzer Generator) to analyze input file and return tokens.
* Useful link of Flex can be found here: https://www.geeksforgeeks.org/flex-fast-lexical-analyzer-generator/
---

Example of analyzing Olympic data
-
1. olympic.lex - used as "command" file for Flex compiler. Generate the C file.
```
flex.exe olympic.lex
```
2. olympic.c - the generated result file from the Flex compiler, in C language. Compile the file using GCC compiler:
```
gcc olympic.c -o OlympicAnalyzer.exe
```
3. Run the program to generate Tokens:
```
OlympicAnalyzer.exe data.txt
``` 
You can find the necessary tools under the Tools directory.

---

TODO
-
- [ ] Add example to input file.
- [ ] Add the compiled file.
- [ ] Add GIFs with examples.
- [ ] Document the code.
- [ ] Finish the example.