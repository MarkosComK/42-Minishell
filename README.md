# Minishell

---

## How to clone the project

This project use a submodule for libft which allows me to update the libft while working at this project.

To clone properly you can use that command:

```bash
git clone --recurse-submodules git@github.com:MarkosComK/42-Minishell.git
```

## Project structure

To keep the project organized we've chosen to make a header for each folder, the header must contain the name of the folder and the functions and macros related
to that folder to keep the project as cleen and easy to found some file as possible.

Also, above each set of functions we have a comment with the name of the file you can found those functions.

Here's and example using an equivalent header to srcs/input:

```c
#ifndef INPUT_H
# define INPUT_H

//input_validation.c
bool	input_validation(char *input);
bool	check_quotes(char *str);
bool	check_pipes(char *str);

//quote_parser.c
char	*quote_space_parser(char *argv);
int		counter(char *str, char c);
char	*space_to_minus(char *str);
char	*dequote_single(char *str);

#endif
```

As you can see above, you can found inside the file input_validation.c all the functions listed below the commented line

```c
//input_validation.c
bool	input_validation(char *input);
bool	check_quotes(char *str);
bool	check_pipes(char *str);

```

And this rule helps keep the functions easy to maintain and found along the whole project.

## Git-flow

This project has a guide for now that you can check <a href="https://www.notion.so/markoscomk/Minishell-10a7f389561a8071b283f60971d94217">here</a>

I added a rule to protect the main branch so me and my partner can only make commits (which means add code) by sending Pull-requests; the PR must be reviewed from the partner / peer before be added to the main project.

## Binary tree flow

Our approach to organize the user input in order to properly run them as bash does is by using binary-trees
this is also a good oportunity to learn this data structure -- soon this example will be implemented into these
docs.

### Binary tree - image

this example is not 100% clear yet but, as i said, i'm still learning binary trees so keep looking into the repo.

<p align="center">
    <img src="https://github.com/user-attachments/assets/b708eb21-cae1-411a-a49c-1c16e2350da2">
</p>
