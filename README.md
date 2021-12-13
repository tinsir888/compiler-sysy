# Compiler-SysY-NKUCS
NKU CS major compulsory course, taught by Prof. Wang Gang. Finish a compiler of language SysY(A subset of language C), by using auxiliary tools bison and yacc.

## Lexical Analyzer
- In this experiment, you need to design a formal definition based on the language features supported by the compiler you design. You will use the Flex tool to implement a lexical analyzer to recognize all words in the program and convert them into word streams. That is to say: In this experiment, you need to use Flex to complete such a program. Its input is a SysY language program, and its output is the category, morphemes, and necessary attributes of each grammatical unit. (For example, for NUMBER, it will have its "number" attribute; for ID, it will have its "serial number" in the symbol table, and some identifiers will have the same "serial number".) This requires designing a symbol table.
- Of course, the current symbol table items are only simple content such as morphemes, but the data structure of the symbol table, search algorithms, storage of morphemes, and processing of reserved words can all be considered.
- You need to verify your program: input a simple source program, output the morpheme content, word category and attributes of each word in the word stream (the attributes of constants can be numeric values, and identifiers can be pointers to symbol tables).
