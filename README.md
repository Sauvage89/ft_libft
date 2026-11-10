*This project has been created as part of the 42 curriculum by lensauva.*

# Libft

## Description

**Libft** is the first project of the 42 curriculum. The goal is to build, from scratch, a static C library (`libft.a`) that reimplements a set of standard libc functions and adds extra utility functions that will be reused throughout the rest of the curriculum.

The project is split into three parts:

1. **Libc functions** – re-coding standard functions with the same prototypes and behaviors as the originals (prefixed with `ft_`).
2. **Additional functions** – utility functions that are either absent from the libc or exist in a different form (string manipulation, conversions, file descriptor output).
3. **Linked list** – a set of functions to manipulate a singly linked list built on the `t_list` structure.

Constraints followed in this project:

- Written in C, in accordance with the Norm.
- Compiled with compiler `cc` and flags `-Wall -Wextra -Werror`.
- No global variables.
- Helper functions are declared `static`.
- The library is built with `ar`.
- No memory leaks, and no unexpected crashes (segfault, bus error, double free, etc.), except for undefined behavior.

## Instructions

### Compilation

At the root of the repository:

```bash
make        # builds libft.a
make clean  # removes object files
make fclean # removes object files and libft.a
make re     # fclean + all
```

The Makefile provides the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`, and does not relink unnecessarily.

### Usage

Include the header in your source file:

```c
#include "libft.h"
```

Then compile your program and link it against the library:

```bash
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

Example:

```c
#include "libft.h"

int main(void)
{
    char *str;

    str = ft_strjoin("Hello, ", "42!");
    if (!str)
        return (1);
    ft_putendl_fd(str, 1);
    return (0);
}
```

### Testing

Test programs are not part of the submission. To compare `strlcpy`, `strlcat` and `bzero` against the system versions on a glibc system, include `<bsd/string.h>` and compile with `-lbsd`.

## Library description

### Part 1 – Libc functions

| Function | Description |
|---|---|
| `ft_isalpha` | Returns `1` if the character is alphabetic, `0` otherwise. |
| `ft_isdigit` | Returns `1` if the character is a digit, `0` otherwise. |
| `ft_isalnum` | Returns `1` if the character is alphanumeric, `0` otherwise. |
| `ft_isascii` | Returns `1` if the character is in the ASCII range (0–127), `0` otherwise. |
| `ft_isprint` | Returns `1` if the character is printable, `0` otherwise. |
| `ft_strlen` | Computes the length of a string. |
| `ft_memset` | Fills a memory area with a constant byte. |
| `ft_bzero` | Sets a memory area to zero. |
| `ft_memcpy` | Copies `n` bytes between non-overlapping memory areas. |
| `ft_memmove` | Copies `n` bytes between memory areas that may overlap. |
| `ft_strlcpy` | Copies a string into a buffer of a given size, always NUL-terminating (if size > 0). Returns the length of the source. |
| `ft_strlcat` | Appends a string to a buffer of a given size, always NUL-terminating (if size > 0). Returns the length it tried to create. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |
| `ft_strchr` | Locates the first occurrence of a character in a string. |
| `ft_strrchr` | Locates the last occurrence of a character in a string. |
| `ft_strncmp` | Compares at most `n` characters of two strings. |
| `ft_memchr` | Locates the first occurrence of a byte in a memory area. |
| `ft_memcmp` | Compares two memory areas. |
| `ft_strnstr` | Locates a substring in a string, searching at most `len` characters. |
| `ft_atoi` | Converts the initial portion of a string to an `int`. |
| `ft_calloc` | Allocates zero-initialized memory. If `nmemb` or `size` is `0`, returns a unique pointer that can be passed to `free()`. |
| `ft_strdup` | Allocates and returns a duplicate of a string. |

### Part 2 – Additional functions

| Function | Prototype | Description |
|---|---|---|
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Allocates and returns a substring of `s` starting at index `start`, of maximum length `len`. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2);` | Allocates and returns the concatenation of `s1` and `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set);` | Allocates and returns a copy of `s1` with the characters in `set` removed from the beginning and the end. |
| `ft_split` | `char **ft_split(char const *s, char c);` | Allocates and returns a NULL-terminated array of strings obtained by splitting `s` with the delimiter `c`. Returns `NULL` if any allocation fails (previously allocated memory is freed). |
| `ft_itoa` | `char *ft_itoa(int n);` | Allocates and returns a string representing the integer `n`. Negative numbers are handled. |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Applies `f` to each character of `s` (with its index) and returns a newly allocated string of the results. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Applies `f` to each character of `s` (with its index), passing each character by address so it can be modified. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd);` | Writes the character `c` to the file descriptor `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd);` | Writes the string `s` to the file descriptor `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd);` | Writes the string `s` followed by a newline to the file descriptor `fd`. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd);` | Writes the integer `n` to the file descriptor `fd`. |

### Part 3 – Linked list

The following structure is declared in `libft.h`:

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

| Function | Prototype | Description |
|---|---|---|
| `ft_lstnew` | `t_list *ft_lstnew(void *content);` | Allocates and returns a new node with the given `content`; `next` is set to `NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds the node `new` at the beginning of the list. |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst);` | Counts the number of nodes in the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds the node `new` at the end of the list. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees the content of a node with `del`, then frees the node itself (not the next one). |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees the given node and all its successors using `del` and `free`, then sets the list pointer to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Applies `f` to the content of each node. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Applies `f` to the content of each node and builds a new list from the results. On allocation failure, the partially built list is cleared with `del` and `NULL` is returned. |

## Technical choices

- **Static helpers**: when a function needs to be broken down, the helpers are declared `static` to limit their scope to their file.
- **Error handling**: every function that allocates memory returns `NULL` on allocation failure, and frees anything it had already allocated.
- **Same behavior as libc**: Part 1 functions follow the behavior described in their man pages (including edge cases).
- **Library creation**: `libft.a` is created at the root of the repository with `ar rcs`.

## Resources

### References

- man pages of the reimplemented functions
- Kernighan & Ritchie, *The C Programming Language*
- peer to peer
- The 42 Norm

### Use of AI
>
> - *[writing/proofreading this README]*
> - *[writing/proofreading the Makefile]*
> - *[documentation on syntax of C]*
