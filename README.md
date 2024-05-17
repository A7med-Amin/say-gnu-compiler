# SAY Compiler Project

![image](https://github.com/A7med-Amin/compiler/assets/80707696/1aeb1f1d-2189-43ce-aa21-0c1710e5a5dd)

## Requirements
#### you need to have bison and flex on your machine, you can download them from requirements folder

## How to run
#### make all   (Run compiler with terminal)
#### make runinputcode   (Run compiler on test file)
#### you can use GUI that makes the following commands for you and allows you to use text editor to write your code


The SAY Compiler Project involves the development of a YACC (Yet Another Compiler Compiler) parser for a custom programming language. YACC is utilized to generate syntax analyzers for compilers. The parser defined in this project includes rules and actions for handling various constructs such as:

- Variable and constant declarations
- Assignment statements
- Mathematical and Boolean expressions
- Conditional statements (if statements, switch cases)
- Loops (for, while, do-while loops)
- Function declarations and calls
- Block structures
- Print statements

The compilation process includes lexical analysis, syntax analysis, semantic analysis, and code generation. The output for each source code includes:

- Syntax handling file
- Semantic handling file
- Symbol table file
- Quadruples file

## Tools and Technologies Used

- **YACC (Yet Another Compiler Compiler)**: Tool for generating the parser.
- **C/C++ Libraries**: Includes standard headers such as `stdio.h`, `stdlib.h`, `cmath`, `string`, and `cstring`.
- **AssemblyGenerator.hpp**: Custom header for generating assembly code.
- **semantic_analyzer.hpp**: Custom header for semantic analysis.

## List of Tokens and Descriptions

The tokens defined in the YACC file represent various elements of the language's syntax. Below is a list of tokens along with their descriptions and regex patterns:

| Token             | Description                           | Regex        |
|-------------------|---------------------------------------|--------------|
| `INT_DATA_TYPE`   | Represents an integer data type.      | `int`        |
| `FLOAT_DATA_TYPE` | Represents a floating-point data type.| `float`      |
| `CHAR_DATA_TYPE`  | Represents a character data type.     | `char`       |
| `STRING_DATA_TYPE`| Represents a string data type.        | `string`     |
| `BOOLEAN_DATA_TYPE`| Represents a boolean data type.      | `bool`       |
| `CONSTANT`        | Represents the `const` keyword.       | `const`      |
| `VOID_TYPE`       | Represents the `void` keyword.        | `void`       |
| `IF`              | Represents the `if` keyword.          | `if`         |
| `ELSE`            | Represents the `else` keyword.        | `else`       |
| `SWITCH`          | Represents the `switch` keyword.      | `switch`     |
| `CASE`            | Represents the `case` keyword.        | `case`       |
| `DEFAULT`         | Represents the `default` keyword.     | `default`    |
| `WHILE`           | Represents the `while` keyword.       | `while`      |
| `FOR`             | Represents the `for` keyword.         | `for`        |
| `REPEAT`          | Represents the `repeat` keyword.      | `repeat`     |
| `UNTIL`           | Represents the `until` keyword.       | `until`      |
| `BREAK`           | Represents the `break` keyword.       | `break`      |
| `RETURN`          | Represents the `return` keyword.      | `return`     |
| `IDENTIFIER`      | Represents an identifier (variable names). | `[a-zA-Z_][a-zA-Z0-9_]*` |
| `BOOLEAN_TRUE`    | Represents the boolean value `true`.  | `"true"`     |
| `BOOLEAN_FALSE`   | Represents the boolean value `false`. | `"false"`    |
| `INTEGER_VALUE`   | Represents integer literals.          | `[0-9]+`     |
| `FLOATING`        | Represents floating-point literals.   | `[0-9]+\\.[0-9]+` |
| `CHARACTER`       | Represents character literals.        | `\\'.?\\'`   |
| `STRING_LITERAL`  | Represents string literals.           | `\\".*\\"`   |
| `ADD`             | Represents the addition `+` operator. | `+`          |
| `SUB`             | Represents the subtraction `-` operator. | `-`      |
| `MUL`             | Represents the multiplication `*` operator. | `*`      |
| `DIV`             | Represents the division `/` operator. | `/`          |
| `MOD`             | Represents the modulo `%` operator.   | `%`          |
| `INC`             | Represents the increment `++` operator. | `++`      |
| `DEC`             | Represents the decrement `--` operator. | `--`      |
| `POW`             | Represents the power `**` operator.   | `**`         |
| `ASSIGN`          | Represents the assignment `=` operator. | `=`       |
| `AND`             | Represents the logical AND `&&` operator. | `&&`     |
| `OR`              | Represents the logical OR `||` operator. | `||`      |
| `NOT`             | Represents the logical NOT `!` operator. | `!`      |
| `EQ`              | Represents the equality `==` operator. | `==`       |
| `NEQ`             | Represents the inequality `!=` operator. | `!=`      |
| `GT`              | Represents the greater than `>` operator. | `>`      |
| `LT`              | Represents the less than `<` operator. | `<`        |
| `GTE`             | Represents the greater than or equal to `>=` operator. | `>=`  |
| `LTE`             | Represents the less than or equal to `<=` operator. | `<=`  |
| `PRINT`           | Represents the `print` keyword.       | `print`      |

## Quadruples

Quadruples represent intermediate code used in the compilation process. Below are examples of quadruples generated by the parser:

| Operation | Operand1 | Operand2 | Result | Code |
|-----------|----------|----------|--------|------|
| ASSIGN    | a        | T0       |        | char coco = 'a'; |
| ALLOC     | coco     | R0       |        |                  |
| ASSIGN    | T0       | R0       |        |                  |
| ALLOC     | j        | R1       |        | float j;         |
| ASSIGN    | 9        | T1       |        | int x = 9;       |
| ALLOC     | x        | R2       |        |                  |
| ASSIGN    | T1       | R2       |        |                  |
| ASSIGN    | TRUE     | T2       |        | bool check = true; |
| ALLOC     | check    | R3       |        |                   |
| ASSIGN    | T2       | R3       |        |                   |
| ASSIGN    | TRUE     | T3       |        | bool orCheck = true || true; |
| ASSIGN    | TRUE     | T4       |        |                   |
| OR        | T3       | T3       | T5     |                   |
| ALLOC     | orCheck  | R4       |        |                   |
| ASSIGN    | T5       | R4       |        |                   |
| ASSIGN    | 3        | T0       |        | int x = 3 + 2;   |
| ASSIGN    | 2        | T1       |        |                  |
| ADD       | T0       | T1       | T2     |                  |
| ALLOC     | x        | R0       |        |                  |
| ASSIGN    | T2       | R0       |        |                  |
| ASSIGN    | 2        | T3       |        | int y = x - 2;   |
| SUB       | T2       | T3       | T4     |                  |
| ALLOC     | y        | R1       |        |                  |
| ASSIGN    | T4       | R1       |        |                  |
| ASSIGN    | 12.0     | T5       |        | float z = 12.0 / 2; |
| ASSIGN    | 2        | T6       |        |                   |
| DIV       | T5       | T1       | T7     |                   |
| ALLOC     | z        | R2       |        |                   |
| ASSIGN    | T7       | R2       |        |                   |

## Tokens with Types

Tokens with types are defined using `%type` and `%token` directives with a type specifier. These tokens carry additional information such as values or types, which is necessary for semantic analysis and code generation.

## Conclusion


The provided YACC file is part of a project that includes a parser for a programming language or syntax. It utilizes various C/C++ libraries and custom headers for generating assembly code and performing semantic analysis. The tokens defined in the file represent various elements of the language's syntax, such as data types, operators, keywords, and punctuation. Tokens with associated types carry additional information necessary for semantic analysis and code generation.

## Authors

- **Yousef Mahmoud Gilany** 
- **Seif Mohamed Al Baghdady** 
- **Ahmed Ameen Sayed** 

## University

- Cairo University, Faculty of Engineering, Department of Computer Engineering
