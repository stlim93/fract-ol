*This project has been created as part of the 42 curriculum by stelim*

# Description
Libft is the first project for Common Core and it introduces cadet into `libc` functions by rewriting them into a custom library. Additional utility functions along with modified version of existing functions are added into the custom library.

This project is divided into three parts:
1. The first part deals with simpler functions dealing with ascii, strings and memory.
2. The second part involves additional string-related and input/output functions.
3. Lastly, the third part involves linked-list and its related functions.

## Part 1 - Reimplementation of (some) functions from `libc`
1. `int ft_isalpha(int c)`  
	- Params:  
	  literal string or ascii number.  
	- Return value:  
	  1 if c is an alphabet else 0.
2. `int ft_isdigit(int c)`  
	- Params:  
		literal string or ascii number.  
	- Return value:  
		1 if c is a numeric else 0.
3. `int ft_isalnum(int c)`  
	- Params:  
		literal string or ascii number.  
	- Return value:  
		1 if c is an alphabet or a numeric else 0.
4. `int ft_isprint(int c)`  
	- Params:  
		literal string or ascii number.  
	- Return value:  
		1 if c is a printable ascii number (between 32 and 126 inclusive).
5. `size_t ft_strlen(const char *s)`  
	- Params:  
		pointer to a constant string.  
	- Return value:  
		The length of the string excluding the NULL-terminator. Returned value between 0 and INT_MAX.
6. `void *ft_memset(void *s, int c, size_t n)`  
	- Params:  
		s: a pointer to a memory  
		c: an integer c. This will be converted to `unsigned char`  
		n: the length of bytes of values c  
	- Return value:  
	  pointer to a memory address.
7. `void ft_bzero(void *s, size_t n)`  
	- Params:  
	  s: a pointer to a memory address  
	  n: a positve integer.  
	- Return value:  
	  None. Overwrite the n bytes in the pointer address given to be 0.
8. `void *ft_memcpy(void *dest, const void *src, size_t n)`  
	- Params:  
	  dest: pointer to `dest`  
	  src: the memory address to start copying  
	  n: the number of bytes to copy from `src` to `dest`  
	- Return value:  
	  Returns a pointer to `dest`.
9. `void *ft_memmove(void *dest, const void *src, size_t n)`  
	- Params:  
	  dest: pointer to `dest`  
	  src: the memory address to copy from  
	  n: the number of bytes to copy from `src` to `dest`  
	- Return value:
	  Returns a pointer to `dest`.
10. `size_t ft_strlcpy(char *dst, const char *src, size_t size)`  
	- Params:  
	  dst: pointer to a string array  
	  src: a pointer to character constant to be copied from  
	  size: the number of bytes to copy from `src`
	- Return value:  
		The total length of the string attempted to create.
11. `size_t ft_strlcat(char *dst, const char *src, size_t size)`
	- Params:  
	  dst: pointer to a string array  
	  src: a pointer to character constant to be copied from  
	  size: the number of bytes to copy from `src` and appended to `dst`  
	- Return value:  
	  The total length of the string attempted to create.
12. `int ft_tolower(int c)`
	- Params:  
	  c: an integer between 65 and 90 (equivalent to 'A' and 'Z')  
	- Return value:  
	  an integer
13. `int ft_toupper(int c)`
	- Params:  
	  c: and integer between 97 and 122.  
	- Return value:  
	  an integer
14. `char *ft_strchr(const char *s, int c)`
	- Params:  
	  s: pointer to a character constant i.e. string array/literal.  
	  c: an integer to be converted to `unsigned char`  
	- Return value:  
	  Returns the pointer to the first occurrence of `(unsigned char) c`. If no occurrence returns NULL.
15. `char *ft_strrchr(const char *s, int c)`
	- Params:  
	  s: pointer to a character constant i.e. string array/literal.  
	  c: an integer to be converted to `unsigned char`  
	- Return value:  
	  Returns the pointer to the last occurrence of `(unsigned char) c`. If no occurrence returns NULL.
16. `int ft_strncmp(const char *s1, const char *s2, size_t n)`
	- Params:  
	  s1: pointer to a character constant i.e. string array/literal.  
	  s2: pointer to a character constant i.e. string array/literal.  
	  n: the length of bytes to compare.  
	- Return value:  
	  The difference in the ascii value between the first `n` bytes of `s1` and `s2`.
17. `void *ft_memchr(const void *s, int c, size_t n)`
	- Params:  
	  s: pointer to a memory address  
	  c: an integer to be converted to `unsigned char`  
	  n: the first `n` bytes to scan  
	- Return value:  
	  A pointer to the matching byte or NULL
18. `int ft_memcmp(const void *s1, const void *s2, size_t n)`
	- Params:  
	  s1: pointer to a memory address  
	  s2: pointer to a memory address  
	  n: the first `n` bytes to compare  
	- Return value:  
	  the difference in `s1` vs `s2` interpreted as `unsigned char`
19. `char *ft_strnstr(const char *string, const char *key, size_t len)`
	- Params:  
	  string: a pointer to a string array/literals  
	  key: the keyword to search  
	  len: the first `len` bytes to search for `key`
	- Return value:  
	  If `key` is null (i.e. '0') `s1` is returned. Else if `key` is not found, NULL is returned. Otherwise return the pointer to the first character of the first occurrence of `key`.
20. `int ft_atoi(const char *nptr)`
	- Params:  
	  nptr: pointer to a string array/literals  
	- Return value:  
	  An integer.
