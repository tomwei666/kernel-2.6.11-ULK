cmd_scripts/kconfig/lxdialog/yesno.o := gcc -Wp,-MD,scripts/kconfig/lxdialog/.yesno.o.d  -Wall -Wstrict-prototypes -O2 -fomit-frame-pointer   -DCURSES_LOC="<ncurses.h>" -DLOCALE    -c -o scripts/kconfig/lxdialog/yesno.o scripts/kconfig/lxdialog/yesno.c

deps_scripts/kconfig/lxdialog/yesno.o := \
  scripts/kconfig/lxdialog/yesno.c \
  scripts/kconfig/lxdialog/dialog.h \
  /usr/include/sys/types.h \
    $(wildcard include/config/.h) \
    $(wildcard include/config/e/offset64.h) \
    $(wildcard include/config/gefile64.h) \
    $(wildcard include/config/d.h) \
    $(wildcard include/config/en.h) \
    $(wildcard include/config/c.h) \
    $(wildcard include/config/x98.h) \
    $(wildcard include/config/ix199506.h) \
  /usr/include/features.h \
    $(wildcard include/config/c99.h) \
    $(wildcard include/config/ix.h) \
    $(wildcard include/config/ix2.h) \
    $(wildcard include/config/ix199309.h) \
    $(wildcard include/config/en/extended.h) \
    $(wildcard include/config/en2k.h) \
    $(wildcard include/config/gefile.h) \
    $(wildcard include/config/ile.h) \
    $(wildcard include/config/ntrant.h) \
    $(wildcard include/config/tify/level.h) \
    $(wildcard include/config/i.h) \
    $(wildcard include/config/ern/inlines.h) \
  /usr/include/sys/cdefs.h \
    $(wildcard include/config/espaces.h) \
  /usr/include/bits/wordsize.h \
  /usr/include/gnu/stubs.h \
  /usr/include/gnu/stubs-32.h \
  /usr/include/bits/types.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stddef.h \
  /usr/include/bits/typesizes.h \
  /usr/include/time.h \
  /usr/include/endian.h \
  /usr/include/bits/endian.h \
  /usr/include/sys/select.h \
  /usr/include/bits/select.h \
  /usr/include/bits/sigset.h \
  /usr/include/bits/time.h \
  /usr/include/sys/sysmacros.h \
  /usr/include/bits/pthreadtypes.h \
  /usr/include/fcntl.h \
  /usr/include/bits/fcntl.h \
  /usr/include/unistd.h \
  /usr/include/bits/posix_opt.h \
  /usr/include/bits/confname.h \
  /usr/include/getopt.h \
  /usr/include/ctype.h \
  /usr/include/stdlib.h \
  /usr/include/alloca.h \
  /usr/include/string.h \
    $(wildcard include/config/ing/inlines.h) \
  /usr/include/bits/string.h \
    $(wildcard include/config/ing/arch/memset.h) \
    $(wildcard include/config/ing/arch/strchr.h) \
  /usr/include/bits/string2.h \
  /usr/include/ncurses.h \
    $(wildcard include/config/sion.h) \
    $(wildcard include/config/stdbool/h.h) \
    $(wildcard include/config/k.h) \
    $(wildcard include/config/ition.h) \
    $(wildcard include/config/nts.h) \
  /usr/include/ncurses_dll.h \
  /usr/include/stdio.h \
  /usr/include/libio.h \
    $(wildcard include/config/a.h) \
    $(wildcard include/config/ar/t.h) \
    $(wildcard include/config//io/file.h) \
  /usr/include/_G_config.h \
  /usr/include/wchar.h \
  /usr/include/bits/wchar.h \
  /usr/include/gconv.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdarg.h \
  /usr/include/bits/stdio_lim.h \
  /usr/include/bits/sys_errlist.h \
  /usr/include/bits/stdio.h \
  /usr/include/unctrl.h \
  /usr/include/curses.h \
  /usr/lib/gcc/i486-linux-gnu/4.1.2/include/stdbool.h \

scripts/kconfig/lxdialog/yesno.o: $(deps_scripts/kconfig/lxdialog/yesno.o)

$(deps_scripts/kconfig/lxdialog/yesno.o):
