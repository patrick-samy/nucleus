## Nucleus ##
### C++ kernel ###

#### Build instructions ####

```sh
$ ./configure {ia-32,arm} {ibm-pc,omap,realview-pbx-a9} toolchain_prefix && make
```

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
