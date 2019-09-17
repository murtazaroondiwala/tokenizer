#ifndef functions
#define functions
struct Node* head;
int str_copy(char *str1, char *str2);
int str_find_substring(char*str1, char*str2);
int str_find_substring1(char*str1, char*str2);
int str_length(char *str);
int str_compare1(char *str1, char *str2);
int str_compare(char *str1, char *str2);
void *memcopy(const void* src,  void* dest, unsigned int n);
void Tweet1(struct Node* head,char* A);
void Insert(char* A);
#endif