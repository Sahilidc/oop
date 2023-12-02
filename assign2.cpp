// Varad Charholikar
// PA01

// Assignment 2 : To study and demonstrate the concept of function overloading using C++

#include <iostream>
#include <cstring>
using namespace std;

// strcat() function overload
char* strcat(char* dest, const char* src) {
  while (*dest) {
    dest++;
  }
  while (*src) {
    *dest++ = *src++;
  }
  return dest;
}

// strncat() function overload
char* strncat(char* dest, const char* src, size_t n) {
  while (*dest) {
    dest++;
  }
  for (size_t i = 0; i < n; i++) {
    if (*src == '\0') {
      break;
    }
    *dest++ = *src++;
  }
  return dest;
}

// strcpy() function overload
char* strcpy(char* dest, const char* src) {
  char* p = dest;
  while (*src) {
    *p++ = *src++;
  }
  return dest;
}

// strncpy() function overload
char* strncpy(char* dest, const char* src, size_t n) {
  char* p = dest;
  for (size_t i = 0; i < n; i++) {
    if (*src == '\0') {
      break;
    }
    *p++ = *src++;
  }
  *p = '\0';
  return dest;
}

int main(){
    char dest[50] = "Hello World!, ";
    char src[50] = "My name is Varad ";
    char pos[50] = "I study in MIT WPU";
    char ans[50];

    strcat(dest, src);
    cout << dest << endl;

    strncat(dest, pos, 7);
    cout << dest << endl;

    strcpy(ans, src);
    cout << dest << endl;
  
    strncpy(dest, pos, 7);
    cout << dest << endl;
    
}