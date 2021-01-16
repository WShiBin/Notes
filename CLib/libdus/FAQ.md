## 1. What is D-Bus?

This is probably best answered by reading the D-Bus tutorial or the introduction to the specification. In short, it is a system consisting of 1) a wire protocol for exposing a typical object-oriented language/framework to other applications; and 2) a bus daemon that allows applications to find and monitor one another. Phrased differently, D-Bus is 1) an interprocess communication (IPC) system and 2) some higher-level structure (lifecycle tracking, service activation, security policy) provided by two bus daemons, one systemwide and one per-user-session.

## 2. Is D-Bus stable/finished?

The low-level library "libdbus" and the protocol specification are considered ABI stable. The README file has a discussion of the API/ABI stability guarantees. Higher-level bindings (such as those for Qt, GLib, Python, Java, C#) each have their own release schedules and degree of maturity, not linked to the low-level library and bus daemon release. Check the project page for the binding you're considering to understand that project's policies.

## 3. How is the reference implementation licensed? Can I use it in proprietary applications?

The short answer is yes, you can use it in proprietary applications. You should read the COPYING file, which offers you the choice of two licenses. These are the GPL and the AFL. The GPL requires that your application be licensed under the GPL as well. The AFL is an "X-style" or "BSD-style" license compatible with proprietary licensing, but it does have some requirements; in particular it prohibits you from filing a lawsuit alleging that the D-Bus software infringes your patents while you continue to use D-Bus. If you're going to sue, you have to stop using the software. Read the licenses to determine their meaning, this FAQ entry is not intended to change the meaning or terms of the licenses.

## 4. What is the difference between a bus name, and object path, and an interface?

If you imagine a C++ program that implements a network service, then the bus name is the hostname of the computer running this C++ program, the object path is a C++ object instance pointer, and an interface is a C++ class (a pure virtual or abstract class, to be exact).

In Java terms, the object path is an object reference, and an interface is a Java interface.

People get confused because if they write an application with a single object instance and a single interface, then the bus name, object path, and interface look redundant. For example, you might have a text editor that uses the bus name org.freedesktop.TextEditor, has a global singleton object called /org/freedesktop/TextEditor, and that singleton object could implement the interface org.freedesktop.TextEditor.

However, a text editor application could as easily own multiple bus names (for example, org.kde.KWrite in addition to generic TextEditor), have multiple objects (maybe /org/kde/documents/4352 where the number changes according to the document), and each object could implement multiple interfaces, such as org.freedesktop.DBus.Introspectable, org.freedesktop.BasicTextField, org.kde.RichTextDocument.

## 5. What is a "service"?

A service is a program that can be launched by the bus daemon to provide some functionality to other programs. Services are normally launched according to the bus name they will have.

People often misuse the word "service" for any bus name, but this tends to be ambiguous and confusing so is discouraged. In the D-Bus docs we try to use "service" only when talking about programs the bus knows how to launch, i.e. a service always has a .service file.

## 6. Is D-Bus a "component system"?

It helps to keep these concepts separate in your mind:

Object/component system

GUI control/widget embedding interfaces

Interprocess communication system or wire protocol

D-Bus is not a component system. "Component system" was originally defined by COM, and was essentially a workaround for the limitations of the C++ object system (adding introspection, runtime location of objects, ABI guarantees, and so forth). With the C# language and CLR, Microsoft added these features to the primary object system, leaving COM obsolete. Similarly, Java has much less need for something like COM than C++ did. Even QObject (from Qt) and GObject (from GLib) offer some of the same features found in COM.

Component systems are not about GUI control embedding. Embedding a spreadsheet in a word processor document is a matter of defining some specific interfaces that objects can implement. These interfaces provide methods related to GUI controls. So an object implementing those interfaces can be embedded.

The word "component" just means "object with some fancy features" and in modern languages all objects are effectively "components."

So components are fancy objects, and some objects are GUI controls.

A third, unrelated feature is interprocess communication or IPC. D-Bus is an IPC system. Given an object (or "component" if you must), you can expose the functionality of that object over an IPC system. Examples of IPC systems are DCOM, CORBA, SOAP, XML-RPC, and D-Bus. You can use any of these IPC systems with any object/component system, though some of them are "tuned" for specific object systems. You can think of an IPC system primarily as a wire protocol.

If you combine an IPC system with a set of GUI control interfaces, then you can have an out-of-process or dynamically-loaded GUI control.

Another related concept is the plugin or extension. Generic plugin systems such as the Eclipse system are not so different from component/object systems, though perhaps a "plugin" tends to be a bundle of objects with a user-visible name and can be downloaded/packaged as a unit.

## 7. How fast is the D-Bus reference implementation?

Of course it depends a bit on what you're doing. This mail contains some benchmarking. At the time of that benchmark, D-Bus one-to-one communication was about 2.5x slower than simply pushing the data raw over a socket. After the recent rewrite of the marshaling code, D-Bus is slower than that because a lot of optimization work was lost. But it can probably be sped up again.

D-Bus communication with the intermediate bus daemon should be (and as last profiled, was) about twice as slow as one-to-one mode, because a round trip involves four socket reads/writes rather than two socket reads/writes.

The overhead comes from a couple of places; part of it is simply "abstraction penalty" (there are layers of code to support multiple main loops, multiple transport types, security, etc.). Probably the largest part comes from data validation (because the reference implementation does not trust incoming data). It would be simple to add a "no validation" mode, but probably not a good idea all things considered.

Raw bandwidth isn't the only concern; D-Bus is designed to enable asynchronous communication and avoid round trips. This is frequently a more important performance issue than throughput.

## 8. How large is the D-Bus reference implementation?

A production build (with assertions, unit tests, and verbose logging disabled) is on the order of a 150K shared library.

A much, much smaller implementation would be possible by omitting out of memory handling, hardcoding a main loop (or always using blocking I/O), skipping validation, and otherwise simplifying things.

## 9. How does D-Bus differ from other interprocess communication or networking protocols?

Keep in mind, it is not only an IPC system; it also includes lifecycle tracking, service activation, security policy, and other higher-level structure and assumptions.

The best place to start is to read the D-Bus tutorial, so you have a concrete idea what D-Bus actually is. If you understand other protocols on a wire format level, you may also want to read the D-Bus specification to see what D-Bus looks like on a low level.

As the tutorial and specification both explain, D-Bus is tuned for some specific use cases. Thus, it probably isn't tuned for what you want to do, unless you are doing the things D-Bus was designed for. Don't make the mistake of thinking that any system involving "IPC" is the same thing.

The D-Bus authors would not recommend using D-Bus for applications where it doesn't make sense. The following questions compare D-Bus to some other protocols primarily to help you understand D-Bus and decide whether it's appropriate; D-Bus is neither intended nor claimed to be the right choice for every application.

It should be possible to bridge D-Bus to other IPC systems, just as D-Bus can be bridged to object systems.

Note: the D-Bus mailing list subscribers are very much not interested in debating which IPC system is the One True System. So if you want to discuss that, please use another forum.

## 10. How does D-Bus differ from CORBA?

Start by reading Q: 9.

CORBA is designed to support object-oriented IPC between objects, automatically marshalling parameters as necessary. CORBA is strongly supported by the Open Management Group (OMG), which produces various standards and supporting documents for CORBA and has the backing of many large organizations. There are many CORBA ORBs available, both proprietary ORBs and free / open source software ORBs (the latter include ORBit, MICO, and The ACE Orb (TAO)). Many organizations continue to use CORBA ORBs for various kinds of IPC.

Both GNOME and KDE have used CORBA and then moved away from it. KDE had more success with a system called DCOP, and GNOME layered a system called Bonobo on top of CORBA. Without custom extensions, CORBA does not support many of the things one wants to do in a desktop environment with the GNOME/KDE architecture.

CORBA on the other hand has a number of features of interest for enterprise and web application development, though XML systems such as SOAP are the latest fad.

Like D-Bus, CORBA uses a fast binary protocol (IIOP). Both systems work in terms of objects and methods, and have concepts such as "oneway" calls. Only D-Bus has direct support for "signals" as in GLib/Qt (or Java listeners, or C# delegates).

D-Bus hardcodes and specifies a lot of things that CORBA leaves open-ended, because CORBA is more generic and D-Bus has two specific use-cases in mind. This makes D-Bus a bit simpler.

However, unlike CORBA D-Bus does not specify the API for the language bindings. Instead, "native" bindings adapted specifically to the conventions of a framework such as QObject, GObject, C#, Java, Python, etc. are encouraged. The libdbus reference implementation is designed to be a backend for bindings of this nature, rather than to be used directly. The rationale is that an IPC system API should not "leak" all over a program; it should come into play only just before data goes over the wire. As an aside, OMG is apparently working on a simpler C++ binding for CORBA.

Many CORBA implementations such as ORBit are faster than the libdbus reference implementation. One reason is that D-Bus considers data from the other end of the connection to be untrusted and extensively validates it. But generally speaking other priorities were placed ahead of raw speed in the libdbus implementation. A fast D-Bus implementation along the lines of ORBit should be possible, of course.

On a more trivial note, D-Bus involves substantially fewer acronyms than CORBA.

## 11. How does D-Bus differ from XML-RPC and SOAP?

Start by reading Q: 9.

In SOAP and XML-RPC, RPC calls are transformed into an XML-based format, then sent over the wire (typically using the HTTP protocol), where they are processed and returned. XML-RPC is the simple protocol (its spec is only a page or two), and SOAP is the full-featured protocol.

XML-RPC and SOAP impose XML parsing overhead that is normally irrelevant in the context of the Internet, but significant for constant fine-grained IPC among applications in a desktop session.

D-Bus offers persistent connections and with the bus daemon supports lifecycle tracking of other applications connected to the bus. With XML-RPC and SOAP, typically each method call exists in isolation and has its own HTTP connection.

## 12. How does D-Bus differ from DCE?

Start by reading Q: 9.

Distributed Computing Environment (DCE) is an industry-standard vendor-neutral standard that includes an IPC mechanism. The Open Group has released an implementation as open source software. DCE is quite capable, and includes a vast amount of functionality such as a distributed time service. As the name implies, DCE is intended for use in a large, multi-computer distributed application. D-Bus would not be well-suited for this.

## 13. How does D-Bus differ from DCOM and COM?

Start by reading Q: 9.

Comparing D-Bus to COM is apples and oranges; see Q: 6.

DCOM (distributed COM) is a Windows IPC system designed for use with the COM object system. It's similar in some ways to DCE and CORBA.

## 14. How does D-Bus differ from ZeroC's Internet Communications Engine (Ice)

Start by reading Q: 9.

The Internet Communications Engine (Ice) is a powerful IPC mechanism more on the level of SOAP or CORBA than D-Bus. Ice has a "dual-license" business around it; i.e. you can use it under the GPL, or pay for a proprietary license.

## 15. How does D-Bus differ from Inter-Client Exchange (ICE)?

ICE was developed for the X Session Management protocol (XSMP), as part of the X Window System (X11R6.1). The idea was to allow desktop sessions to contain nongraphical clients in addition to X clients.

ICE is a binary protocol designed for desktop use, and KDE's DCOP builds on ICE. ICE is substantially simpler than D-Bus (in contrast to most of the other IPC systems mentioned here, which are more complex). ICE doesn't really define a mapping to objects and methods (DCOP adds that layer). The reference implementation of ICE (libICE) is often considered to be horrible (and horribly insecure).

DCOP and XSMP are the only two widely-used applications of ICE, and both could in principle be replaced by D-Bus. (Though whether GNOME and KDE will bother is an open question.)

## 16. How does D-Bus differ from DCOP?

Start by reading Q: 9.

D-Bus is intentionally pretty similar to DCOP, and can be thought of as a "DCOP the next generation" suitable for sharing between the various open source desktop projects.

D-Bus is a bit more complex than DCOP, though the Qt binding for D-Bus should not be more complex for programmers. The additional complexity of D-Bus arises from its separation of object references vs. bus names vs. interfaces as distinct concepts, and its support for one-to-one connections in addition to connections over the bus. The libdbus reference implementation has a lot of API to support multiple bindings and main loops, and performs data validation and out-of-memory handling in order to support secure applications such as the systemwide bus.

D-Bus is probably somewhat slower than DCOP due to data validation and more "layers" in the reference implementation. A comparison hasn't been posted to the list though.

At this time, KDE has not committed to using D-Bus, but there have been discussions of KDE bridging D-Bus and DCOP, or even changing DCOP's implementation to use D-Bus internally (so that GNOME and KDE would end up using exactly the same bus). See the KDE mailing list archives for some of these discussions.

## 17. How does D-Bus differ from [yet more IPC mechanisms]?

Start by reading Q: 9.

There are countless uses of network sockets in the world. MBUS, Sun ONC/RPC, Jabber/XMPP, SIP, are some we can think of quickly.

## 18. Which IPC mechanism should I use?

Start by reading Q: 9.

If you're writing an Internet or Intranet application, XML-RPC or SOAP work for many people. These are standard, available for most languages, simple to debug and easy to use.

If you're writing a desktop application for UNIX, then D-Bus is of course our recommendation for talking to other parts of the desktop session.

D-Bus is also designed for communications between system daemons and communications between the desktop and system daemons.

If you're doing something complicated such as clustering, distributed swarms, peer-to-peer, or whatever then the authors of this FAQ don't have expertise in these areas and you should ask someone else or try a search engine. D-Bus is most likely a poor choice but could be appropriate for some things.

Note: the D-Bus mailing list is probably not the place to discuss which system is appropriate for your application, though you are welcome to ask specific questions about D-Bus after reading this FAQ, the tutorial, and searching the list archives. The best way to search the list archives is probably to use an Internet engine such as Google. On Google, include "site:freedesktop.org" in your search.

## 19. How can I submit a bug or patch?

The D-Bus web site has a link to the bug tracker, which is the best place to store patches. You can also post them to the list, especially if you want to discuss the patch or get feedback.