# Grav

## Grav is a simple Version Control System written in C++

Grav is a simple command-line Version Control System for managing project versions and restoring previous committed files.

## Version

```bash
grav -v
```

You can also use:

```bash
grav -version
```

or:

```bash
grav --v
```

Output:

```text
Grav 0.1.0
```

## Usage

### Initialize a Repository

Initialize a Grav repository in the current directory:

```bash
grav init
```

This creates the `.grav` directory:

```text
.grav/
├── HEAD.txt
├── .cfg
├── .log
├── .src/
└── .versions/
```

---

### Add a File

Add a file to the repository:

```bash
grav add <file>
```

Example:

```bash
grav add main.cpp
```

The file is copied into:

```text
.grav/.src/
```

For example:

```text
.grav/
└── .src/
    └── main.cpp
```

---

### Commit a Version

Create a new version from the files currently stored in `.src`:

```bash
grav commit <version>
```

Example:

```bash
grav commit v1.0
```

The committed files are stored in:

```text
.grav/
└── .versions/
    └── v1.0/
        └── src/
```

After the commit, `.src` is cleared and recreated for the next changes.

---

### Commit With a Log

You can add a message to a commit:

```bash
grav commit <version> -log "<message>"
```

Example:

```bash
grav commit v1.0 -log "Initial version"
```

The log is stored in:

```text
.grav/.log
```

Example:

```text
v1.0 | Initial version
```

Multiple commits can be stored in the log.

---

### Clone a Repository

`grav clone` restores the files from the **latest committed version** of a Grav repository.

It does not build or compile the project.

```bash
grav clone <repository> <destination>
```

Example:

```bash
grav clone ../my-project ../my-copy
```

The files from the latest version are copied into the destination:

```text
my-copy/
├── main.cpp
├── test.cpp
└── ...
```

The latest version is determined by:

```text
.grav/HEAD.txt
```

---

### Clone to `.gravsrc`

You can use `-c` to restore the latest committed version into a `.gravsrc` directory in the current directory:

```bash
grav clone <repository> -c
```

Example:

```bash
grav clone ../my-project -c
```

This creates:

```text
.gravsrc/
├── main.cpp
├── test.cpp
└── ...
```

The `.gravsrc` directory contains the files from the latest committed version.

---

## Repository Structure

A Grav repository looks like:

```text
project/
├── main.cpp
├── test.cpp
└── .grav/
    ├── HEAD.txt
    ├── .cfg
    ├── .log
    ├── .src/
    └── .versions/
        ├── v1.0/
        │   └── src/
        │       ├── main.cpp
        │       └── test.cpp
        └── v2.0/
            └── src/
                ├── main.cpp
                └── test.cpp
```

### `.grav` Files

| File / Directory | Description                                   |
| ---------------- | --------------------------------------------- |
| `HEAD.txt`       | Stores the latest committed version           |
| `.cfg`           | Stores repository information                 |
| `.log`           | Stores commit messages                        |
| `.src`           | Temporary storage for files before committing |
| `.versions`      | Stores committed versions                     |

---

## Commands

| Command                                  | Description                                 |
| ---------------------------------------- | ------------------------------------------- |
| `grav init`                              | Initialize a Grav repository                |
| `grav -v`                                | Show Grav version                           |
| `grav -version`                          | Show Grav version                           |
| `grav --v`                               | Show Grav version                           |
| `grav add <file>`                        | Add a file                                  |
| `grav commit <version>`                  | Commit a new version                        |
| `grav commit <version> -log "<message>"` | Commit a version with a log                 |
| `grav clone <repo> <destination>`        | Restore the latest version to a destination |
| `grav clone <repo> -c`                   | Restore the latest version into `.gravsrc`  |

---

## Example

```bash
grav init

grav add main.cpp
grav add test.cpp

grav commit v1.0 -log "Initial version"

grav add main.cpp

grav commit v2.0 -log "Updated main.cpp"

grav clone ../my-project ../my-copy
```

## How Grav Works

The basic workflow is:

```text
Source Files
     │
     ▼
grav add
     │
     ▼
.grav/.src
     │
     ▼
grav commit
     │
     ▼
.grav/.versions/<version>/src
     │
     ▼
HEAD.txt
     │
     ▼
grav clone
     │
     ▼
Latest Version Files
```

## Status

Grav is currently under development.

Current version:

```text
0.1.0
```

More features will be added in future versions.

## License

This project is currently under development.

