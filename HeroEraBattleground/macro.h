/* Those preprocessor directives use Windwos API to print colorful characters */
#define SET_CYAN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN|FOREGROUND_BLUE)
#define SET_WHITE SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN | FOREGROUND_BLUE)
#define SET_RED SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED)
#define SET_GREEN SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN)
#define SET_YELLOW SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN)

/* Gaming constants */
// The ratio that by which a hero's defence ability can reduce the damage taken.
// This value should not be too big. See the document for more details.
#define C_IMMUNE 24.0
// Used to calculate the crit chance. This value should not be too big.
#define C_CRIT_MONEY 2000.0
// When you sell an equipment, you get this ratio of the original price.
#define C_SELL 0.6
// When you give some damage to your enemy, then you receive money according to this ratio of damage
#define C_RECEIVE 5
// Crit attack coefficient
#define C_CRIT 1.5