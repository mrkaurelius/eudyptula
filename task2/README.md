# task-2

linux git reposunu clonela

```sh
$ git clone git://git.kernel.org/pub/scm/linux/kernel/git/stable/linux.git
$ git checkout v6.2.11 # stable
```

anladigim kadariyla kallavi init scriptler icin bir fs'e ihtiyac duyuluyor. bizim icin initramfs
gerekli olmayabilir fakat initramfs olmadan kernel'i calistiramadim.

```sh
mkinitramfs -o ramdisk.img
lsinitramfs ramdisk.img # root filesystem'deki dosyalari listeleme
```

qemu ile derlenen kernel'i calistir.

```sh
qemu-system-x86_64 \
  -kernel linux/arch/x86/boot/bzImage \
  -initrd ramfs/ramdisk.img \
  -append "root=/dev/zero console=ttyS0" \
  -m 512 \
  -serial stdio \
  -display none
```

## Kaynaklar

- [Booting a Custom Linux Kernel in QEMU and Debugging It With GDB](https://nickdesaulniers.github.io/blog/2018/10/24/booting-a-custom-linux-kernel-in-qemu-and-debugging-it-with-gdb/)
- [About initramfs](https://www.linuxfromscratch.org/blfs/view/svn/postlfs/initramfs.html)
- [How initramfs works](https://wiki.debian.org/initramfs)