21. `void *ft_calloc(size_t nmemb, size_t size)`
	- Params:  
	  nmemb: a non-negative integer (Note: Negative integer will underflow / wrap around)  
	  size: a non-negative integer (Note: Negative integer will underflow / wrap around)  
	- Return:  
	  a pointer to the allocated memory.
22. `char *ft_strdup(const char *s)`
	- Params:  
	  s: pointer to a string array/literals  
	- Return value:  
	  Pointer to the duplicated strings.

## Part 2 - Not existing or modified version of functions from `libc`
1. `char *ft_substr(char const *s, unsigned int start, size_t len)`
	- Params:  
	  s: pointer to a string array/literals  
	  start: the starting index of the substring within string  
	  len: the maximum length of the substring  
	- Return value:  
	  A pointer to the new substring.
2. `char *ft_strjoin(char const *s1, char const *s2)`
	- Params:
	  s1: pointer to a string array/literals  
	  s2: pointer to a string array/literals  
	- Return value:  
	  A pointer to a new string.
3. `char *ft_strtrim(char const *s1, char const *set)`
	- Params:  
	  s1: pointer to a string array/literals  
	  set: a set of string literals to trim from `s1`.
4. `char **ft_split(char const *s, char c)`
	- Params:  
	  s: pointer to a string array/literals  
	  c: a string literal  
	- Return value:  
	  An array of new strings from splitting `s` based on delimiter `c`.
5. `char *ft_itoa(int n)`
	- Params:  
	  n: An integer  
	- Return value:  
	  A pointer to a string representing integer `n`.
6. `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))`
	- Params:  
	  s: pointer to string array/literals  
	  f: pointer to a function that takes `unsigned int` and `char`  
	- Return value:  
	  pointer to a new string with `f` applied to each character
7. `void ft_striteri(char *s, void (*f)(unsigned int, char *))`
	- Params:  
	  s: pointer to string array/literals  
	  f: pointer to a function that takes `unsigned int` and `char`  
	- Return value:
	  None. `f` is applied to each character in `s` and modified in-place.
8. `void ft_putchar_fd(char c, int fd)`
	- Params:  
	  c: the character to output  
	  fd: the file descriptor on which to write  
	- Return:
	  None.
9. `void ft_putstr_fd(char *s, int fd)`
	- Params:  
	  c: the string to output  
	  fd: the file descriptor on which to write  
	- Return:
	  None.
10. `void ft_putendl_fd(char *s, int fd)`
	- Params:  
	  c: the string to output  
	  fd: the file descriptor on which to write  
	- Return:
	  None.
11. `void ft_putnbr_fd(int n, int fd)`
	- Params:  
	  c: the integer to output  
	  fd: the file descriptor on which to write  
	- Return:
	  None.

## Part 3 - Linked list
1. `t_list *ft_lstnew(void *content)`
	- Params:  
	  content: pointer to memory of `content`  
	- Return:  
	  Pointer to the linked list.
2. `void ft_lstadd_front(t_list **lst, t_list *new)`
	- Params:  
	  lst: a linked list  
	  new: a linked list
	- Return:  
	  None
3. `int ft_lstsize(t_list *lst)`
	- Params:  
	  lst: a linked list  
	- Return:  
	  An integer indicating the number of nodes in the linked list.
4. `t_list *ft_lstlast(t_list *lst)`
	- Params:  
	  lst: a linked list  
	- Return:  
	  The pointer to the last node.
5. `void ft_lstadd_back(t_list **lst, t_list *new)`
	- Params:  
	  lst: a linked list  
	  new: a linked list  
	- Return:  
	  None
6. `void ft_lstdelone(t_list *lst, void (*del)(void *))`
	- Params:  
	  lst: a linked list  
	  del: a pointer to a function that performs a deletion operation  
	- Return:  
	  None
7. `void ft_lstclear(t_list **lst, void (*del)(void *))`
	- Params:  
	  lst: a linked list  
	  del: a pointer to a function that performs a clear operation  
	- Return:  
	  None
8. `void ft_lstiter(t_list *lst, void(*f)(void *))`
	- Params:  
	  lst: a linked list  
	  f: a pointer to a function that takes in `void *`  
	- Return value:  
	  None
9. `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))`
	- Params:  
	  lst: a linked list  
	  f: a pointer to a function that takes in `void *`  
	  def: a pointer to a function that performs delete operation `void *`  
	- Return value:  
	  None

# Instructions
1. Git clone to your folder under FOLDER_NAME
```
git clone git@github.com:stlim93/libft.git FOLDER_NAME
```
2. Run make to generate static library libft.a.
```
make
```
3. To remove all object files run
```
make clean
```
4. If want to remove all object files and library run 
```
make fclean
```
5. To rebuild the library run
```
make re
```

# Resources
## Classic References
Heavy references were made based on the two following sites:
1. https://man7.org/linux/man-pages/.
2. https://linux.die.net/man/.
3. Manual pages via `man` on bash terminal.

## AI Declaration
1. AI usage is limited to knowledge verification such as but not limited to:
	- Errors debugging (e.g. "What does the error <XXX> when compiling C means?")
	- Test case generation
	- Initial knowledge exposure (e.g. "What is <Topic> and give an introduction on <Topic>")

# Others
The following libraries and their functions are used as part of the library creation:
1. stdlib.h  
	stdlib.h is a standard header file used in this project for some functions. The two functions used are `malloc` and `free` along with macro `NULL` defined within stdlib.h to indicate `NULL` pointer.
2. unistd.h  
	unistd.h is a standard header file that provides access to POSIX operating system API. It mainly allows user to interact with the system kernal via system calls. The main function used is `write` in the functions relevant to file descriptor (`ft_*_fd.c`).