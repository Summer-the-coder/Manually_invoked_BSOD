# Manually_invoked_BSOD

**Disclaimer**: I am not responsible for any damage caused to your computer through the use of the code in this repository.

----

The Windows API doesn't directly provide such dangerous things as the ability to raise a BSOD.

However, if you really want to do so, Windows provides you with some undocumented functions from internal libraries that are not intended for use by applications (they are meant to be used by drivers and the kernel).

The script in `crash.cpp`, which utilizes two undocumented functions from `ntdll.lib`, if compiled and ran with administrator permissions, will almost guaranteedly raise a BSOD (and crash your system).

**Note**: If you are compiling with g++ and getting errors like "undefined reference to `NtRaiseHardError'", try to compile with Clang or MSVC (since they are usually aware of Windows's ABI). 
