## Atom ##
### C++ kernel ###

#### Build instructions ####

```sh
$ ./configure ARCH={ia-32,arm} PLATFORM={ibm-pc,omap,realview-pbx-a9} CROSS_COMPILE=toolchain_prefix
$ make
```

#### Testing ####

  * On IA-32 / IBM-PC

```sh
# Use grub or try it with Qemu
$ qemu -kernel atom.elf
```

  * On ARM / OMAP & Realview PBX-A9

```sh
$ objcopy -O binary atom.elf atom.bin

# Try it with Qemu
$ qemu-system-arm -M realview-pbx-a9 -nographic -kernel atom.bin
    
# Or build an u-boot image
$ mkimage -A arm -O u-boot -C none -e 0x80000000 -a 0x80000000 -d atom.bin uImage
```

--------------
#### Authors ####
* Patrick Samy
* Julio Guerra
