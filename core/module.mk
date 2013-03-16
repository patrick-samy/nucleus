# Add local sources
$(eval $(call add_sources,core.cc 	\
			  sys/close.c	\
			  sys/errno.c	\
			  sys/times.c	\
			  sys/getpid.c	\
			  sys/isatty.c	\
			  sys/sbrk.c	\
			  sys/wait.c	\
			  sys/read.c	\
			  sys/fstat.c	\
			  sys/stat.c	\
			  sys/unlink.c	\
			  sys/link.c	\
			  sys/lseek.c	\
			  sys/open.c	\
			  sys/environ.c	\
			  sys/symlink.c	\
			  sys/readlink.c\
			  sys/kill.c	\
			  sys/_exit.c	\
			  sys/fork.c	\
			  sys/execve.c	\
			  sys/write.c	\
			  sys/gettod.c))

# Build archive
$(eval $(call make_archive,core.a))
