# REINS

> A library written in C using termcaps and termios. It is made in
> compliance with the 42-imposed norme.

The intention of this library is to replicate the default behavior of the terminal, and provide an easy way to customize that behavior.

`t_keyf` is a function pointer typedef used internally for functions related to handling keypresses.  
Its prototype is:  
 `int (*t_keyf)(t_reins *reins, t_vec *vec, char *buf, t_hook *hook);`

## Functions

* `int reins_hook(t_reins *reins, char *keycode, void (*f)(void *param), void *param);`  
In default `t_keyf` functions a hook is always called using the provided parameter when present.

* `int reins_key(t_reins *reins, char *keycode, t_keyf function);`  
Add or change an existing `t_keyf` function of a given key.  
This can be combined with `reins_hook()` to provide an extra parameter to use in your `t_keyf` function.

* `int reins_get_input(t_reins *reins, char **line);`  
Retrieve a line of input from the terminal, stored in the char* pointed to by line.  
Returned int is 0 for empty line with EOF, -1 for error and 1 for a succesful line read

* `int reins_enable(t_reins *reins);`  
Enable reins

* `int reins_disable(t_reins *reins);`  
Disable reins

* `t_reins *reins_init();`  
Returns an allocated and initialized reins object

* `void reins_destroy(t_reins *reins);`  
Destroy the reins object, freeing it after;
