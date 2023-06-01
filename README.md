# CS 106L, Standard C++ Programming, Spring 2023

Before starting CS144, I need an elegant designed course to master the advanced language features of C++. Undoubtedly, CS106L is a good choice. If you have the similar plan, give it a try.
> :star2: This course has been fully uploaded and all assignments have been finished.

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

- [x] Lecture 1 - 15 (I have read 2021 win materials)
- [x] Lecture5: [Practice with Streams](resource/Practice%20with%20Streams.html) - _Basic functions_
- [x] Lecture6: Iterators - _Basic functions_
- [x] Lecture8: [Practice with Classes](resource/Practice%20with%20Classes.html) - _Add `insert`, `erase`, `clear`, `capacity`, `pop_back` and some const version methods and rvalue methods. What's more, `gtest` is used._

### Assignments

- [x] [Assignment Setup](resource/Assignment%20Setup.html)
- [x] [Assignment 1: WikiRacer](resource/Assignment%201%20WikiRacer.html)
- [x] [Assignment 2: STL HashMap](resource/Assignment%202%20STL%20HashMap.html)

## License

MIT License
