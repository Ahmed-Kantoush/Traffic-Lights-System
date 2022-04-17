#ifndef bitmath
#define bitmath
#define setbit(x,y) (x)|=1<<(y)
#define clrbit(x,y) (x)&=~(1<<(y))
#define getbit(x,y) (x)>>(y)&1
#define togbit(x,y) (x)^=(1<<(y))

#define concHelp(a,b,c,d,e,f,g,h) 0b##a##b##c##d##e##f##g##h
#define conc(a,b,c,d,e,f,g,h) concHelp(a,b,c,d,e,f,g,h)
#endif
