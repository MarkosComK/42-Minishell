# Minishell

---

## How to clone the project

This project use a submodule for libft which allows me to update the libft while working at this project.

To clone properly you can use that command:

```bash
git clone --recurse-submodules git@github.com:MarkosComK/42-Minishell.git
```

## How It Works

### Tokenization

First of all, let's talk about the separators. The separators are:

- `;`
- `&&`
- `||`

A separator always marks the end of the execution. This means if there's an input command with `n` separators, it can be split `n` times into shorter commands. We'll call this split result a **command line**.

A command line can also be split; we can use the pipe (`|`) as a separator. We'll call this result **job**. Finally, a job can be split into simple commands.

- **INPUT CMD** → can be composed of `n` CMD LINE(s) (separated by `;`, `&&`, `||`)
- **CMD LINE** → can be composed of `n` JOB(s) (separated by `|`)
- **JOB** → always contains a command and `n` redirections (`<`, `<<`, `>`, `>>`

### Command Structure Breakdown

1. **INPUT CMD**:
    - This is the highest level of command input that a user can enter.
    - It can consist of multiple **CMD LINE** elements, which are separated by:
        - **`;`**: Executes the following command unconditionally.
        - **`&&`**: Executes the following command only if the preceding command succeeded.
        - **`||`**: Executes the following command only if the preceding command failed.
    - Example: `cmd1; cmd2 && cmd3 || cmd4`
2. **CMD LINE**:
    - Each **CMD LINE** can contain multiple **JOB** elements.
    - These jobs are separated by pipes (`|`), allowing for command chaining where the output of one command serves as the input for the next.
    - Example: `cmd1 | cmd2 | cmd3`
3. **JOB**:
    - A **JOB** always consists of a single command and may include several **redirections**:
        - **`<`**: Input redirection.
        - **`<<`**: Here document input redirection.
        - **`>`**: Output redirection (overwrites the file).
        - **`>>`**: Output redirection (appends to the file).
    - Example: `ls > output.txt` (where `ls` is the command and `>` is the redirection operator).

The command lines and jobs will be handled in the BST (see the next part). The lexer-parser will return a linked list of tokens that will be used to build a BST later. This is the structure of a token node:

```c
typedef struct s_tok {
    t_tok_t type;       // could be OP or CMD
    char* data;        // could be command name with its args or a filename
    struct s_tok* next;
} t_tok;

```

### Example of Tokenization

Let's illustrate with a simple example of how to tokenize a command line:

```bash
minish> $ ls | cat -e | rev

```

**Tokens:**

```
[type: CMD, data: (ls)]
[type: OP: PIPE, data: NULL]
[type: CMD, data: (cat -e)]
[type: OP: PIPE, data: NULL]
[type: CMD, data: (rev)]

```

As we can see, the tokens have two types: **operator** or **cmd**. The operator used to split a job (the pipes) has no data; however, the redirections have the filename in data, like:

```bash
minish> $ ls > file

```

**Tokens:**

```
[type: CMD, data: (ls)]
[type: OP: REDIR_GR, data: (file)]

```

Additionally, the separators of the command lines will be used for conditional calculations (if the separators are `&&` or `||`). For example, consider an input command with some separators. For each separator, a new BST will be created and executed. The conditional return (true or false) of the command(s) executed on the BST will be stored during the BST execution. After execution, it's straightforward to perform conditional calculations.

The parentheses are only used for conditional calculations; they have no effect on anything else:

```bash
minish> $ CMD_LINE && CMD_LINE || (CMD_LINE || CMD_LINE) || CMD_LINE ; CMD_LINE
             ^           ^             ^          ^             ^         ^
             |           |             |          |             |         |
             1 BST       1 BST         1 BST      1 BST         1 BST    always exec
           always exec   exec if      exec if    exec if       exec if
                         prev=true     prev=false  prev=false   parentheses=false

```
