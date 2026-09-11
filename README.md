# Grav

## Grav is a simple Version Control System written in C++

Grav is a simple command-line Version Control System that allows you to initialize repositories, add files, create versions, store commit logs, and clone repositories.

## Usage

### Initialize a Repository

Create a new Grav repository in the current directory:

```bash
grav init
```

This creates the following structure:

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

The added file is stored inside:

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

Create a new version of the files added to `.src`:

```bash
grav commit <version>
```

Example:

```bash
grav commit v1.0
```

The version is stored inside:

```text
.grav/
└── .versions/
    └── v1.0/
        └── src/
```

After committing, `.src` is cleared and recreated for the next changes.

---

### Commit With a Log

You can create a version with a log message:

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

---

### Clone a Repository

Clone a Grav repository into another directory:

```bash
grav clone <repository> <destination>
```

Example:

```bash
grav clone ../my-repository ../my-copy
```

You can also clone the latest committed version into the current directory:

```bash
grav clone ../my-repository -c
```

The `-c` option uses the current working directory as the destination.

---

## Repository Structure

A Grav repository can look like this:

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
```

### `.grav`

The `.grav` directory contains the repository data.

| File / Directory | Purpose                         |
| ---------------- | ------------------------------- |
| `HEAD.txt`       | Stores the current version      |
| `.cfg`           | Stores repository configuration |
| `.log`           | Stores commit logs              |
| `.src`           | Stores files before committing  |
| `.versions`      | Stores committed versions       |

---

## Commands

| Command                                  | Description                      |
| ---------------------------------------- | -------------------------------- |
| `grav init`                              | Initialize a Grav repository     |
| `grav add <file>`                        | Add a file                       |
| `grav commit <version>`                  | Commit a version                 |
| `grav commit <version> -log "<message>"` | Commit a version with a log      |
| `grav clone <repo> <destination>`        | Clone a repository               |
| `grav clone <repo> -c`                   | Clone into the current directory |

---

## Example

```bash
grav init

grav add main.cpp

grav commit v1.0 -log "Initial version"

grav clone ../my-project ../my-copy
```

## Status

Grav is currently under development.

More features will be added in future versions.

## License

This project is currently under development.
