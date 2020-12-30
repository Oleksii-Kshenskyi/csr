# Coding Style Research

## The Goal
The point of this repository is coding style research.
For the longest time, I've been having the problem of it being emotionally difficult for me to refactor existing code (in the cases where I have to change the code structure). This repository is dedicated to finding the coding style that works for me through experimentation.

## Requirements for the coding style
The coding style I'm looking for has to be:
- As modular as possible, meaning I have to be able to swap the code pieces without any or close to any refactoring, even when I'm adding features incompatible with the current impleentation of a project.
- As explicit as possible, meaning even after a year of being away from a project, I have to be able to understand what the code is doing. For that, it has to self-document itself.
- The code structure has to be created in such a way that you almost don't need to modify existing code. (SOLID Open/Closed principle).
... For now that is it, We'll see how the requirements evolve with time and more research data.

## Languages used
For now, the plan is to use C++ the most, as this is the language I have the most experience with. I also understand its feature set the best.

Using other languages (like Rust/Elixir/Erlang/Python) is possible, but the majority of the work is going to be done in C++.

## Repo structure
The structure of this repo is pretty simple: it's an enumerated list of folders. Each folder is a self-contained project that is a finished application, and each of them investigates a particular part of the coding style I'm interested in. Apart from the number, the folder is named after the coding style aspect I'm trying to figure out. For example, `01_adding_features` is focused on adding features to pre-existing code, and how to make adding features less painful, error prone and modular. The code in the program itself does not matter much, it's usually a simple application that does something like parse files, function as a simple command line utility, etc. What matters is the coding style data I get from writing the project. It is usually documented in the README.md for the corresponding folder/project.

## License
This code is just a research. It's licensed under Unlicense, one of the public domain licenses, so you can do whatever you want with it.

## More info in the readme incoming once I start getting actual research data from the project.