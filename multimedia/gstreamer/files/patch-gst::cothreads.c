--- gst/cothreads.c.orig	Mon Feb  2 06:56:53 2004
+++ gst/cothreads.c	Fri Feb  6 13:05:26 2004
@@ -42,6 +42,10 @@
 #include <ucontext.h>
 #endif
 
+#ifdef HAVE_MAKECONTEXT
+#include <ucontext.h>
+#endif
+
 #ifndef MAP_ANONYMOUS
 #ifdef MAP_ANON
 /* older glibc's have MAP_ANON instead of MAP_ANONYMOUS */
@@ -52,7 +56,7 @@
 #endif
 #endif
 
-#define STACK_SIZE 0x200000
+#define STACK_SIZE 0x100000
 
 #define COTHREAD_MAGIC_NUMBER 0xabcdef
 
