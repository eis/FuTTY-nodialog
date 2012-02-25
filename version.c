/*
 * PuTTY version numbering
 */

#define STR1(x) #x
#define STR(x) STR1(x)

#if defined SNAPSHOT

#if defined SVN_REV
#define SNAPSHOT_TEXT STR(SNAPSHOT) ":r" STR(SVN_REV)
#else
#define SNAPSHOT_TEXT STR(SNAPSHOT)
#endif

char ver[] = "Development snapshot " SNAPSHOT_TEXT;
char sshver[] = "FuTTY-Snapshot-" SNAPSHOT_TEXT;

#undef SNAPSHOT_TEXT

#elif defined RELEASE

char ver[] = "Release " STR(RELEASE);
char sshver[] = "FuTTY-Release-" STR(RELEASE);

#elif defined SVN_REV

char ver[] = "Custom build r" STR(SVN_REV) ", " __DATE__ " " __TIME__;
char sshver[] = "FuTTY-Custom-r" STR(SVN_REV);

#elif defined PUTTYCYG

char ver[] = "FuTTYcyg " STR(PUTTYCYG);
char sshver[] = "FuTTY-cygterm-" STR(PUTTYCYG);

#else

char ver[] = "FuTTY 0.61-2011-07-13, " __DATE__ " " __TIME__;
char sshver[] = "FuTTY-Local: " __DATE__ " " __TIME__;

#endif

/*
 * SSH local version string MUST be under 40 characters. Here's a
 * compile time assertion to verify this.
 */
enum { vorpal_sword = 1 / (sizeof(sshver) <= 40) };
