## Nucleus ##
### C++ kernel ###

Nucleus is the first C++11 kernel.

The main purpose is to make intensive use of the most advance
state-of-the-art C++ features to get the most elegant, flexible and
scalable kernel design. Porting the kernel on a new target should only
be subject to a very few additions.

The design philosophy of nucleus is:
- rely as much as possible on C++ and its standard library.
- make static everything known at compile-time.
- use virtual classes only when polymorphism is needed at run-time;
  use generic programming otherwise.
We strongly believe that rich software designs highly increase
software expressiveness, flexibility and scalability. The STL is the
best illustration of such a design.

To ensure this, nucleus is being developed in parallel on multiple
architectures and platforms to immediately observe the impacts of our
design choices.

Another interest of using C++ for kernel programming is to get the
most out of its beautiful STL. This is why nucleus is composed of two
sub-projects : libk & libkxx - two generic, portable and
kernel-oriented C and C++ libraries needed by the STL or language’s
features.


#### Build instructions ####

```sh
$ ./configure [OPTIONS] && make
```

See `./configure --help` for every configuration details.

#### Testing ####

  * On IA-32 / IBM-PC

```sh
# Use grub or try it with Qemu
$ qemu -kernel nucleus.elf
```

  * On ARM / OMAP & Realview PBX-A9

```sh
$ objcopy -O binary nucleus.elf nucleus.bin

# Try it with Qemu
$ qemu-system-arm -M realview-pbx-a9 -nographic -kernel nucleus.bin
    
# Or build an u-boot image
$ mkimage -A arm -O u-boot -C none -e 0x80000000 -a 0x80000000 -d nucleus.bin uImage
```

--------------
#### Authors ####
* Patrick Samy
* Julio Guerra
