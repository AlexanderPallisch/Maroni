# Maroni
Maroni Engine

## Questions

### Describe a logging system with your own words:
A way to catch and display messages occuring while code executes.
Optimal, there is also an inbuild (threadsave) way to store these Messages (DB or Files)
for later examination and if (globally) configurable for different classes of Messages.

### What is the difference between git submodules and git subtrees?
 **Submodules** allow you to keep a Git repository as a subdirectory of another Git repository. This lets you clone another repository into your project and keep your commits separate.
 A Change in **Submodule** leads to 2 commits: one  commit in **Submodule** and one in the main-repository. If someone clones the main-repository, an recursive clone with git clone --recursive is neccessary

 **Submodules** have a lesser repository size than Git subtrees since they are only pointers to a specific commit in the child project, whereas **subtrees** hold the complete child project and its history.
 **Submodules** in Git must be accessible from a server, while **subtrees** are not. 
 Component-based development makes use of **submodules**, whereas system-based development makes use of **subtrees**.

### What is a build system in C++? Name 3 build systems:
A system to generate executeables and other non-source files of a program from the programs source files (for different platforms).

make
cmake
maven (java)


### What is a package manager in C++? Name 3 package manager:
A System to manage packages and dependencies and their versions in a complex (many dependent libraries) project.
Conan
vcpkg 
Buckaroo

### What is the difference between git and github?
git - version control system

github - website to host github-repositories and has other additional features

### Name 3 benefits of a version control system:
easier collabroation with others - easier merge changes

possibility to view history of changes - go back to prior version

branches - seperate developement of different features

### Name 3 alternatives to git:
svn, cvs

mercurial

bitbucket

### Name 2 differences between git and other version control systems:
git is distributed - no central server neccesary

git branching and merging more sophisticated than many other vcs

### Name known issues related to game engines (Unreal, Unity) and version control systems:
large file sizes, and these often binary

game engine version dependencies
