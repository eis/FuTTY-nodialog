INTRODUCTION
============
This zip contains source code changes to PuTTY to add Windows 7 jumplist support.

The Windows 7 jumplist is a customizable list defined by the application. It is persistant across application restarts: the OS maintains the list when the app is not running. The list is shown when the user right-clicks on the taskbar button of a running app or a pinned non-running application. We use the jumplist to maintain a list of recently started saved sessions, started either by doubleclicking on a saved session, or with the command line "-load" parameter. The user can pin his favorite items in the jumplist, so they are never more than one click away.


SOURCE CODE CHANGES
===================
To implement the changes, replace the files in the source tree with their counterparts in this zip file. The changes are relative to SVN revision 8641. The changes may require the Windows 7 SDK to compile properly. The files are:

* windows/wintaskbar.c and windows/wintaskbar.h. Contains the main code for manipulating the taskbar entries.

* windows/winstore.c and storage.h. Added low-level functions to manipulate jumplist entries in the registry.

* cmdline.c, putty.h and windows/window.c. Modifications to remember which session was specified on the commandline and to save it to the jumplist. Also added COM initialize and cleanup.

* config.c. Contains modifications to add and remove sessions from the jumplist when they are double-clicked or removed in the config screen.

* windows/winstuff.h. Several definitions added.

====================