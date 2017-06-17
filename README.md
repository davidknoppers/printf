*This is a group project between Jianqin Jay Wang and David Knoppers*.

The purpose of this project is to recreate the printf function that programmers use in their code daily.

This function can handle the following modifiers:
%, c (char), s (string), d and i (decimal), u (unsigned int), o (octal), x (lower hexadecimal), X (upper hexadecimal), and b (binary).

The return value for the function is the total character count of the output.

For this project, we were only allowed to use the following advanced functions from the C library:

```
write
malloc
free
va_start
va_end
va_copy
va_arg
```



Example usage of the function _printf:

Example Input 1:

```c
int i = 10;
_printf("%d\n", i)
```

Output:

```
10
```

Example Input 2:

```c
char c = 'z';
_printf("%c\n", c)
```

Output:

```
c
```

Example Input 3:

```c
_printf("%s\n", "Print out this string")
```

Output:

```
Print out this string
```

A basic main function has been included for users to test the _printf function.