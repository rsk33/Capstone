# CPPND: Capstone Snake Game Project (Option 2)

This is a repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The starter code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

## Description

## Class Structure

## Expected Behaviour or Output of the Program

## Rubric Cross-Reference
* **README** (_not specified here_)
* **Compiling and Testing** (_not specified here_)
* **Loops, Functions, I/O**
  * A variety of control structures are used in the project. The project code is clearly organized into functions
  * The project reads data from an external file or writes data to a file as part of the necessary operation of the program
  * The project accepts input from a user as part of the necessary operation of the program
* **Object Oriented Programming**
  * The project code is organized into classes with class attributes to hold the data, and class methods to perform tasks
  * All class data members are explicitly specified as public, protected, or private
  * All class members that are set to argument values are initialized through member initialization lists
  * All class member functions document their effects, either through function names, comments, or formal documentation. Member functions do not change program state in undocumented ways
  * Appropriate data and functions are grouped into classes. Member data that is subject to an invariant is hidden from the user. State is accessed via member functions
  * Inheritance hierarchies are logical. Composition is used instead of inheritance when appropriate. Abstract classes are composed of pure virtual functions. Override functions are specified
  * One function is overloaded with different signatures for the same function name
  * One member function in an inherited class overrides a virtual base class member function
  * One function is declared with a template that allows it to accept a generic parameter
* **Memory Management**
  * At least two variables are defined as references, or two functions use pass-by-reference in the project code
  * At least one class that uses unmanaged dynamically allocated memory, along with any class that otherwise needs to modify state upon the termination of an object, uses a destructor
  * The project follows the Resource Acquisition Is Initialization pattern where appropriate, by allocating objects at compile-time, initializing objects when they are declared, and utilizing scope to ensure their automatic destruction
  * For all classes, if any one of the copy constructor, copy assignment operator, move constructor, move assignment operator, and destructor are defined, then all of these functions are defined
  * For classes with move constructors, the project returns objects of that class by value, and relies on the move constructor, instead of copying the object
  * The project uses at least one smart pointer: `unique_ptr`, `shared_ptr`, or `weak_ptr`. The project does not use raw pointers
* **Concurrency**
  * The project uses multiple threads in the execution
  * A promise and future is used to pass data from a worker thread to a parent thread in the project code
  * A mutex or lock (e.g. `std::lock_guard` or `std::unique_lock`) is used to protect data that is shared across multiple threads in the project code
  * A `std::condition_variable` is used in the project code to synchronize thread execution


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  * Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source.
* gcc/g++ >= 9.2.1
  * Linux: gcc / g++

    ```
    sudo add-apt-repository ppa:ubuntu-toolchain-r/test
    sudo apt update
    sudo apt install gcc-9
    ```
    
    if there earlier versions of compiler are installed, default version has to be defined
    
    first erase the current `update-alternatives` setup for `gcc` and `g++`

    ```
    sudo update-alternatives --remove-all gcc 
    sudo update-alternatives --remove-all g++
    ```

    install alternatives (ex. for setup for versions 8 and 9)

    ```
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-8 10
    sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 20

    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-8 10
    sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-9 20

    sudo update-alternatives --install /usr/bin/cc cc /usr/bin/gcc 30
    sudo update-alternatives --set cc /usr/bin/gcc

    sudo update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++ 30
    sudo update-alternatives --set c++ /usr/bin/g++
    ```

    configure alternatives

    ```
    sudo update-alternatives --config gcc
    sudo update-alternatives --config g++
    ```

    check default version

    ```
    gcc --version
    g++ --version
    ```

  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.