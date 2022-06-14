---
layout: default
title: Prototypes
---

# Prototypes

## Main

archive: main.c
All related with the flow of main.

### main

Starts the program. The inputs must be one argument, a '.ber' file.

```c
int main(int argc, char **argv);
```

## Exception manager

archive: exception_manager.c
This file handler all the exceptions of 'main.c' inputs.

### exception_manager

From this functions are checked all excepcitions about argv inputs and
map build.

```c
void  exception_manager(int argc, char **argv);
```

### throw_exception

Throw a custom error message and end the program.

```c
void  throw_exception(char *message);
```

### ch_map

Checks content of '.ber' file. If one of the next conditions it isn't
done returns 1 else 0
- Minimal map size.
- Correct number of columns for each line (ch_linelen).
- Correct type of characters and positions. (ch_chars).

```c
int ch_map(int fd, int col, int row);
```

### ch_linelen

Checks if number of line's character in a '.ber' file are equal to
the number of columns. If lenght of line is different to columns 
returns 1 else 0.

```c
int ch_linelen(int col, char *line)
```

### ch_chars

Checks if a line has the allowed characters for a map.ber file.
If finds characters for ENEMY (C), EXIT (E) or START (P) increase one
its respective position in array cep[3]. If there is a not allowed 
character in the line, return 1 else 0.

```c
int ch_chars(int r, int col, int cep[3]);
```

## Map

### get_map

Iniciliaze param 'map' and fill it with characters of 
direction 'fn'.

```c
void	get_map(char *fn, t_map *map);
```

### build_window

Starts a window and place all the tile elements based on 
double array 'map'.

```c
void	init_window(t_var *var);
```
