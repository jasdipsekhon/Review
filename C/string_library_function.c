#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MEMCPY
//#define MEMSET
#define MEMCMP
//#define STRCPY
//#define STRCMP
//#define STRCAT
//#define STRSTR
//#define STRTOK
//#define ATOI

#ifdef MEMCPY
void *my_memcpy(void *dest, void *src, int n) {
    unsigned char *dest_ptr = (unsigned char *)dest;
    const unsigned char *src_ptr = (const unsigned char *)src;
    
    // while (n--) {
    //     *dest_ptr++ = *src_ptr++;
    // }
    
    for (size_t i = 0; i < n; i++) {
        dest_ptr[i] = src_ptr[i];
    }
    return dest;
}

void print_string(char *s) {
    // s[1] = s[1] + 1;
    printf("%s\n", s);
}

int main()
{
    unsigned char *a = "Hello, World!";
    unsigned char b[strlen(a) + 1];
    my_memcpy(b, a, strlen(a) + 1);
    printf("%s\n", b);
    print_string(a);
    return 0;
}
#endif

#ifdef MEMSET
void *memset(void *s, int c, size_t n) {
    char *s_ptr = (char *)s;
    char c_char = (char)c;
    for (size_t i = 0; i < n; i++) {
        s_ptr[i] = c_char;
    }
    return s;
}

int main() {
    char a[] = "Hello, World";
    memset(a, 'A', 4);
    printf("%s\n", a);
    return 0;
}
#endif

#ifdef MEMCMP
int my_memcmp(void *s1, void *s2, size_t n) {
    char *s1_ptr = (char *)s1;
    char *s2_ptr = (char *)s2;
    for (size_t i = 0; i < n; i++) {
        if (s1_ptr[i] != s2_ptr[i]) {
            return (int)(s1_ptr[i] - s2_ptr[i]);
        }
    }
    return 0;
}

int main() {
    char *a = "Hello, World";
    char *b = "Hello, Wodld";
    int result = my_memcmp(a, b, strlen(a));
    printf("%d\n", result);
    return 0;
}
#endif

#ifdef STRCPY
char *my_strcpy(char *dest, char *src) {
    char *src_ptr = src;
    for (int i = 0; src_ptr[i] != '\0'; i++) {
        dest[i] = src_ptr[i];
    }
    dest[strlen(src)] = '\0';
    return dest;
}

int main()
{
    char arr[] = "Hello World";
    char arr2[strlen(arr) + 1];
    my_strcpy(arr2, arr);
    printf("%s", arr2);
    return 0;
}
#endif

#ifdef STRCMP
size_t my_strcmp(const char *s1, const char *s2, size_t n) {
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0') {
            return s2[i] - s1[i];
        }
    }
    return 0;
}

int main()
{
    char arr[] = "Hello World";
    char arr2[] = "Hello Worll";
    size_t cmp = my_strcmp(arr, arr2, strlen(arr)); 
    printf("%ld\n", cmp);
    return 0;
}
#endif

#ifdef STRCAT
char *my_strcat(char *dest, const char *src) {
    char *dest_ptr = dest;
    while (*dest_ptr != '\0') {
        dest_ptr++;
    }
    for (int i = 0; i < src[i] != '\0'; i++) {
        dest_ptr[i] = src[i];
    }
    return dest;
}

int main()
{
    char arr[] = "Hello World";
    char arr2[] = "Hello Worll";
    char* result = my_strcat(arr, arr2); 
    printf("%s\n", result);
    return 0;
}
#endif

#ifdef STRSTR
char *my_strstr(char *haystack, char *needle) {
    while (*haystack != '\0') {
        char *haystack_ptr = haystack;
        char *needle_ptr = needle;
        while (*needle_ptr != '\0' && *haystack_ptr == *needle_ptr) {
            haystack_ptr++;
            needle_ptr++;
        }
        if (*needle_ptr == '\0') {
            return (char *)haystack;
        }
        haystack++;
    }  
    return NULL;
}

int main() {
    char arr[] = "Hello World";
    char arr2[] = "World";
    char *result = my_strstr(arr, arr2);
    printf("%s", result);
    return 0;
}
#endif

#ifdef STRTOK
char *my_strtok(char *s, char *delim) {
    char *s_ptr = s;
    while(*s != '\0') {
        if (*s == *delim) {
            return (char *)s;
        }
        s++;
    }
    return NULL;
}
int main() {
    char arr[] = "Hello World";
    char arr2[] = "W";
    char *result = my_strtok(arr, arr2);
    printf("%s", result);
    return 0;
}
#endif

#ifdef ATOI
int my_atoi(char *s) {
    char *s_ptr = s;
    int sign = 0;
    int result = 0;
    if (*s_ptr == '-' || *s_ptr == '+') {
        sign = (*s_ptr == '-') ? -1 : 1;
        s_ptr++;
    }
    while (*s_ptr >= '0' && *s_ptr <= '9') {
        result = result * 10 + (*s_ptr - '0');
        s_ptr++;
    }
    return sign * result;
}

int main() {
    char arr[] = "-256";
    int result = my_atoi(arr);
    printf("%d", result / 2);
    return 0;
}
#endif
