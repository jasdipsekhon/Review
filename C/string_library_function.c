#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#define MEMCPY
//#define MEMSET
#define MEMCMP

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
