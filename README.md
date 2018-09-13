# QtThreadFight -- A small example program where two threads "fight" to move a circle in Qt/C++

![QtThreadFight](/QtThreadFight.png)

This program should display a window with a circle that gradually moves
from left to right.  Two worker threads "fight" over the x location **locx**, with
one of the workers steadily "winning."  A box is drawn near the scene center to help
see where the circle ends up when the worker threads are done.

The purpose of this app is to demonstrate a simple example of how threading might
work to take advantage of multiple cpu cores, and to demonstrate some of the issues
involved when using threads.  This code is not finished yet, and the behavior is not
yet what I'm trying for, but the code builds and the circle moves across the screen.
Once I get it doing what I'm looking for, I'll update this readme.

This code is a refactor of https://github.com/isc1/QtThread01 by https://www.reddit.com/user/jcelerier
which is intended to correct design problems with that code, much thanks to jcelerier for taking
to time to offer improvements!

**It should be noted that we are not killing the threads properly:** closing the window
by clicking the X button on the window while **shutdowncounter** > 0 (i.e. before the
worker threads finish running and exit) does not send any cleanup signal or anything to
the threads, so they do not end gracefully and you will get:

_QThread: Destroyed while thread is still running_

...in app output.  I need to fix this.  Don't do it this way in production.  This code also uses
extern globals, and doesn't use getters/setters, and commits other such misdemeanors, fyi.

After closing the window before the worker threads finished a few times, Windows apparently
decided that this code is being sketchy with the heap; for awhile I got this message in
Application Output at runtime:

_FTH: (10180): *** Fault tolerant heap shim applied to current process. This is usually due to previous crashes. ***_

...just FYI.  I have no idea what the implications here might be for things like Windows Defender, or
any other such issues.  After I ran the code a number of times without stopping the window
before the worker threads finished, windows apparently decided to stop making this fault
tolerant heap shim thing happen, and I stopped seeing that message.

*This code was written on Qt 5.11.1 on Windows 10.  It may run on OS X and Linux with modifications but we haven't done that.*

*This code is copyright 2018 inhabited.systems and jcelerier, and is shared under the MIT license. (See file MIT-License.txt)  This code is unsupported.*