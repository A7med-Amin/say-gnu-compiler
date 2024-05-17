// Single line comment

/*
Multiline
comment
*/


/*
    ======================================== DECLARATIONS AND ASSIGNMENTS ================================================
*/
const int SABET = 100;
int declaration;
float decWith_Assign=5.2;
int x = 0;
int y = 10;
int z = x / y - x;
string ya_welcome = "Hello World!";
bool a = true;
bool b = false;
// bool c = a && b;

/*
    ======================================== ARITHMETIC ================================================
*/
int result;
int op1 = 5;
int op2 = 6;
result = op1 + op2;


/*
    ======================================== BLOCK SCOPES ================================================
*/
{
    int x = 5;
    {
        int x = 10;
        int y = 20;
    }
    y = 30;
}
x = y;

/*
    ======================================== FUNCTIONS ================================================
*/

int sum(int x, int y)
{
  return x + y;
}

void fun(){
    int res;
    if (x>7)
    {
        res = 7;
    }
    else if (x < 4) {
        res = 8;
    }
    else{
        res = 10;
    }
}

// int paramChecker(string str, float ff, char c){
//     if (ff > 7.5)
//     {
//         return 8;
//     }
//     else if (ff < 4.12) {
//         return 0;
//     }
//     else{
//         return 10;
//     }
// }

// int returnChecker(string str, float ff, char c){
//     int res;
//     if (ff>7.5)
//     {
//         res = 8;
//     }
//     else if (ff < 4.12) {
//         res = 0;
//     }
//     else{
//         res = 10;
//     }
// }

void main()
{
  int a = sum(10, 20);
  fun();
//   a = paramChecker("seif", 3.5,'d');
// a = returnChecker("seif", 3.5,'d');
}

/*
======================================== CONDITIONAL EXPRESSIONS ================================================
*/

int test;
if (x == 10)
{
    test = 10;
}
else if (x == 5)
{
    test = 5;
}
else
{
    test = x;
}

int i = 9;
int var;
if((i>8 && i < 9) || (i!=8 && i <= 9)){
    var=12;
}

char coco = 'A';
float j;
// switch(coco){ 
//     case 'c': 
//         j = 9.0; 
//         break; 
//     case 'h': 
//         j = 6.33; 
//         break; 
//     default: 
//         j =7.56;
// }


/*
    ======================================== LOOPS ================================================
*/

for (int i = 0; i < 10; i = i+1)
{
    int b = 10;
}

int xx = 0;

while (xx < 20)
{
    xx = xx + 1;
}

xx = 0;

repeat
{
    xx = xx + 1;
} until (x < 20);


/*
    ======================================== NOW HELLO WITH ERRORS ================================================
*/

// ********** SEMANTIC ERRORS **********

// int x = 10;                                  // ERROR: REDECLARATION OF x   
// float fof = fun();                          // ERROR: FUNCTION RETURN TYPE MISMATCH OF TYPE VOID
// const int CONSO;                           // ERROR: CONSTANT DECLARATION WITHOUT INITIALIZATION
// SABET = 10;                               // ERROR: CONSTANT CAN NOT BE CHANGED
// undeclared = 4.6;                        // ERROR: UNDECLARED VARIABLE

// ********** SYNTAX ERRORS **********

// in x;

// fo (int i = 0; i < 10; i = i+1)








