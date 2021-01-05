# Researching adding new features to a pre-existing application
This is a small C++ project that is a part of CSR (coding style research).
It is meant to start looking for a good method of adding new features to a pre-existing codebase.

# How it works
The project is built with Unix makefiles. It's a small C++ application that parses a very simple config file similar to .ini/.toml. The project is done in 2 stages.
- Stage 1: adding the very basics of config file parsing from scratch.
- Stage 2: implementing a new feature into the parser that has to change most of the project structure in order to be implemented.
- [Probable] Stage 3: proper error handling, prettifying the code, making the code ready for "release". This stage may be absent depending on whether I believe it's worth the effort or not, because the data I'm interested in (the actual research) is in the transition between Stage 1 and Stage 2.

# Research results
## Stage 1 [FINISHED]

Stage 1 is adding the very basics. The very basic application for parsing .ini-like config files after Stage 1 includes:
- Basic command line argument handling (requires one mandatory parameter, the config file name);
- Parsing the config file into a C++ structure/class;
- Outputting the config file on the screen in a human-readable (JSON-like) format.

The point of Stage 1 is not to make a functional application per se, but to create a playground for Stage 2 research to be conducted on. The fact that it's a config file parser is irrelevant to the research.

## Stage 2

Stage 2 is the main stage for this research. The point of the research is to confirm that adding features to an existing program, refactoring and changing the existing structure in the meantime, is emotionally taxing on my brain. After confirming that, the main goal is to identify the reasons WHY it's emotionally taxing, and afterwards start developing a coding style which lets me avoid emotional labor while developing a new feature. I hope Stage 2 provides enough data to start analyzing the problem and probably even solving it. If I don't have enough data by the end of Stage 2, I'll start another research (02 in this repo). The 01_adding_features folder after Stage 2 should include:
- An added feature of reading and writing individual parameters to and from the config file;
- This is achieved via command line:
  - The new -r flag reads a parameter from the specified config file.
  - The new -w flag writes a parameter to the specified config file.
- There can be multiple -r and -w parameters in the command line arguments at the same time. Application's task is to handle them all.
- Basically, the application should have two modes after Stage 2 is finished: mode 1 is the old one from Stage 1 which just reads the config file, parses it and outputs the config file on the screen. Mode 2 is the one from Stage 2: It reads and writes specified parameters from and to the file.

Again, the point of Stage 2 is not implementing those features in itself. The point is to simulate a situation where I have to add new features to a pre-existing code base, understand the difficulties that come up and start looking for a coding style that would allow me to solve most of those difficulties.

## Conclusions
TBA