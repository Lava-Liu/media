# 1 "src/sum.c"
# 1 "<built-in>"
# 1 "<命令行>"
# 1 "src/sum.c"

# 1 "include/sum.h" 1



int sum(int start, int end);
# 3 "src/sum.c" 2

int sum(int start, int end)
{
 int i = start;
 int result = 0;
 for(i;i <= end; i++)
 {
  result = result + i;
 }
 return result;
}
