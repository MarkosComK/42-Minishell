
# 🐚 Minishell
### As Beautiful as a Shell

Welcome to **Minishell**! This project involves creating a simple shell, essentially a miniature Bash, teaching us about process management, POSIX standards, and efficient memory handling. With Minishell, you'll get to experience command-line environments as coders did in the early days of computing.

![image](https://github.com/user-attachments/assets/1820ebd6-a450-43af-b462-dd11e206631c)

![image](https://github.com/user-attachments/assets/ad348c52-a258-4ff6-a9ed-fa36f9ba9ca0)

![image](https://github.com/user-attachments/assets/4c014c12-9bd4-40c4-a604-5fc59fb18395)

## 🚀 How to Clone the Project

To properly clone this project, as it uses **libft** as a submodule, use the following command:

```bash
git clone --recurse-submodules git@github.com:MarkosComK/42-Minishell.git
```

This ensures that **libft** will be available and up-to-date as you work on Minishell.

## 📂 Project Structure

We've organized the project with headers for each folder to make it easy to find and maintain functions and macros. Each header lists the functions related to that folder, while above each function set, there's a comment specifying the file where these functions can be found.

For example, here's an equivalent header for `srcs/input`:

```c
#ifndef INPUT_H
# define INPUT_H

// input_validation.c
bool    input_validation(char *input);
bool    check_quotes(char *str);
bool    check_pipes(char *str);

// quote_parser.c
char    *quote_space_parser(char *argv);
int     counter(char *str, char c);
char    *space_to_minus(char *str);
char    *dequote_single(char *str);

#endif
```

This structure keeps code modular and easy to navigate. 🗂️

## 🌳 Command Parsing with an Asymmetric Binary Tree

To process user input effectively, we utilize an asymmetric binary tree for command parsing. This structure allows us to handle command execution priority and sequence precisely, similar to Bash. Using a binary tree also offers a deeper understanding of tree-based data structures, making it an invaluable addition to our learning.

Our implementation respects POSIX standards, ensuring our shell behaves similarly to a POSIX-compliant environment for compatibility and predictable command execution.

<p align="center">
    <img src="https://github.com/user-attachments/assets/b708eb21-cae1-411a-a49c-1c16e2350da2">
</p>

The example above illustrates our current asymmetric binary tree implementation, still a work-in-progress as we refine our parsing approach.

## ⚙️ Project Fundamentals

Minishell is a collaborative project that covers multiple core development concepts:

- **Memory Management**: We ensure efficient use of memory and strictly avoid memory leaks, managing dynamic allocation and deallocation meticulously.
- **POSIX Compliance**: Commands and functionalities align with POSIX standards to make our shell as consistent with standard Unix shells as possible.
- **Git Management**: We utilize Git for version control, organizing our work through branches and reviewing all contributions via Pull Requests.
- **Collaborative Coding**: The project is designed to improve teamwork, with each feature developed in a separate branch and reviewed by team members before merging.
- **Header and Function Organization**: Code is modularized with headers for each section, simplifying maintenance and readability.

These fundamentals not only make Minishell functionally robust but also serve as critical learning points that reinforce best practices in software development.

## 🔹 Git-Flow

Our Git process follows a Git-Flow model. Here's an overview:

- **Protected Main Branch**: Only Pull Requests (PRs) are allowed to merge into `main`.
- **Branch Per Change**: Each feature or fix has its dedicated branch, helping us track and review changes effectively.
- **Peer Review**: PRs are reviewed by a team member before merging to ensure code quality.

This approach gives us experience managing branches and streamlining collaboration in a large project.

## ⚙️ Mandatory Features

Minishell implements core shell features, such as:

- **Prompt Display**: Shows a prompt while waiting for user input.
- **Builtins**: Supports `echo`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit` commands.
- **Path Resolution**: Searches and launches executables based on `$PATH` or relative/absolute paths.
- **Redirections and Pipes**: Handles `|`, `<`, `>`, and `>>` similar to Bash.
- **Environment Variables**: Expands `$` variables and `$?` exit codes.
- **Signal Handling**: Manages `Ctrl+C`, `Ctrl+D`, and `Ctrl+\` similar to Bash.
- **Command History**: Uses Termcap to navigate command history with up and down arrows.

For detailed requirements, check the (en.subject-Minishell (1)).

## 🌟 Bonus Features

The project also includes bonus features for an advanced shell experience:

- **Here Documents (`<<`)**: Implements Bash-style here-documents.
- **Enhanced Line Editing**: Supports cutting, copying, and pasting text, moving by words, and multi-line commands with Termcaps.
- **Logical Operators**: Adds support for `&&` and `||` operators.
- **Wildcards (`*`)**: Implements wildcard expansion.

> **Note**: Only attempt bonuses after the mandatory features are working perfectly.

Minishell provides a unique opportunity to understand shell mechanics and improve our technical and teamwork skills.
## 👥 Authors

Made with 💻 and ☕️ by:

<div align="center">

[![marsoare](https://img.shields.io/badge/marsoare-black?style=for-the-badge&logo=github)](https://github.com/MarkosComK)
[![hluiz-ma](https://img.shields.io/badge/hluiz--ma-black?style=for-the-badge&logo=github)](https://github.com/SirAlabar)

[Markos](https://github.com/MarkosComK) & [Hugo](https://github.com/SirAlabar)

</div>
