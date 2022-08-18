
 ## CS 3610 (Data Structures), Ohio University, EECS

 #### Contact: Nasseef Abukamail (abukamai@ohio.edu)

---

  Welcome to CS 3610. In this class we will be writing programs in C++. In order to prepare for class, you need to install a C++ compiler and other software tools on your own machines. Please keep in mind that all the tools needed for the class are also available on our lab machines (Stocker 107 and 307A). The labs are open all day and can be accessed [remotely](#linux-commands-and-remote-loginfile-transfer). We will also be using [Git/GitHub](#gitgithub) for source/version control. Your projects (homework assignments) will be in our GitHub [3610 classroom](https://github.com/3610-fl-22).

  **Important:** In order to be able to use your own computer to do the assignments and examples in this class you need to install the following:
  - C/C++ compiler like GNU C++  or MinGW 
  - Git tools
  - A text editor such as VSCode
  
  > Installation instructions are outlined below.

  **All examples discussed in class will be posted on this site.**

---

- [CS 3610 (Data Structures), Ohio University, EECS](#cs-3610-data-structures-ohio-university-eecs)
    - [Contact: Nasseef Abukamail (abukamai@ohio.edu)](#contact-nasseef-abukamail-abukamaiohioedu)
  - [Installing **C/C++** compiler](#installing-cc-compiler)
  - [Recommended Editors](#recommended-editors)
  - [VS Code Customization](#vs-code-customization)
    - [Extensions](#extensions)
    - [Configure the compiler to run in a terminal](#configure-the-compiler-to-run-in-a-terminal)
    - [Configure Code Runner to use `-Wall -std=c++11 -g`](#configure-code-runner-to-use--wall--stdc11--g)
    - [Configure the Debugger](#configure-the-debugger)
      - [Mac Setup](#mac-setup)
      - [Windows/Linux Setup](#windowslinux-setup)
    - [Helpfull user snippets](#helpfull-user-snippets)
  - [Git/GitHub](#gitgithub)
    - [Git Installation](#git-installation)
    - [Create a GitHub account](#create-a-github-account)
    - [Generate a Personal Access Token (PAT) to be able to use GitHub remotely](#generate-a-personal-access-token-pat-to-be-able-to-use-github-remotely)
  - [Linux Commands and Remote Login/File Transfer](#linux-commands-and-remote-loginfile-transfer)
  - [SFTP Client](#sftp-client)
  - [Coding Style](#coding-style)

### Installing **C/C++** compiler

---

- `Mac`:
    Start the terminal program (Search for `Terminal`). Install the `Command Line Tools` using the command `xcode-select --install`. This will also install `git`. Alternatively, you can install Xcode and install the `Command Line Tools` after you run it the first time.
- `Linux`: Should already come with GNU g++ preinstalled.

- `Windows`: 
  
  - [Install Windows Subsystem for Linux](docs/Windows10-WSL.md) (Recommended)
  
    This will give you a `bash` terminal closer to what Mac and Linux has. If you go through the instructions listed there you can use the same instructions/commands as Linux/Mac that are shown in the rest of this readme file.

### Recommended Editors

---

You need a good programming editor (**DO NOT USE WINDOWS Notepad**). I recommend either Visual Studio Code. It is free and highly customizable. See below for other editors.

- [Visual Studio Code](https://code.visualstudio.com/) (Recommended)
- [Atom Editor](https://atom.io)
- [Emacs](https://www.gnu.org/software/emacs)
- [Vim](https://www.vim.org)
- [nano](https://www.nano-editor.org/)
- and many others ....

### VS Code Customization

---

#### Extensions

- C/C++ extension from Microsoft (**Required**)
- Code Runner (recommended)
- Trailing Semicolon (recommended)
- Code Spell Checker (recommended)

#### Configure the compiler to run in a terminal

- Open `Preferences` and click on `Settings`
- Find the entry called `Run Code Configuration` (Available if you installed `Code Runner` extension)
- Enable the options:
  - `Run in Terminal`
  - `Save All Files Before Run`
  - `Save File Before Run`

#### Configure Code Runner to use `-Wall -std=c++11 -g`

- Go to the Settings menu
- Search for `Code-Runner: Executor Map` and click on `Edit in Settings.json`
- To be able to compile and run your program using the `Run Code` icon or the shortcut `Ctrl-Alt N`, add the following lines right after the opening brace `{`  in `Settings.json` and save it.
  
  ```json
  "code-runner.executorMap": {
        "c": "cd $dir && gcc -Wall $fileName -o $fileNameWithoutExt && $dir$fileNameWithoutExt",
        "cpp": "cd $dir && g++ -Wall -std=c++11 -g $fileName && ./a.out"
    },
  ```
    > On Windows use `./a.exe` instead of `./a.out`.   `-g` option is needed to use a debugger such as `gdb` or `lldb`.

#### Configure the Debugger

**The debugger is configured for every project separately. You must open the project folder in order to use it.**

The debugger depends on what executable file you set up in the previous step. Make sure you open the folder (not the program) where your program resides. You need to do these steps for every project you want to debug.
##### Mac Setup
- Install the extension `CodeLLDB`
- Click on the debug icon on the left
- Click on `Run and Debug`
- Seclect `C++ (GDB/LLDB)
- Select `lldb - Build and debug active file`
- Edit the file `launch.json` inside the `.vscode` directory and make the following changes:
```json
  "configurations": [
        {
            "name": "launch",
            "type": "lldb",
            "request": "launch",
            "program": "${fileDirname}/a.out",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "lldb",
            "preLaunchTask": "C/C++: clang++ build active file"
        }
```

> Input interaction will be done in the terminal window within VScode.
- Edit the `tasks.json` file inside the `.vscode` directory and change the `args` section to the following:
  ```json
  "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/a.out"
          ],
  ```

##### Windows/Linux Setup
- Click on the debug icon on the left
- Click on `Run and Debug`
- Seclect `C++ (GDB/LLDB)
- Select `g++/g++.exe - Build and debug active file`
  

From this point on, you can click on the green arrow to start debugging. Make sure you set a break point. To set a break point inside your code, click to the left of the line number. A red circle should appear.



#### Helpfull user snippets
VSCode already has built-in snippets such as a *for* loop, *class*, etc. However, you can create your own. Open **User Snippets** under **Preferences**. If you are editing a C++ file then the file **cpp.json** should open automatically. Otherwise, you may have to select it. Here is a sample of snippets that I use [cpp-snippets.json](docs/cpp-snippets.json).

### Git/GitHub

---

We will be using Git/GitHub for version/source control (track changes to code). Here are some excellent tutorials that introduce the concepts and shows the most important commands you need to learn.

https://www.youtube.com/watch?v=MJUJ4wbFm_A

https://www.youtube.com/watch?v=uR6G2v_WsRA


#### Git Installation

https://git-scm.com/download/

> Note: Git might already be installed on your Mac or Linux machines.

#### Create a GitHub account

Make sure you create a student account on GitHub using your school email (.edu). You will get the student pack which includes creating private repositories for free. Here is a direct link:

https://education.github.com/students

#### Generate a Personal Access Token (PAT) to be able to use GitHub remotely
[Personal Access Token](docs/GitHub-token.md)

### Linux Commands and Remote Login/File Transfer

---

Here are some Linux commands and instructions to access our system remotely.

[Linux Commands and Remote Access](docs/linux.md)

### SFTP Client

---

Occasionally you need to transer your files from your machine to our Ubuntu system and vice versa. In order to do this you need to use an SFTP (Secure File Transfer Protocol) client. Here are few SFTP clients:

- [WinSCP (Windows only)](https://winscp.net)
- [Fetch (Mac only)](https://fetchsoftworks.com/)
- [Cyberduck](https://cyberduck.io/)

### Coding Style

---

It is very important to follow a good/standard coding style. Refer to this document when writing code.
[CS 3610 Coding Style](docs/coding-style.md)
