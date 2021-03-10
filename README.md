# REINS

> A library written in C using termcaps and termios. It is made in
> compliance with the 42-imposed norme.

The intention of this library is to replicate the default behavior of the terminal, and provide an easy way to customize that behavior.

`t_keyf` is a function pointer typedef used internally for functions related to handling keypresses.  
Its prototype is:  
 `int (*t_keyf)(t_reins *reins, t_vec *vec, char *buf, t_hook *hook);`

## Functions

* `reins_hook(t_reins *reins, char *keycode, void (*f)(void *param), void *param);`  
In default `t_keyf` functions, when present, a hook is always called using the provided parameter.

* `reins_key(t_reins *reins, char *keycode, t_keyf function))`  
Add functionality or change existing `t_keyf` function of a given key.  
This can be combined with `reins_hook()` to provide an extra parameter to use in your `t_keyf` function.
