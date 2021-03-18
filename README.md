# REINS

> A library written in C using termcaps and termios. It is made in
> compliance with the 42-imposed norme.

The intention of this library is to replicate the default behavior of the terminal, and provide an easy way to customize that behavior.

## Functions

#### Reins:  

##### - basic functionality

* `t_reins *reins_init();`  
Returns an allocated and initialized reins object

* `int reins_enable(t_reins *reins);`  
Enable reins

* `int reins_disable(t_reins *reins);`  
Disable reins

* `int reins_get_input(t_reins *reins, char **line);`  
Retrieve a line of input from the terminal, stored in the char* pointed to by line.  
Returned int is 0 for empty line with EOF, -1 for error and 1 for a succesful line read

* `void reins_destroy(t_reins *reins);`  
Destroy the reins object, freeing it after;

##### - customization

> `t_keyf` is a function pointer typedef used internally for functions related to handling keypresses.  
 `int (*t_keyf)(t_input *input, char *buf, t_hook *hook);`

* `int reins_print_keycodes(t_reins *reins);`  
Similar to reins_get_input, but instead of storing the keycodes and handling them, all it does is print the keycodes, used to figure out what the keycode for a given key is.

* `int reins_hook(t_reins *reins, char *keycode, void (*f)(void *param), void *param);`  
In default `t_keyf` functions a hook is always called using the provided parameter when present.

* `int reins_key(t_reins *reins, char *keycode, t_keyf function);`  
Add or change an existing `t_keyf` function of a given key.  
This can be combined with `reins_hook()` to provide an extra parameter to use in your `t_keyf` function.

#### Input:  

> t_input is a struct that contains information about the input field, as well as the line vector itself.

* `int reins_input_add(t_input *input, char *str, size_t len);`  
Add the given string to the input, inserted at the current position of the cursor.

* `int reins_input_del(t_input *input, size_t len);`  
Delete at most len amount of characters from the input field, starting at the current position of the cursor.

* `int reins_cursor_move(t_input *input, size_t x, size_t y, bool cap);`  
Move the cursor to the x, y position. If cap is true, cursor will be capped to the biggest x,y of the input field.
