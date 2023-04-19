# CS 106L, Standard C++ Programming, Spring 2023

Before starting CS144, I need an elegant designed course to master the advanced language features of C++. Undoubtedly, CS106L is a good choice. If you have the similar plan, give it a try.

## Configuration

The assignments use C++ standard `c++17`, which requires specific `g++` version to support it. Otherwise, you will encounter strange errors.

> _**Little Story**_: The `setup.sh` script in assignment1 thrown `std::bad_alloc` when I was about to start coding. It really gave me a shock. Obviously, the teachers might want to give me a another chance to exercise GDB. :thinking:

```bash
add-apt-repository ppa:ubuntu-toolchain-r/test
sudo apt update
sudo apt install gcc-11 g++-11
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-11 10
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-11 10
```

## Progress

### Lectures

- [x] Lecture 1 - 5
- [x] Practice with Streams

### Assignments

- [x] Assignment Setup
- [ ] Assignment 1: WikiRacer
- [ ] Assignment 2: STL HashMap

## License

MIT License
