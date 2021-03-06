--- src/rtgpoll.c.orig	2010-04-21 21:24:13.686718318 +0100
+++ src/rtgpoll.c	2010-04-21 21:33:53.755065067 +0100
@@ -13,6 +13,7 @@
 stats_t stats =
 {PTHREAD_MUTEX_INITIALIZER, 0, 0, 0, 0, 0, 0, 0, 0, 0.0};
 char *target_file = NULL;
+char *pidfile = NULL;
 target_t *current = NULL;
 MYSQL mysql;
 int entries = 0;
@@ -41,7 +42,7 @@
     config_defaults(&set);
 
     /* Parse the command-line. */
-    while ((ch = getopt(argc, argv, "c:dhmt:vz")) != EOF)
+    while ((ch = getopt(argc, argv, "c:dhmp:t:vz")) != EOF)
 	switch ((char) ch) {
 	case 'c':
 	    conf_file = optarg;
@@ -55,6 +56,9 @@
 	case 'm':
 	    set.multiple++;
 	    break;
+	case 'p':
+	    pidfile = optarg;
+	    break;
 	case 't':
 	    target_file = optarg;
 	    break;
@@ -66,6 +70,9 @@
 	    break;
 	}
 
+    if (!pidfile)
+        pidfile = DEFAULT_PIDFILE;
+
     if (set.verbose >= LOW)
 	printf("RTG version %s starting.\n", VERSION);
 
@@ -78,7 +85,7 @@
     sigaddset(&signal_set, SIGINT);
     sigaddset(&signal_set, SIGQUIT);
 	if (!set.multiple) 
-    	checkPID(PIDFILE);
+    	checkPID(pidfile);
 
     if (pthread_sigmask(SIG_BLOCK, &signal_set, NULL) != 0)
 	printf("pthread_sigmask error\n");
@@ -244,7 +251,7 @@
                 if (set.verbose >= LOW)
                    printf("Quiting: received signal %d.\n", sig_number);
                 rtg_dbdisconnect(&mysql);
-                unlink(PIDFILE);
+                unlink(pidfile);
                 exit(1);
                 break;
         }
@@ -259,6 +266,7 @@
     printf("\nOptions:\n");
     printf("  -c <file>   Specify configuration file\n");
     printf("  -d          Disable database inserts\n");
+    printf("  -p <file>   Specify pid file (defaults to /tmp/rtgpoll.pid)\n");
     printf("  -t <file>   Specify target file\n");
     printf("  -v          Increase verbosity\n");
 	printf("  -m          Allow multiple instances\n");
