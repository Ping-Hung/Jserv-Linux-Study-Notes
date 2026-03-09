# Definitions
## Object
- C99 standards, Definition 3.13
> Object: region of data storage in the execution environment. The contents of
> which can represent values
- Objects have _lifetimes_

## Lifetime
- C99 standards, 6.2.4
> An object has a **_storage duration_** which determines its **_lifetime_**;
> there are 3 _storage durations_, **static**, **automatic**, and
> **allocated**. The **_lifetime_** of an object is the portion of program
> execution during which storage is guaranteed to be reserved for it.

## Execution Environment
- C99 standards, Chapter 5.
- Responsible for executing (translated) programs.
- 2 types: _free-standing_ and _hosted_.
- _program startup_ occurs when a designated C function is called by the 
  execution environment.
    - All **static storage** is _initialized_ before _program startup_.
- _program termination_ returns control to _execution environment_.

**Free-Standing Environment**:  
- C program execution may take place **without** any benefit from an OS

**Hosted Environment**:  
- An OS sits between hardware and (userspace) C code. Has conventions to follow
    - See details in C99 Standards 5.1.2.2 onwards.

## Aliasing
- Different names for the same location in memory (different names for the same
  object (usually done with pointers)).
    - Sources: 
        1. Purdue ECE 468 Aliasing slides
        2. [](https://cellperformance.beyond3d.com/articles/2006/06/understanding-strict-aliasing.html)
## Strict Aliasing
- An object in memory can only be accessed through pointers of allowed types.
  Violating this rule can lead to undefined behavior, where the compiler might
  make incorrect assumptions about the behavior or the program, potentially
  leading to unexpected results.
    - Source: [](https://developer.arm.com/documentation/100748/0624/Writing-Optimized-Code/C-and-C---aliasing)

